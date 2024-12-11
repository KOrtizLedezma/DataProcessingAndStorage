//
// Created by kenet on 12/11/24.
//

#ifndef INMEMORYDB_H
#define INMEMORYDB_H

#include <unordered_map>
#include <string>

class InMemoryDB {

private:
    // Main database
    std::unordered_map<std::string, int> database;
    // Transaction changes
    std::unordered_map<std::string, int> transaction;
    // Flag for transaction status
    bool transaction_active = false;

public:
    // Start a new transaction
    void begin_transaction();

    // Add or update a key-value pair
    void put(const std::string& key, int value);

    // Retrieve a value by key
    int get(const std::string& key);

    // Commit the transaction
    void commit();

    // Rollback the transaction
    void rollback();

};



#endif //INMEMORYDB_H
