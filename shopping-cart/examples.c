/**
 * @file examples.c
 * @brief Example programs demonstrating how to use the shopping cart library.
 *
 * This file contains several self-contained examples showing different ways
 * to use the shopping cart API. These can be compiled separately for learning purposes.
 *
 * @author Danilo Côrtes Gonçalves
 * @date 2026-01-29
 * @version 1.0
 */

#include "shopping_cart.h"
#include <stdio.h>

/**
 * @brief Example 1: Basic cart operations
 *
 * Demonstrates creating a cart, adding products, and printing it.
 */
void example_basic_operations(void) {
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║     Example 1: Basic Cart Operations        ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    // Create a new cart
    ShoppingCart *cart = cart_create();
    if (!cart) {
        printf("Error: Could not create cart\n");
        return;
    }

    // Add some products
    printf("\nAdding products...\n");
    cart_add_product(cart, 101, "Apple", 2.50f, 5);
    cart_add_product(cart, 102, "Orange", 3.00f, 3);
    cart_add_product(cart, 103, "Banana", 1.50f, 10);

    // Display the cart
    printf("Cart contents:\n");
    cart_print(cart);

    // Clean up
    cart_destroy(cart);
}

/**
 * @brief Example 2: Searching for products
 *
 * Demonstrates finding specific products in the cart.
 */
void example_search_products(void) {
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║       Example 2: Searching Products         ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    ShoppingCart *cart = cart_create();

    // Add products
    cart_add_product(cart, 201, "Laptop", 999.99f, 1);
    cart_add_product(cart, 202, "Mouse", 29.99f, 2);
    cart_add_product(cart, 203, "Keyboard", 79.99f, 1);

    // Search for a product
    int code_to_find = 202;
    printf("\nSearching for product with code %d...\n", code_to_find);

    Product *found = cart_find_product(cart, code_to_find);
    if (found) {
        printf("✓ Found!\n");
        printf("  Code:     %d\n", found->code);
        printf("  Name:     %s\n", found->name);
        printf("  Price:    R$ %.2f\n", found->unit_price);
        printf("  Quantity: %d\n", found->quantity);
        printf("  Subtotal: R$ %.2f\n", found->unit_price * found->quantity);
    } else {
        printf("✗ Product not found\n");
    }

    // Try searching for non-existent product
    printf("\nSearching for product with code 999...\n");
    if (!cart_find_product(cart, 999)) {
        printf("✗ Not found (as expected)\n");
    }

    cart_destroy(cart);
}

/**
 * @brief Example 3: Updating quantities
 *
 * Demonstrates how to modify product quantities.
 */
void example_update_quantities(void) {
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║     Example 3: Updating Quantities          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    ShoppingCart *cart = cart_create();

    // Add initial products
    printf("\nInitial cart:\n");
    cart_add_product(cart, 301, "Book", 35.00f, 2);
    cart_add_product(cart, 302, "Pen", 5.00f, 5);
    cart_add_product(cart, 303, "Notebook", 12.00f, 3);

    cart_print(cart);

    // Update quantities
    printf("Updating quantities...\n");
    cart_update_quantity(cart, 301, 5);  // Change to 5
    cart_update_quantity(cart, 302, 10); // Change to 10
    cart_update_quantity(cart, 303, 1);  // Change to 1

    printf("\nUpdated cart:\n");
    cart_print(cart);

    cart_destroy(cart);
}

/**
 * @brief Example 4: Removing products
 *
 * Demonstrates removing products from the cart.
 */
void example_remove_products(void) {
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║      Example 4: Removing Products           ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    ShoppingCart *cart = cart_create();

    printf("\nAdding products...\n");
    cart_add_product(cart, 401, "Shirt", 50.00f, 2);
    cart_add_product(cart, 402, "Pants", 80.00f, 1);
    cart_add_product(cart, 403, "Hat", 25.00f, 3);

    printf("\nCart before removal:\n");
    cart_print(cart);

    // Remove a product
    printf("Removing product with code 402...\n");
    CartStatus status = cart_remove_product(cart, 402);
    if (status == CART_SUCCESS) {
        printf("✓ Product removed successfully\n");
    }

    printf("\nCart after removal:\n");
    cart_print(cart);

    // Try removing non-existent product
    printf("Trying to remove product with code 999...\n");
    status = cart_remove_product(cart, 999);
    if (status == CART_ERROR_NOT_FOUND) {
        printf("✗ Product not found (as expected)\n");
    }

    cart_destroy(cart);
}

/**
 * @brief Example 5: Calculating totals
 *
 * Demonstrates calculating total price and item count.
 */
