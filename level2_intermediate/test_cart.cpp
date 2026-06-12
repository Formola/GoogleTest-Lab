#include <gtest/gtest.h>
#include "shopping_cart.h"

// ESEMPIO PROFESSORE:
TEST(ShoppingCartTest, StartsEmptyAndAddsSuccessfully) {
    ShoppingCart cart;
    EXPECT_EQ(cart.GetItemCount(), 0); // void cart has 0 items
    EXPECT_EQ(cart.GetTotalCents(), 0); // void cart has 0 as total price
    
    cart.AddItem("Mela", 150); // 1.50 euro. INT MEANS CENTS !!!!!!
    EXPECT_EQ(cart.GetItemCount(), 1);
    EXPECT_EQ(cart.GetTotalCents(), 150);
}

// TODO STUDENTE 1: Aggiungi tre prodotti diversi al carrello.
// Usa EXPECT_EQ per verificare il conteggio totale e il prezzo totale.
// Usa messaggi personalizzati << se l'asserzione fallisce.
TEST(ShoppingCartTest, CalculatesTotalForMultipleItems) {
    // IL TUO CODICE QUI

    ShoppingCart cart;
    EXPECT_EQ(cart.GetItemCount(), 0); // void cart has 0 items
    EXPECT_EQ(cart.GetTotalCents(), 0); // void cart has 0 as total price

    // Add 3 different products
    cart.AddItem("Mela", 150);
    cart.AddItem("Pera", 200);
    cart.AddItem("Banana", 300);

    // Test correct prices and items number
    EXPECT_EQ(cart.GetItemCount(), 3) << "Current cart should have exactly 3 items!";
    EXPECT_EQ(cart.GetTotalCents(), 650) << "Current cart should have total price: 650 cents";

    // cart.~ShoppingCart();
    // ask prof is the object is deleted when the test ends.

}

// TODO STUDENTE 2: Testa l'estrazione di un prodotto esistente.
// Ricorda di controllare che il puntatore restituito da ExtractItem NON sia nullptr 
// usando ASSERT_NE prima di verificarne il nome e il prezzo.
// Dopo averlo estratto, verifica che il totale e il conteggio del carrello siano diminuiti.
// Ricordati di fare delete del puntatore estratto!
TEST(ShoppingCartTest, ExtractsExistingItemCorrectly) {
    
    ShoppingCart cart;
    cart.AddItem("Mela", 150);
    cart.AddItem("Pera", 200);
    cart.AddItem("Banana", 300);

    // extract item
    Item* item = cart.ExtractItem("Mela");

    ASSERT_NE(item, nullptr) << "Product Mela doens't exist in the cart.";

    // check price e name
    EXPECT_EQ(item->name, "Mela");
    EXPECT_EQ(item->price_cents, 150);

    // check total new number of items in cart.
    EXPECT_EQ(cart.GetItemCount(), 2) << "After extraction, there are 2 items in the cart";
    
    // check total price in the new cart.
    EXPECT_EQ(cart.GetTotalCents(), 500) << "After extraction, total cost is 500";

}

// TODO STUDENTE 3: Testa l'estrazione di un prodotto NON esistente.
// Verifica che ExtractItem restituisca nullptr.
TEST(ShoppingCartTest, ExtractNonExistingItemReturnsNull) {
    // IL TUO CODICE QUI

    ShoppingCart cart;
    cart.AddItem("Pera", 200);

    // extract a non present item.
    Item* missing_item = cart.ExtractItem("Mela");

    // test that extractItem returns nullptr
    EXPECT_EQ(missing_item, nullptr) << "Extracting a non present item in the cart must return nullptr!";


}