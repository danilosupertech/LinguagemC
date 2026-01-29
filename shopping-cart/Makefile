# Makefile for Shopping Cart Project
# 
# This Makefile provides convenient commands for building, running, and
# maintaining the Shopping Cart application.
#
# Usage:
#   make              - Build the project
#   make run          - Run the compiled program
#   make clean        - Remove compiled files
#   make rebuild      - Clean and rebuild
#   make help         - Show this help message

# ==================== Compiler Settings ====================

CC := gcc
CFLAGS := -Wall -Wextra -std=c99 -pedantic
DEBUG_FLAGS := -g -O0
RELEASE_FLAGS := -O2 -DNDEBUG

# ==================== File Organization ====================

# Source files
SOURCES := main.c shopping_cart.c
HEADERS := shopping_cart.h

# Output directory
BUILD_DIR := bin
OUTPUT_NAME := shopping_cart

# Compiled files
OBJECTS := $(SOURCES:%.c=$(BUILD_DIR)/%.o)
EXECUTABLE := $(BUILD_DIR)/$(OUTPUT_NAME)

# ==================== Targets ====================

# Default target: build the project
.PHONY: all
all: $(EXECUTABLE)

# Create build directory
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Compile object files
$(BUILD_DIR)/%.o: %.c $(HEADERS) | $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(RELEASE_FLAGS) -c $< -o $@

# Link the executable
$(EXECUTABLE): $(OBJECTS)
	@echo "Linking $@..."
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@echo "✓ Build successful!"
	@echo "  Executable: $(EXECUTABLE)"

# Build with debug symbols
.PHONY: debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean $(EXECUTABLE)
	@echo "✓ Debug build complete!"

# Run the program
.PHONY: run
run: $(EXECUTABLE)
	@echo "Running Shopping Cart Application..."
	@echo "════════════════════════════════════"
	@./$(EXECUTABLE)

# Run with debug mode
.PHONY: run-debug
run-debug: debug
	@gdb ./$(EXECUTABLE)

# Clean compiled files and directories
.PHONY: clean
clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR)
	@echo "✓ Clean complete!"

# Rebuild: clean and build
.PHONY: rebuild
rebuild: clean all

# Show file information
.PHONY: info
info:
	@echo "Project Information:"
	@echo "  Compiler: $(CC)"
	@echo "  Flags: $(CFLAGS)"
	@echo "  Source files: $(SOURCES)"
	@echo "  Header files: $(HEADERS)"
	@echo "  Build directory: $(BUILD_DIR)"
	@echo "  Executable: $(EXECUTABLE)"

# Format code (requires clang-format)
.PHONY: format
format:
	@echo "Formatting code..."
	@clang-format -i $(SOURCES) $(HEADERS)
	@echo "✓ Code formatting complete!"

# Generate documentation (requires Doxygen)
.PHONY: docs
docs:
	@echo "Generating documentation..."
	@doxygen Doxyfile || echo "Note: Doxyfile not found. Skipping documentation generation."

# Check for memory leaks (requires valgrind)
.PHONY: memcheck
memcheck: $(EXECUTABLE)
	@echo "Running memory check with Valgrind..."
	@valgrind --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

# Help target
.PHONY: help
help:
	@echo "Shopping Cart Project - Build System"
	@echo ""
	@echo "Available targets:"
	@echo "  all          - Build the project (default)"
	@echo "  run          - Build and run the program"
	@echo "  debug        - Build with debug symbols"
	@echo "  run-debug    - Run with GDB debugger"
	@echo "  clean        - Remove compiled files"
	@echo "  rebuild      - Clean and rebuild"
	@echo "  info         - Display project information"
	@echo "  format       - Format code with clang-format"
	@echo "  docs         - Generate documentation with Doxygen"
	@echo "  memcheck     - Check for memory leaks with Valgrind"
	@echo "  help         - Display this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make              # Build the project"
	@echo "  make run          # Build and execute"
	@echo "  make clean        # Remove build artifacts"
	@echo "  make rebuild      # Full rebuild"

# Prevent accidental deletion
.PRECIOUS: $(BUILD_DIR)

# Make targets that are not file names
.PHONY: all run debug run-debug clean rebuild info format docs memcheck help
