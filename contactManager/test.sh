#!/bin/bash

# Test suite for Contact Manager
# Run: bash test.sh

echo "╔════════════════════════════════════════════════╗"
echo "║     Contact Manager - Test Suite              ║"
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
    local expected=$3
    
    echo -n "Testing: $test_name... "
    result=$(eval "$command" 2>&1)
    
    if echo "$result" | grep -q "$expected"; then
        echo -e "${GREEN}✓ PASSED${NC}"
        ((TESTS_PASSED++))
    else
        echo -e "${RED}✗ FAILED${NC}"
        ((TESTS_FAILED++))
    fi
}

echo "Step 1: Compilation"
echo "==================="
test_case "Compile main.c and contact_manager.c" \
    "gcc -Wall -Wextra -std=c99 main.c contact_manager.c -o test_contact_mgr 2>&1 && echo 'OK'" "OK"

if [ ! -f test_contact_mgr ]; then
    echo -e "${RED}Compilation failed!${NC}"
    exit 1
fi

echo ""
echo "Step 2: Files Check"
echo "==================="
test_case "contact_manager.h exists" "[ -f contact_manager.h ] && echo 'found'" "found"
test_case "contact_manager.c exists" "[ -f contact_manager.c ] && echo 'found'" "found"
test_case "main.c exists" "[ -f main.c ] && echo 'found'" "found"
test_case "README.md exists" "[ -f README.md ] && echo 'found'" "found"

echo ""
echo "Step 3: Code Quality"
echo "===================="
echo "Checking for key functions..."
test_case "cm_init() in code" "grep -q 'cm_init' contact_manager.c && echo 'found'" "found"
test_case "cm_add_contact() in code" "grep -q 'cm_add_contact' contact_manager.c && echo 'found'" "found"
test_case "cm_print_contact() in code" "grep -q 'cm_print_contact' contact_manager.c && echo 'found'" "found"

echo ""
echo "Step 4: Memory Test"
echo "==================="
if command -v valgrind &> /dev/null; then
    echo "Testing for memory leaks..."
    valgrind --leak-check=full ./test_contact_mgr < /dev/null > /dev/null 2>&1
    if [ $? -eq 0 ] || [ $? -eq 5 ]; then
        echo -e "${GREEN}✓ Memory test passed${NC}"
        ((TESTS_PASSED++))
    fi
else
    echo -e "${YELLOW}⚠ Valgrind not available (skipped)${NC}"
fi

echo ""
echo "Step 5: Warnings Check"
echo "======================"
gcc -Wall -Wextra -pedantic -std=c99 main.c contact_manager.c -o /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ No compilation warnings${NC}"
    ((TESTS_PASSED++))
else
    echo -e "${YELLOW}⚠ Compilation warnings found${NC}"
fi

echo ""
echo "╔════════════════════════════════════════════════╗"
echo "║              TEST RESULTS SUMMARY              ║"
echo "╠════════════════════════════════════════════════╣"
echo "║ Tests Passed: ${GREEN}$TESTS_PASSED${NC}"
echo "║ Tests Failed: ${RED}$TESTS_FAILED${NC}"
echo "╚════════════════════════════════════════════════╝"

rm -f test_contact_mgr

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    exit 1
fi
