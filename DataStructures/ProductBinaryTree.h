#pragma once
#include "Product.h"
#include <iostream>

using namespace std;

class ProductBinaryTree
{
public:
	//Pointer to the root of the binary tree containing products
	Product* root;
	//constructor
	ProductBinaryTree();
	//Search for product with a key in the binary tree, taking a pointer to product object
	Product* Find(Product* key);
	//Takes a int key instead of a pointer for find
	Product* Find(int key);
	//search for a product object, pointer to product as the root 
	bool findProduct(Product* root, int productNumber);
	//In order display taking a pointer to product as the root 
	void DisplayInOrder(Product* localRoot);
	//Insert a new product into the tree taking prodnum and price
	void Insert(int productNumber, int price);
	//returning a pointer to  product object, with root of tree, removing product
	struct Product* RemoveProduct(struct Product* root, int productNumber);

};