void example_calculate_totals(void) {
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║    Example 5: Calculating Totals            ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    ShoppingCart *cart = cart_create();

    // Add products
    printf("\nBuilding cart...\n");
    cart_add_product(cart, 501, "Monitor", 350.00f, 1);
    cart_add_product(cart, 502, "Headphones", 150.00f, 2);
    cart_add_product(cart, 503, "Cable", 20.00f, 5);

    // Display cart
    cart_print(cart);

    // Calculate and display totals
    float total_price = cart_calculate_total(cart);
    int total_items = cart_count_total_items(cart);

    printf("╔══════════════════════════════════════════════╗\n");
    printf("║             SUMMARY REPORT                  ║\n");
    printf("╠══════════════════════════════════════════════╣\n");
    printf("║ Total distinct items: %2d                    ║\n", (int)cart->item_count);
    printf("║ Total item quantity:  %2d                    ║\n", total_items);
    printf("║ Total price:          R$ %10.2f        ║\n", total_price);
    printf("╚══════════════════════════════════════════════╝\n");

    cart_destroy(cart);
}

/**
 * @brief Example 6: Handling errors
 *
 * Demonstrates proper error handling with the shopping cart.
 */
void example_error_handling(void) {
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║       Example 6: Error Handling             ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    ShoppingCart *cart = cart_create();
    if (!cart) {
        printf("Fatal: Cannot create cart\n");
        return;
    }

    // Test 1: Invalid inputs
    printf("\n[Test 1] Adding product with negative quantity:\n");
    CartStatus status = cart_add_product(cart, 601, "Item", 10.0f, -5);
    if (status == CART_ERROR_INVALID_INPUT) {
        printf("✓ Correctly rejected (negative quantity)\n");
    }

    // Test 2: Invalid price
    printf("\n[Test 2] Adding product with invalid price:\n");
    status = cart_add_product(cart, 601, "Item", -50.0f, 1);
    if (status == CART_ERROR_INVALID_INPUT) {
        printf("✓ Correctly rejected (negative price)\n");
    }

    // Test 3: Valid input
    printf("\n[Test 3] Adding valid product:\n");
    status = cart_add_product(cart, 601, "Item", 10.0f, 1);
    if (status == CART_SUCCESS) {
        printf("✓ Product added successfully\n");
    }

    // Test 4: Searching non-existent product
    printf("\n[Test 4] Searching for non-existent product:\n");
    Product *p = cart_find_product(cart, 999);
    if (p == NULL) {
        printf("✓ Correctly returned NULL for non-existent product\n");
    }

    // Test 5: Removing from cart
    printf("\n[Test 5] Removing product from empty search:\n");
    status = cart_remove_product(cart, 999);
    if (status == CART_ERROR_NOT_FOUND) {
        printf("✓ Correctly reported NOT_FOUND error\n");
    }

    printf("\nFinal cart state:\n");
    cart_print(cart);

    cart_destroy(cart);
}

/**
 * @brief Example 7: Complex scenario - Online store simulation
 *
 * Simulates a realistic online shopping scenario.
 */
void example_online_store_simulation(void) {
    printf("\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║   Example 7: Online Store Simulation        ║\n");
    printf("╚══════════════════════════════════════════════╝\n");

    ShoppingCart *cart = cart_create();

    printf("\n--- Customer starts browsing store ---\n");
    printf("Adding items to cart...\n\n");

    // Customer adds items
    cart_add_product(cart, 1, "Wireless Mouse", 45.00f, 1);
    printf("✓ Added 1x Wireless Mouse (R$ 45.00)\n");

    cart_add_product(cart, 2, "USB Cable", 15.00f, 2);
    printf("✓ Added 2x USB Cable (R$ 15.00 each)\n");

    cart_add_product(cart, 3, "Monitor Stand", 120.00f, 1);
    printf("✓ Added 1x Monitor Stand (R$ 120.00)\n");

    // Customer changes mind about quantity
    printf("\n--- Customer adjusts order ---\n");
    printf("Increasing USB Cable quantity from 2 to 3...\n");
    cart_update_quantity(cart, 2, 3);
    printf("✓ Updated successfully\n");

    // Customer reviews cart
    printf("\n--- Customer reviews cart ---\n");
    cart_print(cart);

    // Calculate final values
    float total = cart_calculate_total(cart);
    int items = cart_count_total_items(cart);

    printf("\n--- Order Summary ---\n");
    printf("Number of distinct products: %zu\n", cart->item_count);
    printf("Total items in order: %d\n", items);
    printf("Order total: R$ %.2f\n", total);
    printf("Estimated shipping: R$ 25.00\n");
    printf("Final total: R$ %.2f\n\n", total + 25.00f);

    cart_destroy(cart);
}

/**
 * @brief Main function to run all examples
 */
int main(void) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║    Shopping Cart Library - Example Programs           ║\n");
    printf("║           All Features Demonstrated                   ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n");

    // Run all examples
    example_basic_operations();
    example_search_products();
    example_update_quantities();
    example_remove_products();
    example_calculate_totals();
    example_error_handling();
    example_online_store_simulation();

    printf("\n");
    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║            All examples completed!                    ║\n");
    printf("║      For more information, see readme.md               ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");

    return 0;
}
