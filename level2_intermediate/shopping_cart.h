#pragma once
#include <string>
#include <vector>

struct Item {
    std::string name;
    int price_cents;
};

class ShoppingCart {
    std::vector<Item*> items;
public:
    ~ShoppingCart(); // Si occupa di fare delete di tutti gli items
    void AddItem(const std::string& name, int price_cents);
    
    // Rimuove e restituisce l'item. Ritorna nullptr se non trovato.
    Item* ExtractItem(const std::string& name);
    
    int GetTotalCents() const;
    int GetItemCount() const;
};