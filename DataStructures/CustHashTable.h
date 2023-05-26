#pragma once
#include "Customer.h"
#include <iostream>

using namespace std;

class HashTable
{
private:
	//Size of hash table
	int size;
	//data is a pointer to an array of customers storing the customer objects
	Customer** data;
	//Hash function to map customer numbers to an index
	int HashFunction(int custNumber);
public:
	//constuctor to initialize the size of hashtable taking custnumber
	HashTable(int custNumber);
	//Find function takes a customer number and returns a pointer to the customer 
	Customer* Find(int custNumber);
	//takes a pointer to a customer object and inserts into hash table
	void Insert(Customer* item);
	//delete function takes a customer number and removes returning the pointer to 
	//the dleeted customer.
	Customer* Delete(int custNumber);
	//Display the contents of the hash table
	void Display();
	//hash function to map string customers to an index
	int HashStringFunction(string custNumber);
};

