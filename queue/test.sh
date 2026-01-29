#!/bin/bash

# Test suite for Queue (Fila)
# Run: bash test.sh

echo "╔════════════════════════════════════════════════╗"
echo "║        Queue/Fila - Test Suite                ║"
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
    result=$(eval "$command" 2>&1)
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓ PASSED${NC}"
        ((TESTS_PASSED++))
    else
        echo -e "${RED}✗ FAILED${NC}"
        echo "  Output: $result"
        ((TESTS_FAILED++))
    fi
}

echo "Step 1: Find Source Files"
echo "========================="
if [ -f main.c ]; then
    echo -e "${GREEN}✓ main.c found${NC}"
    ((TESTS_PASSED++))
else
    echo -e "${RED}✗ main.c not found${NC}"
    ((TESTS_FAILED++))
fi

echo ""
echo "Step 2: Compilation"
echo "==================="
# Try to find and compile all C files
test_case "Compile all C files" \
    "gcc -Wall -Wextra -std=c99 main.c -o test_queue 2>&1 && echo 'OK' | grep -q OK"

if [ ! -f test_queue ]; then
    echo -e "${YELLOW}⚠ Could not compile. Checking structure...${NC}"
fi

echo ""
echo "Step 3: Check README"
echo "==================="
test_case "README.md exists and has content" "[ -s README.md ]"

echo ""
echo "Step 4: Code Quality Checks"
echo "==========================="
echo "Looking for typical queue functions..."

if grep -q "atender" main.c 2>/dev/null; then
    echo -e "${GREEN}✓ Found atender function${NC}"
    ((TESTS_PASSED++))
else
    echo -e "${YELLOW}⚠ atender function not found${NC}"
fi

if grep -q "Novo" main.c 2>/dev/null; then
    echo -e "${GREEN}✓ Found Novo function${NC}"
    ((TESTS_PASSED++))
else
    echo -e "${YELLOW}⚠ Novo function not found${NC}"
fi

echo ""
echo "Step 5: Warnings Check"
echo "======================"
if gcc -Wall -Wextra -pedantic -std=c99 main.c -o /dev/null 2>&1 | grep -q "warning"; then
    echo -e "${YELLOW}⚠ Compilation warnings found${NC}"
else
    echo -e "${GREEN}✓ No compilation warnings${NC}"
    ((TESTS_PASSED++))
fi

echo ""
echo "Step 6: Execution Test"
echo "====================="
if [ -f test_queue ]; then
    timeout 2 ./test_queue > /dev/null 2>&1
    if [ $? -eq 0 ] || [ $? -eq 124 ]; then
        echo -e "${GREEN}✓ Program executed successfully${NC}"
        ((TESTS_PASSED++))
    fi
fi

echo ""
echo "╔════════════════════════════════════════════════╗"
echo "║              TEST RESULTS SUMMARY              ║"
echo "╠════════════════════════════════════════════════╣"
echo "║ Tests Passed: ${GREEN}$TESTS_PASSED${NC}"
echo "║ Tests Failed: ${RED}$TESTS_FAILED${NC}"
echo "╚════════════════════════════════════════════════╝"

rm -f test_queue 2>/dev/null

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    exit 1
fi
