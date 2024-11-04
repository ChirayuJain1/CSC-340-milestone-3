#include "HashTable.hpp"
#include <iostream>

// Default constructor
HashTable::HashTable() {
    // Initialize the hash table and set numberOfItems to 0
    table = new HashNode*[_HASH_TABLE_SIZE]();
    numberOfItems = 0;
    
}

// Method to return the hash table array
HashNode** HashTable::getTable() {
    return table;
}

// Method to return the size of the hash table
int HashTable::getSize() {
    return _HASH_TABLE_SIZE;
}

// Method to check if the hash table is empty
bool HashTable::isEmpty() {
    return numberOfItems == 0;
}

// Method to get the number of items in the hash table
int HashTable::getNumberOfItems() {
    return numberOfItems;
}

// Method to add a new item to the hash table
bool HashTable::add(int searchKey, HashNode* newItem) {
    // TODO: Implement hash function, handle collisions, and insert the item
    return false; // Return true if insertion is successful, otherwise false
}

// Method to remove an item from the hash table
bool HashTable::remove(int searchKey) {
    // TODO: Implement removal of the item with the given search key
    return false; // Return true if removal is successful, otherwise false
}

// Method to clear all items from the hash table
void HashTable::clear() {
    // TODO: Implement logic to clear the hash table and reset numberOfItems
}

// Method to get an item by its search key
HashNode* HashTable::getItem(int searchKey) {
    // TODO: Implement retrieval of the item with the given search key
    return nullptr; // Return the item if found, otherwise nullptr
}

// Method to check if an item with the given search key exists
bool HashTable::contains(int searchKey) {
    // TODO: Implement check for the existence of an item with the given search key
    return false; // Return true if the item exists, otherwise false
}
