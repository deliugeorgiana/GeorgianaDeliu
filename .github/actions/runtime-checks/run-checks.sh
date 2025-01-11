#!/bin/bash
set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo "Starting runtime checks..."

# Check if the build directory exists
if [ ! -d "../../build" ]; then
    echo -e "${RED}Error: Build directory not found${NC}"
    exit 1
fi

# Function to run memory checks
run_memory_checks() {
    local executable=$1
    echo "Running memory checks on $executable"
    
    # Run with Memory Sanitizer
    if MSAN_OPTIONS=exitcode=0 ./$executable 2>memory_check.log; then
        if grep -i "memory leak" memory_check.log || grep -i "use-after-free" memory_check.log; then
            echo -e "${RED}Memory check failed${NC}"
            cat memory_check.log
            return 1
        else
            echo -e "${GREEN}Memory check passed${NC}"
            return 0
        fi
    else
        echo -e "${RED}Program crashed during memory check${NC}"
        cat memory_check.log
        return 1
    fi
}

# Get all executables from build directory
executables=$(find ../../build -type f -executable -not -name "*.sh" -not -name "*.cmake" -not -name "CMake*")

# Run checks for each executable
failed=0
for executable in $executables; do
    echo "Checking executable: $executable"
    
    # Run the executable with basic tests
    if ! $executable; then
        echo -e "${RED}Basic execution test failed${NC}"
        failed=1
        continue
    fi
    
    # Run memory checks
    if ! run_memory_checks $executable; then
        failed=1
    fi
done

if [ $failed -eq 0 ]; then
    echo -e "${GREEN}All runtime checks passed successfully!${NC}"
    exit 0
else
    echo -e "${RED}Some runtime checks failed!${NC}"
    exit 1
fi
