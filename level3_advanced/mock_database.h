#pragma once
#include <map>
#include <string>

struct UserRecord {
    int id;
    std::string role;
};

class MockDatabase {
    std::map<std::string, UserRecord*> db;
    bool connected = false;
public:
    void Connect();
    void Disconnect();
    
    void InsertUser(const std::string& username, int id, const std::string& role);
    
    // Restituisce il record, o nullptr se non trovato o se non connesso
    UserRecord* GetUser(const std::string& username);
    
    void ClearAll();
};