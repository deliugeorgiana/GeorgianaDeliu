#!/usr/bin/bash

# default values
CPPCHECK_VER=2.14.2   # NOTE: consider updating this value in .github/workflows/cmake.yml:47 when changing this value
CMAKE_BUILD_DIR=build
CMAKE_OPTS=()         # example for CLI: -o "-DCMAKE_INSTALL_PREFIX=~/.local/ -DFILESDIR=~/.local/share/Cppcheck"

while getopts ":b:o:v:" opt; do
  case "${opt}" in
    b) CMAKE_BUILD_DIR="${OPTARG}"
    ;;
    o) IFS=" " read -r -a CMAKE_OPTS <<< "${OPTARG}"
    ;;
    v) CPPCHECK_VER="${OPTARG}"
    ;;
    *) printf "Unknown option %s; available options: \n\
        -b (build dir)\n\
        -o (cmake opts)\n\
        -v (cppcheck version)\n" "${opt}"
      exit 1
    ;;
  esac
done

wget "https://github.com/danmar/cppcheck/archive/${CPPCHECK_VER}.zip"
unzip -q "${CPPCHECK_VER}.zip"
rm "${CPPCHECK_VER}.zip"
mv "cppcheck-${CPPCHECK_VER}" cppcheck

cd cppcheck || { echo "Eroare cd"; exit 1; }
cmake -S . -B "${CMAKE_BUILD_DIR}" -DEXTERNALS_AS_SYSTEM=ON "${CMAKE_OPTS[@]}"
cmake --build "${CMAKE_BUILD_DIR}" -j6

# Add the build directory to the PATH
export PATH="${CMAKE_BUILD_DIR}/bin:$PATH"

# Ensure the paths exist before running cppcheck
if [ ! -d "path/to/code" ]; then
  echo "Error: Directory path/to/code does not exist."
  exit 1
fi

# Run cppcheck
cppcheck --enable=all --inline-suppr --std=c++17 --output-file=cppcheck_report.txt path/to/code