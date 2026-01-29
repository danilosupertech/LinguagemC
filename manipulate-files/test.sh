#!/bin/bash

# Test suite for File Manipulation Project
# Run: bash test.sh

echo "╔════════════════════════════════════════════════╗"
echo "║   File Manipulation - Test Suite              ║"
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

if [ -f ManipularArquivos.c ]; then
    echo -e "${GREEN}✓ Found: ManipularArquivos.c${NC}"
    ((TESTS_PASSED++))
else
    echo -e "${RED}✗ ManipularArquivos.c not found${NC}"
    ((TESTS_FAILED++))
fi

echo ""
echo "Step 2: Check Data Files"
echo "========================"

for file in numeros.txt string.txt; do
    if [ -f "$file" ]; then
        echo -e "${GREEN}✓ Found: $file${NC}"
        ((TESTS_PASSED++))
    else
        echo -e "${YELLOW}⚠ Missing: $file${NC}"
    fi
done

echo ""
echo "Step 3: Compilation"
echo "==================="

test_case "Compile ManipularArquivos.c" \
    "gcc -Wall -Wextra -std=c99 ManipularArquivos.c -o test_files"

if [ ! -f test_files ]; then
    echo -e "${RED}Compilation failed. Skipping execution tests.${NC}"
else
    echo ""
    echo "Step 4: Execution Test"
    echo "====================="
    test_case "Execute program" "timeout 2 ./test_files"
fi

echo ""
echo "Step 5: File I/O Detection"
echo "=========================="

echo "Checking for file operations..."
if grep -q "fopen\|fread\|fwrite\|fclose" ManipularArquivos.c 2>/dev/null; then
    echo -e "${GREEN}✓ Found file I/O operations${NC}"
    ((TESTS_PASSED++))
else
    echo -e "${YELLOW}⚠ No standard file I/O found${NC}"
fi

echo ""
echo "Step 6: Code Quality"
echo "==================="

gcc -Wall -Wextra -pedantic -std=c99 ManipularArquivos.c -o /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ No compilation warnings${NC}"
    ((TESTS_PASSED++))
else
    echo -e "${YELLOW}⚠ Compilation warnings found${NC}"
fi

echo ""
echo "Step 7: README Check"
echo "===================="

test_case "README.md exists and has content" "[ -s README.md ]"

echo ""
echo "╔════════════════════════════════════════════════╗"
echo "║              TEST RESULTS SUMMARY              ║"
echo "╠════════════════════════════════════════════════╣"
echo "║ Tests Passed: ${GREEN}$TESTS_PASSED${NC}"
echo "║ Tests Failed: ${RED}$TESTS_FAILED${NC}"
echo "╚════════════════════════════════════════════════╝"

rm -f test_files 2>/dev/null

if [ $TESTS_FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ✓${NC}"
    exit 0
else
    exit 1
fi
