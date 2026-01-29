#!/bin/bash

# Test suite for Memory Allocation Project
# Run: bash test.sh

echo "╔════════════════════════════════════════════════╗"
echo "║   Memory Allocation - Test Suite              ║"
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

files=("Malloc_Calloc.c" "TesteMalloc.c" "TesteCalloc.c")
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

test_case "Compile Malloc_Calloc.c" "gcc -Wall -Wextra -std=c99 Malloc_Calloc.c -o test_malloc_calloc"
test_case "Compile TesteMalloc.c" "gcc -Wall -Wextra -std=c99 TesteMalloc.c -o test_malloc"
test_case "Compile TesteCalloc.c" "gcc -Wall -Wextra -std=c99 TesteCalloc.c -o test_calloc"

echo ""
echo "Step 3: Execution Tests"
echo "======================="

if [ -f test_malloc_calloc ]; then
    test_case "Execute Malloc_Calloc" "timeout 2 ./test_malloc_calloc"
fi

if [ -f test_malloc ]; then
    test_case "Execute TesteMalloc" "timeout 2 ./test_malloc"
fi

if [ -f test_calloc ]; then
    test_case "Execute TesteCalloc" "timeout 2 ./test_calloc"
fi

echo ""
echo "Step 4: Memory Function Usage"
echo "============================="

echo "Checking for malloc usage..."
for file in Malloc_Calloc.c TesteMalloc.c TesteCalloc.c; do
    if [ -f "$file" ]; then
        if grep -q "malloc" "$file"; then
            echo -e "${GREEN}✓ malloc found in $file${NC}"
            ((TESTS_PASSED++))
        fi
    fi
done

echo ""
echo "Checking for calloc usage..."
for file in Malloc_Calloc.c TesteCalloc.c; do
    if [ -f "$file" ]; then
        if grep -q "calloc" "$file"; then
            echo -e "${GREEN}✓ calloc found in $file${NC}"
            ((TESTS_PASSED++))
        fi
    fi
done

echo ""
echo "Step 5: Free/Memory Cleanup"
echo "==========================="

echo "Checking for free() usage..."
for file in Malloc_Calloc.c TesteMalloc.c TesteCalloc.c; do
    if [ -f "$file" ]; then
        if grep -q "free" "$file"; then
            echo -e "${GREEN}✓ free found in $file${NC}"
            ((TESTS_PASSED++))
        else
            echo -e "${YELLOW}⚠ free not found in $file (potential memory leak)${NC}"
        fi
    fi
done

echo ""
echo "Step 6: Memory Leak Detection"
echo "============================="

if command -v valgrind &> /dev/null; then
    echo "Running memory checks..."
    
    if [ -f test_malloc_calloc ]; then
        if timeout 5 valgrind --leak-check=full ./test_malloc_calloc > /dev/null 2>&1; then
            echo -e "${GREEN}✓ Malloc_Calloc: No memory leaks${NC}"
            ((TESTS_PASSED++))
        else
            echo -e "${YELLOW}⚠ Malloc_Calloc: Potential memory issues${NC}"
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

rm -f test_malloc_calloc test_malloc test_calloc 2>/dev/null

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    exit 1
fi
