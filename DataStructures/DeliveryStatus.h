#pragma once
#include <iostream>

using namespace std;

class DeliveryStatus {
public:
    // Data for the delivery status
    int data;
    //Status of the delivery
    int status;
    //Pointer to the next delivery status in the linked list
    DeliveryStatus* next;
    //Constructor to inisialise the class
    DeliveryStatus(int data, int status);
    //Return data
    int GetData();
    //Displays the deliveyr status
    void Display();
};

