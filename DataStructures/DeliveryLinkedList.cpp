#include "DeliveryLinkedList.h"

//constructor to set the first pointer to 0 or null
LinkedList::LinkedList() {
    first = 0;
}

//checks that the list is empty by checking the first pointer
bool LinkedList::IsEmpty() {
    return (first == 0);
}
//Method to insert a new node at the beginning of the list 
void LinkedList::Insert(DeliveryStatus* newLink) {
    newLink->next = first;
    first = newLink;
}
//Display method traverses the list calls each of the node to print 
void LinkedList::Display() {
    DeliveryStatus* current = first;
    while (current != 0) {
        current->Display();
        current = current->next;
    }
}

// Find method searches for a node with matching data, returns pointer to the matching node
DeliveryStatus* LinkedList::Find(int key) {
    DeliveryStatus* current = first;
    while (current->data != key) {
        if (current->next == 0)
            return 0;
        else
            current = current->next;
    }
    return current;
}

// Delete method traverses the list and deletes the node that matches data,  returns
// pointer to deleted node.
DeliveryStatus* LinkedList::Delete(int key) {
    DeliveryStatus* current = first;
    DeliveryStatus* previous = first;
    while (current->data != key) {
        if (current->next == 0)
            return 0;
        else {
            previous = current;
            current = current->next;
        }
    }
    if (current == first)
        first = first->next;
    else
        previous->next = current->next;
    return current;
}

// Delete method removes first node from linked list and returns pointer.
DeliveryStatus* LinkedList::Delete() {
    DeliveryStatus* temp = first;
    first = first->next;
    return temp;
}