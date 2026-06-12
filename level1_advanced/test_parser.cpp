#include <gtest/gtest.h>
#include "config_parser.h"

// ESEMPIO PROFESSORE:
// TEST(ConfigParserTest, ParseValidLine) {
//     ConfigPair* pair = ParseConfigLine("host=localhost");
    
//     // Usiamo ASSERT_NE perche' se pair e' null, dereferenziarlo crasherà il test
//     ASSERT_NE(pair, nullptr) << "Il parsing di una linea valida non deve restituire null";
    
//     // Usiamo EXPECT_EQ per controllare i valori senza interrompere subito in caso di errore
//     EXPECT_EQ(pair->key, "host");
//     EXPECT_EQ(pair->value, "localhost");
    
//     delete pair; // Clean-up (come mostrato nelle slide)
// }

// TODO STUDENTE 1: Testa cosa succede se la linea non contiene il carattere '=' (es. "invalidline")
// Assicurati che restituisca nullptr. Aggiungi un messaggio personalizzato in caso di fallimento.
// TEST(ConfigParserTest, ParseLineWithoutEqualsSignReturnsNull) {
//     ConfigPair* pair = ParseConfigLine("linewithoutequalsign");

//     ASSERT_EQ(pair, nullptr) << "Il parsing di una linea senza '=' deve restituire null";
    
// }

// // TODO STUDENTE 2: Testa il parsing di una linea vuota "".
// TEST(ConfigParserTest, ParseEmptyLineReturnsNull) {

//     ConfigPair* pair = ParseConfigLine("");
//     ASSERT_EQ(pair, nullptr) << "Il parsing di una linea vuota deve restituire null";

//     // se ParseConfigLine restituisce già nullptr, non dobbiamo fare delete.
// }

// TODO STUDENTE 3: La funzione IsValidKeyName accetta solo lettere e numeri.
// Scrivi un test che verifichi almeno 3 casi validi e 3 casi non validi 
// (es. stringhe con spazi, caratteri speciali). Usa EXPECT_EQ confrontando con true/false.
// TEST(KeyValidationTest, ValidatesKeyCharactersCorrectly) {
//     // IL TUO CODICE QUI

//     // 3 VALID CASES. Pass correct string as key (no spaces, special chars ecc)
//     EXPECT_EQ(IsValidKeyName("key"), true);
//     EXPECT_EQ(IsValidKeyName("ciaoooomykey"), true);
//     EXPECT_EQ(IsValidKeyName("chiave3333333"), true);

//     // 3 INVALID CASES. Pass invalid string as key, with spaces or special chars.
//     EXPECT_EQ(IsValidKeyName("invalid key"), false);
//     EXPECT_EQ(IsValidKeyName("key^$%-trattino"), false);
//     EXPECT_EQ(IsValidKeyName("!!!!key"), false);
//     EXPECT_EQ(IsValidKeyName(""), false);
//     // EXPECT_NE

// }


// try to create a test fixture to extend this parser exercise
// something like a key generator

#include <gtest/gtest.h>
#include "config_parser.h"

class ConfigParserFixture : public testing::Test {
protected:
    // Dichiariamo il puntatore qui, così è accessibile da tutti i test
    ConfigPair* pair;

    // SetUp: viene eseguito PRIMA di ogni test
    void SetUp() override {
        pair = nullptr; // Assicuriamoci di partire con un puntatore pulito
    }

    // TearDown: viene eseguito DOPO ogni test (anche se il test fallisce!)
    void TearDown() override {
        delete pair;    // Libera la memoria se ParseConfigLine l'ha allocata
        pair = nullptr; // Buona pratica
    }

    // Generate Valid Keys (only letters and numbers)
    std::string GenerateValidKey(int length) {
        std::string key = "key";
        for (int i = 0; i < length; ++i) {
            key += std::to_string(i);
        }
        return key;
    }

    // Generate Invalid Keys (with spaces and special characters)
    std::string GenerateInvalidKey(std::string word) {
        return word + "!! 1_invalid!";
    }

