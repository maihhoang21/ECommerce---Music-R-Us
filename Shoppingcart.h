#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <unordered_map>
#include <iostream>

class ShoppingCart {
private:
    std::unordered_map<std::string, int> cart_items; 
    std::unordered_map<std::string, double> item_prices; 

public:
   
    void addItemToCart(const std::string& item_id, double price, int quantity);
    void removeItemFromCart(const std::string& item_id);
    void viewCartItems() const;
    double calculateTotalPrice() const;
    void emptyCart();
};

#endif
