#include <gtest/gtest.h>
#include "mock_database.h"

// TODO STUDENTE 0: Crea la Test Fixture "DatabaseTest".
class DatabaseTest : public testing::Test {
protected:
    MockDatabase db;

    // it will be executed before the starting point of TEST_F
    void SetUp() override {
        db.Connect();

        db.InsertUser("admin", 1, "manager");
        db.InsertUser("guest", 2, "client");

    }

    // destructor method, used to release resources created in SetUp
    void TearDown() override {

        db.ClearAll();
        db.Disconnect();
    }
};


// TODO STUDENTE 1: Usando TEST_F, scrivi un test che verifichi l'utente "admin".
TEST_F(DatabaseTest, RetrievesExistingAdmin) {

    UserRecord* user = db.GetUser("admin");

    ASSERT_NE(user, nullptr) << "L'utente admin deve esistere nel db";
    
    // check id e role
    EXPECT_EQ(user->id, 1) << "The admin id must be 1.";
    EXPECT_EQ(user->role, "manager") << "the admin role must be manager";

}

// TODO STUDENTE 2: Usando TEST_F, scrivi un test che verifichi l'utente "guest".
TEST_F(DatabaseTest, RetrievesExistingGuest) {

    UserRecord* user = db.GetUser("guest");

    ASSERT_NE(user, nullptr) << "L'utente guest deve esistere nel db";
    
    // check id e role
    EXPECT_EQ(user->id, 2) << "The guest id must be 2.";
    EXPECT_EQ(user->role, "client") << "the guest role must be client";
}

// TODO STUDENTE 3: Usando TEST_F, scrivi un test che prova a recuperare un utente 
// non esistente (es. "hacker") e verifica che il risultato sia nullptr.
TEST_F(DatabaseTest, UnknownUserReturnsNull) {

    UserRecord* user = db.GetUser("hacker");

    // EXPECT_EQ(user, nullptr) << "A user that doesn't exit in db must return nullptr";
    // EXPECT_EQ(user->id, 2) << "The guest id must be 2.";

    ASSERT_EQ(user, nullptr) << "A user that doesn't exit in db must return nullptr";

}

// TODO STUDENTE 4: Usando TEST_F, disconnetti esplicitamente il DB all'interno 
// del test (chiamando Disconnect()) e verifica che chiamare GetUser("admin") 
// restituisca nullptr (il DB non deve rispondere se non e' connesso).
TEST_F(DatabaseTest, GetUserFailsWhenDisconnected) {

    db.Disconnect();

    UserRecord* user = db.GetUser("admin");

    ASSERT_EQ(user, nullptr) << "If db is disconnected, getUser must return nullptr";

}