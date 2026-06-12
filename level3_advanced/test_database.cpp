#include <gtest/gtest.h>
#include "mock_database.h"

// TODO STUDENTE 0: Crea la Test Fixture "DatabaseTest".
class DatabaseTest : public testing::Test {
protected:
    MockDatabase db;

    void SetUp() override {
    }

    void TearDown() override {
    }
};


// TODO STUDENTE 1: Usando TEST_F, scrivi un test che verifichi l'utente "admin".
TEST_F(DatabaseTest, RetrievesExistingAdmin) {
}

// TODO STUDENTE 2: Usando TEST_F, scrivi un test che verifichi l'utente "guest".
TEST_F(DatabaseTest, RetrievesExistingGuest) {
}

// TODO STUDENTE 3: Usando TEST_F, scrivi un test che prova a recuperare un utente 
// non esistente (es. "hacker") e verifica che il risultato sia nullptr.
TEST_F(DatabaseTest, UnknownUserReturnsNull) {
}

// TODO STUDENTE 4: Usando TEST_F, disconnetti esplicitamente il DB all'interno 
// del test (chiamando Disconnect()) e verifica che chiamare GetUser("admin") 
// restituisca nullptr (il DB non deve rispondere se non e' connesso).
TEST_F(DatabaseTest, GetUserFailsWhenDisconnected) {
}