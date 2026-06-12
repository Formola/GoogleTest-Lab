#include "config_parser.h"
#include <cctype>

ConfigPair* ParseConfigLine(const std::string& line) {
    if (line.empty()) {
        return nullptr;
    }

    size_t equals_pos = line.find('=');
    if (equals_pos == std::string::npos) {
        return nullptr; // Nessun segno '=' trovato
    }

    ConfigPair* pair = new ConfigPair();
    pair->key = line.substr(0, equals_pos);
    pair->value = line.substr(equals_pos + 1);
    
    return pair;
}

bool IsValidKeyName(const std::string& key) {
    if (key.empty()) return false;
    for (char c : key) {
        if (!std::isalnum(c)) { // Accetta solo lettere e numeri
            return false;
        }
    }
    return true;
}