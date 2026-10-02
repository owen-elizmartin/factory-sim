#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
REPORT_DIR="$PROJECT_ROOT/test-reports"

mkdir -p "$REPORT_DIR"

cmake -S "$PROJECT_ROOT" -B "$PROJECT_ROOT/build" &&
cmake --build "$PROJECT_ROOT/build" &&
ctest --test-dir "$PROJECT_ROOT/build" --output-on-failure 2>&1 \
    | tee "$REPORT_DIR/$(date '+%Y-%m-%d_%H-%M-%S').txt"
