#include "shopping_cart.h"

ShoppingCart::~ShoppingCart() {
    for (Item* item : items) {
        delete item;
    }
    items.clear();
}

void ShoppingCart::AddItem(const std::string& name, int price_cents) {
    Item* new_item = new Item{name, price_cents};
    items.push_back(new_item);
}

Item* ShoppingCart::ExtractItem(const std::string& name) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->name == name) {
            Item* extracted = *it;
            items.erase(it); // Rimuove dal carrello
            return extracted;
        }
    }
    return nullptr; // Non trovato
}

int ShoppingCart::GetTotalCents() const {
    int total = 0;
    for (const Item* item : items) {
        total += item->price_cents;
    }
    return total;
}

int ShoppingCart::GetItemCount() const {
    return items.size();
}