#include "CustHashTable.h"

//Constructor inialise the hash table, dynamically allocates array of customer pointers
//with a size equal to size array named data will store the information
HashTable::HashTable(int size) {
	this->size = size;
	data = new Customer * [size];
	for (int n = 0; n < size; n++) {
		data[n] = NULL;
	}
}
//Calculate the remainder of the key 
int HashTable::HashFunction(int key) {
	return key % size;
}
//Calculates the hash value for a specific string key 
int HashTable::HashStringFunction(string key) {
	int sum = 0;
	for (int n = 0; n < key.length(); n++) {
		sum += (int)key[n];
	}
	return sum % size;
}
//Search for a customer with customer number, locate the apporaiote slot for the hash entry
//then returns a pinter to that customer
Customer* HashTable::Find(int key) {
	int hash = HashFunction(key);
	while (data[hash] != NULL) {
		if (data[hash]->custNumber == key) {
			return data[hash];
		}
		hash++;
		hash %= size;
	}
	return NULL;
}
//Insert function to add a customer to the hash table, checks the approiate slot to store
//the customer object.
void HashTable::Insert(Customer* item) {
	int key = item->custNumber;
	int hash = HashFunction(key);
	while (data[hash] != NULL) {
		++hash;
		hash %= size;
	}
	data[hash] = item;
}

//Delete function searching for a specific customer number, then returns a pointer to the
//deleted customer, 
Customer* HashTable::Delete(int key) {
	int hash = HashFunction(key);
	while (data[hash] != NULL) {
		if (data[hash]->custNumber == key) {
			Customer* temp = data[hash];
			data[hash] = NULL;
			return temp;
		}
		++hash;
		hash %= size;
	}
	return NULL;
}
//Display fucntion to iterate through the hash table printing each customer stored
void HashTable::Display() {
	for (int n = 0; n < size; n++) {
		if (data[n] != NULL) {
			cout << n << " : " << data[n]->custNumber << " : "
				<< data[n]->fName << " " << data[n]->lName << endl;
		}
	}
}