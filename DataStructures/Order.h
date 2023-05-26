#pragma once
#include <string>
#include <iostream>

using namespace std;

class Order
{
public:
	//Key of the order
	int key;
	//Name of the order
	string name;
	//constructor iniilises varibles
	Order(int key, string name) : key(key), name(name){}
	//destructor
~Order(){}
//operator function compares the keys of two Order objects and returns true if the 
//key of the current object is greater than the key of the right hand side object.
bool operator>(const Order& rhd) {
	return this->key > rhd.key;
}
};

