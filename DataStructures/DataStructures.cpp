// DataStructures.cpp : This file contains the 'main' function. Program execution begins 
// and ends there.
#include <iostream>
#include <math.h>
#include "CustHashTable.h"
#include "OrderPriorityQueue.h"
#include "Order.h"
#include "ProductBinaryTree.h"
#include "DeliveryLinkedList.h"

using namespace std;

//Method to display menu list for output to user
void menuItems() {
	cout << "--- Retail System ---\n";
	cout << "Please Enter the number of the function you wish to perform\n";
	cout << "Menu Items : \n";
	cout << "1 : Add New Customer Record\n";
	cout << "2 : View Customer List\n";
	cout << "3 : Find Customer by ID\n";
	cout << "4 : Remove Customer\n";
	cout << "5 : Add Order\n";
	cout << "6 : Process Orders\n";
	cout << "7 : View Products\n";
	cout << "8 : Add Product\n";
	cout << "9 : Find Product\n";
	cout << "10 : Remove Product\n";
	cout << "11 : View Deliveries Status\n";
	cout << "12 : Find Delivery\n";
	cout << "13 : Remove Delivery\n";
	cout << "14 : Exit\n";
}

//Method to display status key for the user
void deliveryinfo() {
	cout << "Status 1 : Delivered \n";
	cout << "Status 2 : In Transit \n";
	cout << "Status 3 : Processing \n";
}

