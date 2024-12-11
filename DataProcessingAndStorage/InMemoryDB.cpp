//
// Created by kenet on 12/11/24.
//

#include <stdexcept>
#include "InMemoryDB.h"

#include <iostream>
#include <ostream>

void InMemoryDB::begin_transaction() {
    if (transaction_active) {
        //throw std::runtime_error("Transaction already in progress");
        std::cout << "Error: Transaction already in progress" << std::endl;
    }
    transaction_active = true;
    transaction.clear();
}

void InMemoryDB::put(const std::string& key, const int value) {
    if (!transaction_active) {
        //throw std::runtime_error("Cannot put without an active transaction");
        std::cout << "Error: Cannot put without an active transaction" << std::endl;
    }
    transaction[key] = value;
}

int InMemoryDB::get(const std::string& key) {
    if (transaction_active && transaction.contains(key)) {
        std::cout << "Null" << std::endl;
        return NULL;
    }
    if (database.contains(key)) {
        std::cout << database[key] << std::endl;
        return database[key];
    }
    else {
        std::cout << "Null" << std::endl;
        return -1;
    }
}

void InMemoryDB::commit() {
    if (!transaction_active) {
        //throw std::runtime_error("No active transaction to commit");
        std::cout << "Error: No active transaction to commit" << std::endl;
    }
    for (const auto& [key, value] : transaction) {
        database[key] = value;
    }
    transaction_active = false;
    transaction.clear();
}

void InMemoryDB::rollback() {
    if (!transaction_active) {
        //throw std::runtime_error("No active transaction to rollback");
        std::cout << "Error: No active transaction to rollback" << std::endl;
    }
    transaction_active = false;
    transaction.clear();
}

