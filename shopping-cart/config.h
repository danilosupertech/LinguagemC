/**
 * @file config.h
 * @brief Configuration header for Shopping Cart project.
 *
 * This file contains compile-time configuration options and constants
 * that can be easily modified without changing the core implementation.
 *
 * @author Danilo Côrtes Gonçalves
 * @date 2026-01-29
 * @version 1.0
 */

#ifndef CONFIG_H
#define CONFIG_H

/**
 * @defgroup Configuration Configuration Constants
 * @{
 */

/**
 * @brief Maximum length for product names.
 *
 * Determines the size of the name buffer in Product structure.
 * Increase this if you need to store longer product names.
 *
 * @note The actual usable length is MAX_PRODUCT_NAME_LEN - 1 (for null terminator)
 */
#define MAX_PRODUCT_NAME_LEN 100

/**
 * @brief Enable or disable debug output.
 *
 * Set to 1 to enable debug messages throughout the library.
 * Set to 0 to disable debug output.
 *
 * @note Debug messages are printed to stdout
 */
#define ENABLE_DEBUG 0

/**
 * @brief Enable or disable memory allocation diagnostics.
 *
 * Set to 1 to track and report memory allocations.
 * Useful for debugging memory leaks.
 *
 * @note Requires implementation of memory tracking functions
 */
#define ENABLE_MEMORY_DIAGNOSTICS 0

/**
 * @brief Currency symbol used in output.
 *
 * Change this to modify the currency displayed in formatted output.
 */
#define CURRENCY_SYMBOL "R$"

/**
 * @brief Number of decimal places for currency values.
 *
 * Used in printf format strings for consistent formatting.
 */
#define CURRENCY_DECIMAL_PLACES 2

/**
 * @brief Maximum number of products in a single cart.
 *
 * Set to -1 for unlimited (only limited by available memory).
 * Set to a positive value to enforce a maximum.
 *
 * This is a soft limit - you can still add more products if needed,
 * but the library will provide warnings.
 */
#define MAX_PRODUCTS_PER_CART (-1)

/**
 * @brief Enable or disable input validation.
 *
 * Set to 1 to perform strict validation of all inputs.
 * Set to 0 to disable validation (not recommended).
 */
#define ENABLE_INPUT_VALIDATION 1

/**
 * @brief Enable or disable fancy Unicode borders in output.
 *
 * Set to 1 to use Unicode box-drawing characters.
 * Set to 0 to use ASCII-only characters for compatibility.
 */
#define ENABLE_UNICODE_BORDERS 1

/**
 * @brief Buffer size for user input.
 *
 * Maximum length of strings that can be read from stdin.
 */
#define INPUT_BUFFER_SIZE 256

/**
 * @brief Enable or disable color output.
 *
 * Set to 1 to use ANSI color codes in terminal output.
 * Set to 0 for monochrome output.
 *
 * @note Requires terminal support for ANSI codes
 */
#define ENABLE_COLOR_OUTPUT 0

/**
 * @brief Default currency for new products.
 *
 * Used when creating products without specifying a currency.
 */
#define DEFAULT_CURRENCY "BRL"

/**
 * @brief Application name and version.
 *
 * Used in welcome messages and documentation.
 */
#define APP_NAME "Shopping Cart System"
#define APP_VERSION "2.0"
#define APP_VERSION_DATE "2026-01-29"

/**
 * @brief Enable or disable automatic cart saving.
 *
 * Set to 1 to automatically save cart on each operation.
 * Set to 0 to save only when explicitly requested.
 *
 * @note Requires persistence implementation
 */
#define ENABLE_AUTO_SAVE 0

/**
 * @brief Default save location for cart data.
 *
 * Path where cart data is persisted.
 * Can be overridden at runtime.
 */
#define DEFAULT_SAVE_PATH "./cart.dat"

/** @} */

/* ==================== Debug Macros ==================== */

#if ENABLE_DEBUG
    /**
     * @brief Debug printf macro.
     *
     * Prints debug messages if ENABLE_DEBUG is set to 1.
     */
    #define DEBUG_PRINT(...) \
        do { \
            fprintf(stderr, "[DEBUG] "); \
            fprintf(stderr, __VA_ARGS__); \
            fprintf(stderr, "\n"); \
        } while (0)
#else
    /**
     * @brief No-op debug macro when debugging is disabled.
     */
    #define DEBUG_PRINT(...) \
        do { /* nothing */ } while (0)
#endif

#endif  /* CONFIG_H */