int main() {

	//Creating a new instance of the hashtable class with a size of 30. Storing customers
	HashTable* custTable = new HashTable(30);
	//Insert a new customer object with the insert fuction with the appropriate data defined in the 
	// customer class, customer number, first name and last name.
	custTable->Insert(new Customer(1001, "Gandelf", "Grey"));
	custTable->Insert(new Customer(1002, "Frodo", "Baggins"));
	custTable->Insert(new Customer(1003, "Legolas", "Greenleaf"));
	custTable->Insert(new Customer(1004, "Elrond", "Half-elven"));

	//Creating a new instance of the Orderproirtyqueue with a size of 20, storing orders
	OrderPriorityQueue<Order>* targetIDs = new OrderPriorityQueue<Order>(20);
	//Insert a new order object with the insert functiuon with the appropirate data defined 
	//in the order class, with order number and surname. 
	targetIDs->Insert(new Order(200523, "Bilbo"));
	targetIDs->Insert(new Order(210523, "Samwise"));
	targetIDs->Insert(new Order(220523, "Mary"));
	targetIDs->Insert(new Order(190523, "Pippin"));
	//Creating a new instance of the Productbinarytree, storing products
	ProductBinaryTree* productTree = new ProductBinaryTree();
	//Insert a new order object with the insert function with the appropriate data
	//defined in the order class, with product number and price.
	productTree->Insert(1001, 156);
	productTree->Insert(1002, 10);
	productTree->Insert(2005, 189);
	productTree->Insert(3568, 1009);
	productTree->Insert(2589, 1789);
	productTree->Insert(4475, 870);
	productTree->Insert(6985, 191);
	productTree->Insert(3698, 425);

	//Creating a new instance of the linked list class storing delivery status
	LinkedList* DL = new LinkedList();
	//Inserts a new delviery status object with the insert function with the appripirate 
	//data defined in the delivery class, with a delivery number and status. 
	DL->Insert(new DeliveryStatus(1001, 1));
	DL->Insert(new DeliveryStatus(1002, 1));
	DL->Insert(new DeliveryStatus(1003, 2));
	DL->Insert(new DeliveryStatus(1004, 3));
	DL->Insert(new DeliveryStatus(1005, 3));

	//MenuOption stores the users menu option choice to pass to the switch case
	int menuOption;

	do {
		//Display the menu items
		menuItems();
		cout << "Enter Number ";
		cin >> menuOption;
		//Switch case for menu options of the retail system that will perform the desired operations
		switch (menuOption) {
		case 1: {
			// Inserting a new customer based on user input
			int customerNumber;
			string firstName, lastName;

			cout << "Enter customer number: ";
			cin >> customerNumber;
			cout << "Enter first name: ";
			cin >> firstName;
			cout << "Enter last name: ";
			cin >> lastName;

			//Checks that a  user input of customer with the same customer number exists
			//in the customer hashtable, If it does exist output. 
			if (custTable->Find(customerNumber) != NULL) {
				cout << "Customer already exists with the same customer number.\n";
			}
			//Else create a new customer object into the custtable hash table
			//with the insert function. 
			else {
				custTable->Insert(new Customer(customerNumber, firstName, lastName));
				cout << "Customer inserted successfully.\n";
			}
			break;

		}
		case 2: {
			//Using the display function to show the contents of the hash table.
			custTable->Display();
			break;
		}

		case 3: {
			//Store user input
			int customerNumber;
			
			cout << "Enter the ID of the Customer you wish to find ";
			cin >> customerNumber;

			//This uses the find fucntion to search for a customer within the hash table that has an 
			// ID of cin that is entered, this returns a pointer to the customer object if it is found,
			// otherwise returns null, the result is stored in the obj1 pointer.

			Customer* obj1 = custTable->Find(customerNumber);
			if (obj1 != NULL) {
				cout << "Customer Record Fetched\n";
				cout << "Customer Number: " << obj1->custNumber << "\n";
				cout << "First Name: " << obj1->fName << "\n";
				cout << "Last Name: " << obj1->lName << "\n";
			}
			else
			{
				cout << "Customer ID does not exist in record";
			}
			break;
		}
		case 4: {
			//Store user input
			int customerNumber;

			cout << "Enter this ID of the Customer you wish to delete from record ";
			cin >> customerNumber;

			//This uses the delete function to delete a customer within the hash table
			//that has been entered by a user "customerNumber" the returned value 
			//is a pointer to the customer object, obj1 pointer.
			Customer* obj1 = custTable->Delete(customerNumber);

			//is the obj1 pointer is not null output the details of customer, then confirm 
			// message to user that has been removed. 
			if (obj1 != NULL) {
				cout << "Customer Record Found \n";
				cout << "Customer Number: " << obj1->custNumber << "\n";
				cout << "First Name: " << obj1->fName << "\n";
				cout << "Last Name: " << obj1->lName << "\n";
				cout << "Removed from Customer Record \n";
			}
			//Else output that the record is not in hash table.
			else
			{
				cout << "Customer Record does not exist in record";
			}
			break;
		}
		case 5: {
			//Store user input
			int orderDate;
			string orderName;

			cout << "Enter Delivery Due Date ";
			cin >> orderDate;
			cout << "Enter the name of the Customer ";
			cin >> orderName;

			//New order object with insert function into the targetids prioty queue,
			//with order date and name.
			targetIDs->Insert(new Order(orderDate, orderName));
			cout << "Order has been entered successfully \n";
			break;
		}
		case 6: {
			cout << "Order List : \n";
			//While loop that continues if the targetIDs queue is not empty,
			while (!targetIDs->IsEmpty()) {
				//Removes an order object from the front of the targetIDs order prioity
				//Queue and assigns it to the obj pointer
				Order* obj = targetIDs->Remove();
				cout << "Delivery Due Date : " << obj->key <<"\n" 
					<< " Name : " << obj->name << endl;
				cout << "Orders Sent \n";
			}
			break;
		}
		case 7: {
			cout << "List of Product In Order \n";
			//Starting from the rootnode to display the products in the product tree,
			//using the displayinorder function. this will traveres the tree recursively
			productTree->DisplayInOrder(productTree->root);
			break;
		}
		case 8: {
			//Store user inputs
			int productNumber;
			int price;

			cout << "Enter the Product Number ";
			cin >> productNumber;
			cout << "Enter the Price ";
			cin >> price;

			//Using the insert function of the product tree, passing the inputted data,
			//inserting a new product in the binary tree
			productTree->Insert(productNumber, price);
			cout << "New Product Added \n";
			break;
		}
		case 9: {

			//Stores user input
			int prodNumber;

			cout << "Enter the Product ID to find ";
			cin >> prodNumber;

			//Check is the product exists in the product binary tree, using the findproduct
			//function, passing the root node of the tree and product number, if found
			//get the product object using the find function, and assign it to the found,
			//pointer, then display the details of the product.
			if (productTree->findProduct(productTree->root, prodNumber)) {
				Product* found = productTree->Find(prodNumber);
				cout << "Product Number : " << found->productNumber << endl;
				cout << "Price : " << found->price << " GBP " << endl;
			}
			//else output the product is not apart of the record.
			else
			{
				cout << "Product does not exist \n";
			}
			break;
		}
		case 10: {

			//Stores user input
			int prodNumber;

			cout << "Enter the Product Number you wish to Remove ";
			cin >> prodNumber;

			//Removing the product specifed by the user, by using the remove product function
			//passing the root node of the tree, and prodnumber, then returns the new root
			//of the modified tree which is assigned to the root var in producttree.
			productTree->root = productTree->RemoveProduct(productTree->root,prodNumber);
			cout << "Product Removed \n";
			break;
		}
		case 11: {
			//Prints the delivery info 
			deliveryinfo();
			cout << "View Status of Delveries \n";

			//using the display function, of the DL object of the linked list to traverse
			// and display the contents of the DL object
			DL->Display();
			break;
		}
		case 12: {
			
			//Stores user input
			int statusSearch;

			cout << "Enter a Delivery Number ";
			cin >> statusSearch;

			//USing the find function, on the DL object, then passing the input from the user,
			//searching for a node with the delivery number then returns a pointer of SL to 
			//that node.
			DeliveryStatus* SL = DL->Find(statusSearch);
			//is the pointer is not null output message of the data.
			if (SL != 0) {
				cout << "Found the link with the data : " << SL->data <<  endl;
				cout << "Status : " << SL->status << "\n";
			}
			//Else node not found
			else
			{
				cout << " Cant find link ";
			}
			break;
		}
		case 13: {

			//Stores user input
			int statusSearch;

			cout << "Enter the delivery number you wish to remove ";
			cin >> statusSearch;

			//using the delete function, on the DL object, passing the user input, that will
			//search for a delivery node with the input, removing it and returning a pointer
			//to removed node
			DeliveryStatus* SL = DL->Delete(statusSearch);

			//if pointer to node is found display reomved message.
			if (SL != 0) {
				cout << "Removed \n";
			}
			//Else node not found
			else
			{
				cout << "Unable to find delivery \n";
			}


			break;
		}
		case 14: {
			//Exit the switch
			return 0;
		}
		//Default if a user input something that isnt a switch case option erorr message
		default: {
			cout << "Invalid Entry, please enter a valid menu number \n";
			break;
		}
		}
	} 
	while (menuOption != 14);
		

	return 0;
}
