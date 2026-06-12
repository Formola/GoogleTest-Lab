#include <gtest/gtest.h>
#include "config_parser.h"

// ESEMPIO PROFESSORE:
TEST(ConfigParserTest, ParseValidLine) {
    ConfigPair* pair = ParseConfigLine("host=localhost");
    
    // Usiamo ASSERT_NE perche' se pair e' null, dereferenziarlo crasherà il test
    ASSERT_NE(pair, nullptr) << "Il parsing di una linea valida non deve restituire null";
    
    // Usiamo EXPECT_EQ per controllare i valori senza interrompere subito in caso di errore
    EXPECT_EQ(pair->key, "host");
    EXPECT_EQ(pair->value, "localhost");
    
    delete pair; // Clean-up (come mostrato nelle slide)
}

// TODO STUDENTE 1: Testa cosa succede se la linea non contiene il carattere '=' (es. "invalidline")
// Assicurati che restituisca nullptr. Aggiungi un messaggio personalizzato in caso di fallimento.
TEST(ConfigParserTest, ParseLineWithoutEqualsSignReturnsNull) {
    ConfigPair* pair = ParseConfigLine("linewithoutequalsign");

    printf("DEBUG: pair = %p\n", (void*)pair); // Debug: stampa l'indirizzo di pair
    EXPECT_EQ(pair, nullptr) << "Il parsing di una linea senza '=' deve restituire null";
    
}

// TODO STUDENTE 2: Testa il parsing di una linea vuota "".
TEST(ConfigParserTest, ParseEmptyLineReturnsNull) {

    ConfigPair* pair = ParseConfigLine("");
    EXPECT_EQ(pair, nullptr) << "Il parsing di una linea vuota deve restituire null";

    // se ParseConfigLine restituisce già nullptr, non dobbiamo fare delete.
}

// TODO STUDENTE 3: La funzione IsValidKeyName accetta solo lettere e numeri.
// Scrivi un test che verifichi almeno 3 casi validi e 3 casi non validi 
// (es. stringhe con spazi, caratteri speciali). Usa EXPECT_EQ confrontando con true/false.
TEST(KeyValidationTest, ValidatesKeyCharactersCorrectly) {
    // IL TUO CODICE QUI

    // 3 VALID CASES. Pass correct string as key (no spaces, special chars ecc)
    EXPECT_EQ(IsValidKeyName("key"), true);
    EXPECT_EQ(IsValidKeyName("ciaoooomykey"), true);
    EXPECT_EQ(IsValidKeyName("chiave3333333"), true);

    // 3 INVALID CASES. Pass invalid string as key, with spaces or special chars.
    EXPECT_EQ(IsValidKeyName("invalid key"), true);
    EXPECT_EQ(IsValidKeyName("key^$%-trattino"), false);
    EXPECT_EQ(IsValidKeyName("!!!!key"), false);
    EXPECT_EQ(IsValidKeyName(""), false);


}