#include "Product.h"

//Constructor initialises product object with product numebr and price and setting 
//pointers for tree to null
Product::Product(int productNumber, int price) {
	this->productNumber = productNumber;
	this->price = price;

	leftChild = 0;
	rightChild = 0;
}
//Display method to display product
void Product::Display() {
	cout << "Product Number : " << this->productNumber << " Price : " << this->price << endl;
}
//function to compare two product objects
bool Product::LessThan(Product* p1, Product* p2) {
	if (p1->productNumber < p2->productNumber)
		return true;
	else
		return false;
}

