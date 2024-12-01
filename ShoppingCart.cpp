#include "ShoppingCart.h"

void ShoppingCart::addItemToCart(const std::string& item_id, double price, int quantity) {
    if (cart_items.find(item_id) != cart_items.end()) {
        cart_items[item_id] += quantity;
    } else {
        cart_items[item_id] = quantity;
        item_prices[item_id] = price;
    }
    std::cout << "Added " << quantity << " of item ID " << item_id << " to the cart.\n";
}

void ShoppingCart::removeItemFromCart(const std::string& item_id) {
    if (cart_items.find(item_id) != cart_items.end()) {
        cart_items.erase(item_id);
        item_prices.erase(item_id);
        std::cout << "Item ID " << item_id << " removed from the cart.\n";
    } else {
        std::cout << "Item ID " << item_id << " not found in the cart.\n";
    }
}

void ShoppingCart::viewCartItems() const {
    if (cart_items.empty()) {
        std::cout << "Your cart is empty.\n";
        return;
    }
    std::cout << "Cart Items:\n";
    for (const auto& [item_id, quantity] : cart_items) {
        std::cout << "- Item ID: " << item_id << ", Quantity: " << quantity
                  << ", Unit Price: $" << item_prices.at(item_id) << "\n";
    }
}

double ShoppingCart::calculateTotalPrice() const {
    double total = 0.0;
    for (const auto& [item_id, quantity] : cart_items) {
        total += item_prices.at(item_id) * quantity;
    }
    return total;
}

void ShoppingCart::emptyCart() {
    cart_items.clear();
    item_prices.clear();
    std::cout << "The cart has been emptied.\n";
}
