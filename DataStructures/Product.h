#pragma once
#include <iostream>

using namespace std; 

class Product
{
public:
	//stores the product number
	int productNumber;
	//stores the price of a product
	int price;
	//left child is a pointer to the left child of the product in the binary tree
	Product* leftChild;
	//right child is a pointer to the right child of the product in the binary tree
	Product* rightChild;

	//constructor initalising varibles
	Product(int productNumber, int price);
	//Displau method to display products
	void Display();
	//compare two products 
	bool LessThan(Product* p1, Product* p2);
};

