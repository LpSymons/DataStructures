#pragma once
#include "string"

using namespace std;

class Customer{
	public:
		//Customer number
		int custNumber;
		//First name
		string fName;
		//Last name
		string lName;

		//constructor for class, inailises the custnumber, fname and lname to the customer
		//object
		Customer(int custNumber, string fName, string lName) {
			this->custNumber = custNumber;
			this->fName = fName;
			this->lName = lName;
		}
};

