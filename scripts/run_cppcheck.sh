#!/usr/bin/bash

cppcheck --enable=all \
    --inline-suppr --max-configs=1000 \
    --project="${BUILD_DIR:-build}/compile_commands.json" \
    -i"${BUILD_DIR:-build}" --suppress="*:${BUILD_DIR:-build}/*" \
    -i"${EXT_DIR:-ext}" --suppress="*:${EXT_DIR:-ext}/*" \
    -i"${GEN_DIR:-generated}" --suppress="*:${GEN_DIR:-generated}/*" \
    --check-level=exhaustive \
    --suppress=missingIncludeSystem \
    --suppress=unmatchedSuppression \
    --suppress=useStlAlgorithm \
    --error-exitcode=1