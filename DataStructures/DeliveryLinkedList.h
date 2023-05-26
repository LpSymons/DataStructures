
#pragma once
#include "DeliveryStatus.h"
#pragma once

class LinkedList {
public:
	//pointer to the first link in the linked list
	DeliveryStatus* first;
	//constructor
	LinkedList();
	//checks the linked list is empty returns bool
	bool IsEmpty();
	//insert, will insert a new link to the linked list, taking a delivery status object,
	void Insert(DeliveryStatus* newLink);
	//Displays content of the linked list
	void Display();
	// Finds a link in the linked list and returns a pointer to it
	DeliveryStatus* Find(int key);
	// Deletes a link in the linked list and returns a pointer to it
	DeliveryStatus* Delete(int key);
	// Deletes the first link from the linked list and returns a pinter to it.
	DeliveryStatus* Delete();
};
