/******************************************************************************
  Title          : hash_table.cpp
  Author         : Yu Tong Chen
  Created on     : 4/7/2019
  Description    : The implementation of concrete class derived from abstract class _hash_table.h
  Purpose        : Implementation of hash table.
  Usage          :
  Build with     : no building
  Modifications  :

******************************************************************************/
#include "hash_table.h"


HashTable::HashTable():table_size(INITIAL_SIZE) {
    hash_table = new __ItemType*[table_size];
    for(int i = 0; i < table_size; i++) {
        hash_table[i] = nullptr;
    }
}

HashTable::HashTable(int n):table_size(n) {
    hash_table = new __ItemType*[table_size];
    for(int i = 0; i < table_size; i++) {
        hash_table[i] = nullptr;
    }

}

HashTable::~HashTable() {
    for (int i = 0; i < table_size; i++) {
        if (hash_table[i] != nullptr)
            delete hash_table[i];
    }

    delete[] hash_table;
}

int HashTable::find(__ItemType &item) const {
    unsigned int hash_val = item.code() % table_size;
    int found;
    string key;
    string param_key;
    int value;
    int param_value;

    item.get(param_key,param_value);

    // Grab the initial key value pairs at index hash_val
    if(hash_table[hash_val] != nullptr)
        hash_table[hash_val]->get(key,value);

    // Look for item in hash table by key comparison, advances 1 if not found
    while(hash_table[hash_val] != nullptr && key != param_key) {
        hash_val = item.code() +1;
        hash_table[hash_val]->get(key,value);
    }

    // Not found after searching and current slot is null
    if(hash_table[hash_val] == nullptr)
        found = 0;

    // Found value, param is updated with key value of item at index
    else {
        item.set(key,value);
        found = 1;
    }

    return found;
}

int HashTable::insert(__ItemType item) {
    unsigned int hash_val = item.code() % table_size;
    int inserted = 0;
    string key;
    string param_key;
    int value;
    int param_value;

    item.get(param_key,param_value);

    // Grab the initial key value pairs at index hash_val
    if(hash_table[hash_val] != nullptr)
        hash_table[hash_val]->get(key,value);

    // (Linear Probing) Resolve collisions if there's any
    while(hash_table[hash_val] != nullptr && key != param_key && key != "Dummy") {
            hash_val = item.code() +1;
            hash_table[hash_val]->get(key,value);
    }

    // Collisions resolved, open slot found, insert
    if(hash_table[hash_val] == nullptr || key == "Dummy") {
        hash_table[hash_val] = new __ItemType(item);
        inserted = 1;
        num_item++;

    }

    // If duplicate key found, don't insert
    else if(hash_table[hash_val] != nullptr && key == param_key) {
        inserted = 0;
    }

    return inserted;
}

int HashTable::remove(__ItemType item) {
    unsigned int hash_val = item.code() % table_size;
    int removed = 0;
    string key;
    string param_key;
    int value;
    int param_value;

    dummy.set("Dummy", -1);

    item.get(param_key,param_value);

    // Grab the initial key value pairs at index hash_val
    if(hash_table[hash_val] != nullptr)
        hash_table[hash_val]->get(key,value);

    // Look for item in hash table by key comparison, advances 1 if not found
    while(hash_table[hash_val] != nullptr && key != param_key) {
        hash_val = item.code() +1;
        hash_table[hash_val]->get(key,value);
    }

    // If found item to be removed, mark the index as a dummy/tombstone
    if(key == param_key) {
        hash_table[hash_val] = new __ItemType(dummy);
        num_item--;
        removed = 1;
    }

    return removed;
}

int HashTable::size() const {
    return num_item;
}

int HashTable::listall(ostream &os) const {
    int item_count=0;
    string key;
    int value;

    for(int i = 0; i < table_size; i++) {
        if(hash_table[i] != nullptr) {
            hash_table[i]->get(key,value);
            if(key != "Dummy") {
                os << key << " " << value << endl;
                item_count++;
            }
        }
    }

   return item_count;
}
