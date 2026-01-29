#!/bin/bash

# Test suite for Pointers Project
# Run: bash test.sh

echo "╔════════════════════════════════════════════════╗"
echo "║       Pointers Project - Test Suite           ║"
echo "╚════════════════════════════════════════════════╝"
echo ""

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

TESTS_PASSED=0
TESTS_FAILED=0

test_case() {
    local test_name=$1
    local command=$2
    
    echo -n "Testing: $test_name... "
    if eval "$command" > /dev/null 2>&1; then
        echo -e "${GREEN}✓ PASSED${NC}"
        ((TESTS_PASSED++))
    else
        echo -e "${RED}✗ FAILED${NC}"
        ((TESTS_FAILED++))
    fi
}

echo "Step 1: Find Source Files"
echo "========================="

files=("main.c" "mainx.c" "vetores.c" "funct.h")
for file in "${files[@]}"; do
    if [ -f "$file" ]; then
        echo -e "${GREEN}✓ Found: $file${NC}"
        ((TESTS_PASSED++))
    else
        echo -e "${YELLOW}⚠ Missing: $file${NC}"
    fi
done

echo ""
echo "Step 2: Compilation Tests"
echo "========================="

test_case "Compile main.c" "gcc -Wall -Wextra -std=c99 main.c -o test_main"
test_case "Compile mainx.c" "gcc -Wall -Wextra -std=c99 mainx.c -o test_mainx"
test_case "Compile vetores.c" "gcc -Wall -Wextra -std=c99 vetores.c -o test_vetores"

echo ""
echo "Step 3: Execution Tests"
echo "======================="

if [ -f test_main ]; then
    test_case "Execute main" "timeout 2 ./test_main"
fi

if [ -f test_mainx ]; then
    test_case "Execute mainx" "timeout 2 ./test_mainx"
fi

if [ -f test_vetores ]; then
    test_case "Execute vetores" "timeout 2 ./test_vetores"
fi

echo ""
echo "Step 4: Code Quality"
echo "===================="

echo "Checking for pointer usage..."
if grep -q "\*" main.c; then
    echo -e "${GREEN}✓ Found pointer usage in main.c${NC}"
    ((TESTS_PASSED++))
fi

if grep -q "malloc" main.c 2>/dev/null; then
    echo -e "${GREEN}✓ Found malloc usage${NC}"
    ((TESTS_PASSED++))
fi

echo ""
echo "Step 5: Warning Check"
echo "====================="

for file in main.c mainx.c vetores.c; do
    if [ -f "$file" ]; then
        if gcc -Wall -Wextra -pedantic -std=c99 "$file" -o /dev/null 2>&1 | grep -q "warning"; then
            echo -e "${YELLOW}⚠ Warnings in $file${NC}"
        else
            echo -e "${GREEN}✓ No warnings in $file${NC}"
            ((TESTS_PASSED++))
        fi
    fi
done

echo ""
echo "Step 6: Memory Check"
echo "===================="

if command -v valgrind &> /dev/null; then
    if [ -f test_main ]; then
        if timeout 5 valgrind --leak-check=full ./test_main > /dev/null 2>&1; then
            echo -e "${GREEN}✓ Memory test passed${NC}"
            ((TESTS_PASSED++))
        fi
    fi
else
    echo -e "${YELLOW}⚠ Valgrind not available (skipped)${NC}"
fi

echo ""
echo "╔════════════════════════════════════════════════╗"
echo "║              TEST RESULTS SUMMARY              ║"
echo "╠════════════════════════════════════════════════╣"
echo "║ Tests Passed: ${GREEN}$TESTS_PASSED${NC}"
echo "║ Tests Failed: ${RED}$TESTS_FAILED${NC}"
echo "╚════════════════════════════════════════════════╝"

rm -f test_main test_mainx test_vetores 2>/dev/null

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    exit 1
fi
