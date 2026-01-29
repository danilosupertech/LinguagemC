/**
 * @file shopping_cart.c
 * @brief Implementation of shopping cart system using linked lists.
 *
 * This file contains all function implementations for the shopping cart,
 * including product addition, removal, searching, and cart management.
 *
 * @author Danilo Côrtes Gonçalves
 * @date 2026-01-29
 * @version 2.0
 */

#include "shopping_cart.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==================== Helper Functions ==================== */

/**
 * @brief Creates a new product node.
 *
 * Internal helper function to allocate and initialize a product node.
 *
 * @param code Product code.
 * @param name Product name.
 * @param unit_price Price per unit.
 * @param quantity Initial quantity.
 *
 * @return Pointer to new Product, or NULL if allocation fails.
 */
static Product* product_create(int code, const char *name,
                               float unit_price, int quantity) {
    Product *product = (Product *)malloc(sizeof(Product));
    
    if (!product) {
        return NULL;
    }

    product->code = code;
    strncpy(product->name, name, MAX_PRODUCT_NAME_LEN - 1);
    product->name[MAX_PRODUCT_NAME_LEN - 1] = '\0';  // Ensure null termination
    product->unit_price = unit_price;
    product->quantity = quantity;
    product->next = NULL;

    return product;
}

/* ==================== Public Functions ==================== */

ShoppingCart* cart_create(void) {
    ShoppingCart *cart = (ShoppingCart *)malloc(sizeof(ShoppingCart));
    
    if (!cart) {
        return NULL;
    }

    cart->head = NULL;
    cart->item_count = 0;

    return cart;
}

CartStatus cart_add_product(ShoppingCart *cart, int code, const char *name,
                            float unit_price, int quantity) {
    if (!cart || !name) {
        return CART_ERROR_INVALID_INPUT;
    }

    if (quantity <= 0 || unit_price < 0) {
        return CART_ERROR_INVALID_INPUT;
    }

    // Check if product already exists
    Product *existing = cart_find_product(cart, code);
    if (existing) {
        existing->quantity += quantity;
        return CART_SUCCESS;
    }

    // Create new product node
    Product *new_product = product_create(code, name, unit_price, quantity);
    if (!new_product) {
        return CART_ERROR_MALLOC;
    }

    // Add to beginning of list
    new_product->next = cart->head;
    cart->head = new_product;
    cart->item_count++;

    return CART_SUCCESS;
}

CartStatus cart_remove_product(ShoppingCart *cart, int code) {
    if (!cart || !cart->head) {
        return CART_ERROR_EMPTY;
    }

    // If the product to remove is the head
    if (cart->head->code == code) {
        Product *temp = cart->head;
        cart->head = cart->head->next;
        free(temp);
        cart->item_count--;
        return CART_SUCCESS;
    }

    // Search for product in the rest of the list
    Product *current = cart->head;
    while (current->next) {
        if (current->next->code == code) {
            Product *temp = current->next;
            current->next = temp->next;
            free(temp);
            cart->item_count--;
            return CART_SUCCESS;
        }
        current = current->next;
    }

    return CART_ERROR_NOT_FOUND;
}

CartStatus cart_update_quantity(ShoppingCart *cart, int code, int new_quantity) {
    if (!cart) {
        return CART_ERROR_INVALID_INPUT;
    }

    Product *product = cart_find_product(cart, code);
    if (!product) {
        return CART_ERROR_NOT_FOUND;
    }

    if (new_quantity <= 0) {
        return cart_remove_product(cart, code);
    }

    product->quantity = new_quantity;
    return CART_SUCCESS;
}

Product* cart_find_product(const ShoppingCart *cart, int code) {
    if (!cart) {
        return NULL;
    }

    Product *current = cart->head;
    while (current) {
        if (current->code == code) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

float cart_calculate_total(const ShoppingCart *cart) {
    if (!cart) {
        return 0.0f;
    }

    float total = 0.0f;
    Product *current = cart->head;

    while (current) {
        total += current->unit_price * current->quantity;
        current = current->next;
    }

    return total;
}

int cart_count_total_items(const ShoppingCart *cart) {
    if (!cart) {
        return 0;
    }

    int total = 0;
    Product *current = cart->head;

    while (current) {
        total += current->quantity;
        current = current->next;
    }

    return total;
}

void cart_print(const ShoppingCart *cart) {
    if (!cart) {
        printf("Error: Invalid cart pointer.\n");
        return;
    }

    if (!cart->head) {
        printf("\n=== CARRINHO DE COMPRAS ===\n");
        printf("Carrinho vazio.\n");
        printf("Total: R$ 0.00\n\n");
        return;
    }

    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                      CARRINHO DE COMPRAS                              ║\n");
    printf("╠════════╦═════════════════════════╦═════════╦══════════╦═══════════════╣\n");
    printf("║ Código ║ Produto                 ║ Preço   ║ Qtd      ║ Subtotal      ║\n");
    printf("╠════════╬═════════════════════════╬═════════╬══════════╬═══════════════╣\n");

    Product *current = cart->head;
    while (current) {
        float subtotal = current->unit_price * current->quantity;
        printf("║ %6d ║ %-23s ║ %7.2f ║ %8d ║ R$ %11.2f ║\n",
               current->code,
               current->name,
               current->unit_price,
               current->quantity,
               subtotal);
        current = current->next;
    }

    float total = cart_calculate_total(cart);
    int total_items = cart_count_total_items(cart);

    printf("╠════════╩═════════════════════════╩═════════╩══════════╩═══════════════╣\n");
    printf("║ Total de itens: %2d                          Total: R$ %11.2f         ║\n",
           total_items, total);
    printf("╚═════════════════════════════════════════════════════════════════════════╝\n\n");
}

void cart_clear(ShoppingCart *cart) {
    if (!cart) {
        return;
    }

    Product *current = cart->head;
    while (current) {
        Product *temp = current;
        current = current->next;
        free(temp);
    }

    cart->head = NULL;
    cart->item_count = 0;
}

void cart_destroy(ShoppingCart *cart) {
    if (!cart) {
        return;
    }

    cart_clear(cart);
    free(cart);
}
