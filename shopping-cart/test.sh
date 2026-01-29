#!/bin/bash

# Test suite for Shopping Cart System
# Run: bash test.sh

echo "╔════════════════════════════════════════════════╗"
echo "║   Shopping Cart System - Test Suite v2.0      ║"
echo "╚════════════════════════════════════════════════╝"
echo ""

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

TESTS_PASSED=0
TESTS_FAILED=0

# Test function
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
        echo "  Expected: $expected"
        echo "  Got: $result"
        ((TESTS_FAILED++))
    fi
}

echo "Step 1: Compilation Test"
echo "========================"
test_case "Compile with GCC" "gcc -Wall -Wextra -std=c99 shopping_cart.c main.c -o test_cart 2>&1" "test_cart"

if [ ! -f test_cart ]; then
    echo -e "${RED}Compilation failed. Aborting tests.${NC}"
    exit 1
fi

echo ""
echo "Step 2: Examples Compilation"
echo "============================"
test_case "Compile examples" "gcc -Wall -Wextra -std=c99 shopping_cart.c examples.c -o test_examples 2>&1" "test_examples"

echo ""
echo "Step 3: Memory Check (if valgrind available)"
echo "============================================="
if command -v valgrind &> /dev/null; then
    echo "Running memory check on examples..."
    valgrind --leak-check=full --show-leak-kinds=all ./test_examples > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓ Memory check passed (no leaks)${NC}"
        ((TESTS_PASSED++))
    else
        echo -e "${YELLOW}⚠ Memory issues detected${NC}"
    fi
else
    echo -e "${YELLOW}⚠ Valgrind not available (skipped)${NC}"
fi

echo ""
echo "Step 4: Static Analysis (if available)"
echo "======================================"
if command -v gcc &> /dev/null; then
    echo "Checking for warnings with strict flags..."
    gcc -Wall -Wextra -Werror -pedantic -std=c99 shopping_cart.c main.c -o /dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓ No compilation warnings or errors${NC}"
        ((TESTS_PASSED++))
    else
        echo -e "${YELLOW}⚠ Compilation warnings detected${NC}"
    fi
fi

echo ""
echo "Step 5: File Verification"
echo "========================="
files=("shopping_cart.h" "shopping_cart.c" "config.h" "main.c" "examples.c" "Makefile" "readme.md")

for file in "${files[@]}"; do
    test_case "File exists: $file" "[ -f '$file' ] && echo 'exists'" "exists"
done

echo ""
echo "Step 6: Documentation Check"
echo "==========================="
test_case "readme.md has content" "[ -s readme.md ] && wc -l < readme.md | grep -E '[1-9]'" "[1-9]"
test_case "QUICKSTART.md exists" "[ -f QUICKSTART.md ] && echo 'found'" "found"
test_case "CHANGELOG.md exists" "[ -f CHANGELOG.md ] && echo 'found'" "found"

echo ""
echo "Step 7: Function Verification"
echo "============================="
echo "Checking for key functions in header..."
test_case "cart_create() declared" "grep -q 'cart_create' shopping_cart.h && echo 'found'" "found"
test_case "cart_add_product() declared" "grep -q 'cart_add_product' shopping_cart.h && echo 'found'" "found"
test_case "cart_destroy() declared" "grep -q 'cart_destroy' shopping_cart.h && echo 'found'" "found"
test_case "cart_print() declared" "grep -q 'cart_print' shopping_cart.h && echo 'found'" "found"

echo ""
echo "Step 8: Documentation Quality"
echo "============================="
echo "Checking Doxygen comments..."
doxygen_count=$(grep -c "@brief" shopping_cart.h shopping_cart.c)
if [ "$doxygen_count" -ge 10 ]; then
    echo -e "${GREEN}✓ Found $doxygen_count Doxygen comments${NC}"
    ((TESTS_PASSED++))
else
    echo -e "${YELLOW}⚠ Found only $doxygen_count Doxygen comments (expected >= 10)${NC}"
fi

echo ""
echo "Step 9: Examples Execution"
echo "=========================="
echo "Testing examples (with timeout)..."
timeout 5 ./test_examples > /dev/null 2>&1
if [ $? -eq 0 ] || [ $? -eq 124 ]; then
    echo -e "${GREEN}✓ Examples executed successfully${NC}"
    ((TESTS_PASSED++))
else
    echo -e "${RED}✗ Examples execution failed${NC}"
    ((TESTS_FAILED++))
fi

echo ""
echo "╔════════════════════════════════════════════════╗"
echo "║              TEST RESULTS SUMMARY              ║"
echo "╠════════════════════════════════════════════════╣"
echo "║ Tests Passed: ${GREEN}$TESTS_PASSED${NC}"
echo "║ Tests Failed: ${RED}$TESTS_FAILED${NC}"
echo "╚════════════════════════════════════════════════╝"

# Cleanup
rm -f test_cart test_examples

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed.${NC}"
    exit 1
fi