    std::string GenerateEmptyKey() {
        return "";
    }


};

// ESEMPIO PROFESSORE:
TEST_F(ConfigParserFixture, ParseValidLine) {
    // Nota: ora usiamo il generatore CORRETTO (GenerateValidKey)
    std::string valid_key = GenerateValidKey(5); // Es. "key01234"
    ASSERT_EQ(IsValidKeyName(valid_key), true) << "Il generatore di chiavi valide deve produrre chiavi valide";
    std::string line = valid_key + "=value";

    pair = ParseConfigLine(line);
    
    ASSERT_NE(pair, nullptr) << "Il parsing di una linea valida non deve restituire null";
    EXPECT_EQ(pair->key, valid_key);
    EXPECT_EQ(pair->value, "value");
    
    // NESSUN DELETE QUI! Ci pensa in automatico il TearDown()
}

// Specular of the previous test, but now we want to generate an invalid key and check that IsValidKeyName returns false on it.s
TEST_F(ConfigParserFixture, ParseInvalidLine) {
    // Nota: ora usiamo il generatore CORRETTO (GenerateValidKey)
    std::string valid_key = GenerateInvalidKey("word"); // Es. "word!! 1_invalid!"
    ASSERT_EQ(IsValidKeyName(valid_key), false) << "Il generatore di chiavi invalide deve produrre chiavi non valide";
    std::string line = valid_key + "=value";

    // check on valid_key generated

    pair = ParseConfigLine(line);
    
    ASSERT_NE(pair, nullptr) << "Il parsing di una linea valida non deve restituire null";
    EXPECT_EQ(pair->key, valid_key);
    EXPECT_EQ(pair->value, "value");
    
    // NESSUN DELETE QUI! Ci pensa in automatico il TearDown()
}

// TODO STUDENTE 1: Testa cosa succede se la linea non contiene il carattere '=' (es. "invalidline")
// Assicurati che restituisca nullptr. Aggiungi un messaggio personalizzato in caso di fallimento.
TEST_F(ConfigParserFixture, ParseLineWithoutEqualsSignReturnsNull) {
    std::string invalid_line = GenerateValidKey(5); // Genera una chiave valida
    invalid_line += "invalidline"; // Non inserisce il segno '=', cosi da ritornare nullptr

    pair = ParseConfigLine(invalid_line);

    ASSERT_EQ(pair, nullptr) << "Il parsing di una linea senza '=' deve restituire null";
}

// // TODO STUDENTE 2: Testa il parsing di una linea vuota "".
TEST_F(ConfigParserFixture, ParseEmptyLineReturnsNull) {
    std::string empty_line = GenerateEmptyKey();
    
    pair = ParseConfigLine(empty_line);

    ASSERT_EQ(pair, nullptr) << "Il parsing di una linea vuota deve restituire null";
}

// TODO STUDENTE 3: La funzione IsValidKeyName accetta solo lettere e numeri.
// Scrivi un test che verifichi almeno 3 casi validi e 3 casi non validi 
// (es. stringhe con spazi, caratteri speciali). Usa EXPECT_EQ confrontando con true/false.
TEST_F(ConfigParserFixture, ValidatesKeyCharactersCorrectly) {
    // Questo test non usa 'pair', ma SetUp e TearDown verranno comunque
    // eseguiti silenziosamente, senza dare alcun fastidio.

    // 3 VALID CASES
    EXPECT_EQ(IsValidKeyName(GenerateValidKey(3)), true);
    EXPECT_EQ(IsValidKeyName(GenerateValidKey(10)), true);
    EXPECT_EQ(IsValidKeyName(GenerateValidKey(0)), true); // "key" is still valid

    // 3 INVALID CASES
    EXPECT_EQ(IsValidKeyName(GenerateInvalidKey("word")), false);
    EXPECT_EQ(IsValidKeyName(GenerateInvalidKey("word")), false);
    EXPECT_EQ(IsValidKeyName(GenerateInvalidKey("word")), false);
    EXPECT_EQ(IsValidKeyName(""), false);
}