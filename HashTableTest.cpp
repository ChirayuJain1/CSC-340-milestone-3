/**
*
* HashTableTest.cpp : This is the implementation of GoogleTest for the HashTable.
* 
* 04/11/24 - Created by ChatGPT
* 04/11/24 - Modified by Chirayu Jain and Akash Goyal
*/

#include <gtest/gtest.h>
#include "HashTable.hpp"

// Test fixture class for HashTable
class HashTableTest : public ::testing::Test {
protected:
    HashTable* hashTable;

    // Set up before each test
    void SetUp() override {
        hashTable = new HashTable();
    }

    // Clean up after each test
    void TearDown() override {
        delete hashTable;
    }
};

// Test if a new hash table is empty
TEST_F(HashTableTest, IsEmptyInitially) {
    EXPECT_TRUE(hashTable->isEmpty());
}

// Test adding an item and checking if it exists
TEST_F(HashTableTest, AddAndContains) {
    HashNode* node = new HashNode(1, "John Doe", "123 Main St", "City", "State", "00000");
    hashTable->add(1, node);
    EXPECT_FALSE(hashTable->isEmpty());
    EXPECT_TRUE(hashTable->contains(1));
}

// Test adding multiple items and retrieving them
TEST_F(HashTableTest, AddMultipleItems) {
    hashTable->add(1, new HashNode(1, "John Doe", "123 Main St", "City", "State", "00000"));
    hashTable->add(2, new HashNode(2, "Jane Doe", "456 Oak St", "Town", "State", "11111"));
    hashTable->add(3, new HashNode(3, "Alice Smith", "789 Pine St", "Village", "State", "22222"));

    EXPECT_TRUE(hashTable->contains(1));
    EXPECT_TRUE(hashTable->contains(2));
    EXPECT_TRUE(hashTable->contains(3));
    EXPECT_EQ(hashTable->getNumberOfItems(), 3);
}

// Test retrieving an item by key
TEST_F(HashTableTest, GetItem) {
    HashNode* node = new HashNode(1, "John Doe", "123 Main St", "City", "State", "00000");
    hashTable->add(1, node);
    HashNode* retrievedNode = hashTable->getItem(1);
    EXPECT_EQ(retrievedNode->key, 1);
    EXPECT_EQ(retrievedNode->fullName, "John Doe");
}

// Test removing an item
TEST_F(HashTableTest, RemoveItem) {
    hashTable->add(1, new HashNode(1, "John Doe", "123 Main St", "City", "State", "00000"));
    EXPECT_TRUE(hashTable->contains(1));
    EXPECT_TRUE(hashTable->remove(1));
    EXPECT_FALSE(hashTable->contains(1));
    EXPECT_EQ(hashTable->getNumberOfItems(), 0);
}

// Test clearing the hash table
TEST_F(HashTableTest, ClearTable) {
    hashTable->add(1, new HashNode(1, "John Doe", "123 Main St", "City", "State", "00000"));
    hashTable->add(2, new HashNode(2, "Jane Doe", "456 Oak St", "Town", "State", "11111"));
    hashTable->clear();
    EXPECT_TRUE(hashTable->isEmpty());
    EXPECT_EQ(hashTable->getNumberOfItems(), 0);
}

// Test handling of collisions
TEST_F(HashTableTest, HandleCollisions) {
    int collisionKey1 = 1;
    int collisionKey2 = _HASH_TABLE_SIZE + 1;  // Same index as key 1 with mod operation

    hashTable->add(collisionKey1, new HashNode(collisionKey1, "John Doe", "123 Main St", "City", "State", "00000"));
    hashTable->add(collisionKey2, new HashNode(collisionKey2, "Jane Doe", "456 Oak St", "Town", "State", "11111"));

    EXPECT_TRUE(hashTable->contains(collisionKey1));
    EXPECT_TRUE(hashTable->contains(collisionKey2));
    EXPECT_EQ(hashTable->getItem(collisionKey1)->fullName, "John Doe");
    EXPECT_EQ(hashTable->getItem(collisionKey2)->fullName, "Jane Doe");
}

// The main function for GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}