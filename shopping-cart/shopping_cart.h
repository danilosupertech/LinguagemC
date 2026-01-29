/**
 * @file shopping_cart.h
 * @brief Header file for shopping cart system implementation.
 *
 * This file contains the data structures and function prototypes for a
 * dynamic shopping cart system using linked lists.
 *
 * @author Danilo Côrtes Gonçalves
 * @date 2026-01-29
 * @version 2.0
 */

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <stddef.h>  // for size_t

/**
 * @brief Maximum length for product name (including null terminator).
 */
#define MAX_PRODUCT_NAME_LEN 100

/**
 * @brief Return codes for shopping cart operations.
 */
typedef enum {
    CART_SUCCESS = 0,           /**< Operation completed successfully */
    CART_ERROR_MALLOC = -1,     /**< Memory allocation failed */
    CART_ERROR_INVALID_INPUT = -2, /**< Invalid input provided */
    CART_ERROR_NOT_FOUND = -3,  /**< Product not found in cart */
    CART_ERROR_EMPTY = -4       /**< Cart is empty */
} CartStatus;

/**
 * @brief Structure representing a single product in the shopping cart.
 *
 * This structure uses a singly linked list approach where each product
 * node points to the next product in the cart.
 */
typedef struct Product {
    int code;                           /**< Unique product code/ID */
    char name[MAX_PRODUCT_NAME_LEN];    /**< Product name */
    float unit_price;                   /**< Price per unit */
    int quantity;                       /**< Quantity in cart */
    struct Product *next;               /**< Pointer to next product */
} Product;

/**
 * @brief Shopping cart structure.
 *
 * Encapsulates the linked list of products and metadata about the cart.
 */
typedef struct {
    Product *head;    /**< Pointer to the first product */
    size_t item_count; /**< Total number of distinct items */
} ShoppingCart;

/* ==================== Function Prototypes ==================== */

/**
 * @brief Initializes an empty shopping cart.
 *
 * Allocates and initializes a new shopping cart structure.
 *
 * @return Pointer to initialized ShoppingCart, or NULL on allocation failure.
 */
ShoppingCart* cart_create(void);

/**
 * @brief Adds or updates a product in the shopping cart.
 *
 * If the product (by code) already exists, its quantity is incremented.
 * Otherwise, a new product is added to the beginning of the list.
 *
 * @param cart Pointer to the shopping cart.
 * @param code Unique product code.
 * @param name Product name (max MAX_PRODUCT_NAME_LEN - 1 characters).
 * @param unit_price Price per unit (should be non-negative).
 * @param quantity Quantity to add (should be positive).
 *
 * @return CART_SUCCESS on success, or error code on failure.
 */
CartStatus cart_add_product(ShoppingCart *cart, int code, const char *name,
                            float unit_price, int quantity);

/**
 * @brief Removes a product from the cart by its code.
 *
 * @param cart Pointer to the shopping cart.
 * @param code Product code to remove.
 *
 * @return CART_SUCCESS on success, CART_ERROR_NOT_FOUND if not found.
 */
CartStatus cart_remove_product(ShoppingCart *cart, int code);

/**
 * @brief Updates the quantity of a product in the cart.
 *
 * @param cart Pointer to the shopping cart.
 * @param code Product code to update.
 * @param new_quantity New quantity (must be positive, or product will be removed).
 *
 * @return CART_SUCCESS on success, CART_ERROR_NOT_FOUND if product not found.
 */
CartStatus cart_update_quantity(ShoppingCart *cart, int code, int new_quantity);

/**
 * @brief Finds a product in the cart by its code.
 *
 * @param cart Pointer to the shopping cart.
 * @param code Product code to search for.
 *
 * @return Pointer to the Product structure if found, NULL otherwise.
 */
Product* cart_find_product(const ShoppingCart *cart, int code);

/**
 * @brief Calculates the total value of items in the cart.
 *
 * Total is calculated as: sum of (unit_price * quantity) for all products.
 *
 * @param cart Pointer to the shopping cart.
 *
 * @return Total value in currency units, or 0.0 if cart is empty.
 */
float cart_calculate_total(const ShoppingCart *cart);

/**
 * @brief Counts the total number of items (quantity sum) in the cart.
 *
 * @param cart Pointer to the shopping cart.
 *
 * @return Total quantity of all items, or 0 if cart is empty.
 */
int cart_count_total_items(const ShoppingCart *cart);

/**
 * @brief Prints all products in the cart in a formatted table.
 *
 * Displays header and footer with totals. Handles empty carts gracefully.
 *
 * @param cart Pointer to the shopping cart.
 */
void cart_print(const ShoppingCart *cart);

/**
 * @brief Empties the shopping cart, freeing all product nodes.
 *
 * After this call, the cart structure still exists but is empty.
 *
 * @param cart Pointer to the shopping cart.
 */
void cart_clear(ShoppingCart *cart);

/**
 * @brief Destroys the shopping cart and frees all memory.
 *
 * This function clears the cart contents and then frees the cart structure itself.
 * The pointer should not be used after this call.
 *
 * @param cart Pointer to the shopping cart (can be NULL).
 */
void cart_destroy(ShoppingCart *cart);

#endif  /* SHOPPING_CART_H */
