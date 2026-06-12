#include "mock_database.h"

void MockDatabase::Connect() {
    connected = true;
}

void MockDatabase::Disconnect() {
    connected = false;
}

void MockDatabase::InsertUser(const std::string& username, int id, const std::string& role) {
    UserRecord* record = new UserRecord{id, role};
    db[username] = record;
}

UserRecord* MockDatabase::GetUser(const std::string& username) {
    if (!connected) {
        return nullptr; // Rifiuta query se non connesso
    }
    
    auto it = db.find(username);
    if (it != db.end()) {
        return it->second;
    }
    return nullptr; // Utente non trovato
}

void MockDatabase::ClearAll() {
    for (auto const& [key, val] : db) {
        delete val;
    }
    db.clear();
}