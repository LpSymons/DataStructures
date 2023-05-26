#include "DeliveryStatus.h"

// Constuctor initilaises deliverystatus object and variables
DeliveryStatus::DeliveryStatus(int data, int status) {
    this->data = data;
    this->status = status;
}
//Returns the data
int DeliveryStatus::GetData() {
    return data;
}

//Disaplying the data 
void DeliveryStatus::Display() {
    cout << "Delivery Number : " << data << " " << "Delivery Status " << status << endl;
}

