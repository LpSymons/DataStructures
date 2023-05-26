#include "ProductBinaryTree.h"

//inialise the pointer to 0 or null;
ProductBinaryTree::ProductBinaryTree() {
    root = 0;
}
//Search for a product with a key, starts from the root node, comparing the keys to current
//nodes to determine to move left or right of the child
Product* ProductBinaryTree::Find(int key) {
    Product* current = root;
    while (current->productNumber != key) {
        if (key < current->productNumber)
            current = current->leftChild;
        else
            current = current->rightChild;
        if (current == 0)
            return 0;
    }
    return current;
}

//Ordered traveral of the tree displaying the products stored.
void ProductBinaryTree::DisplayInOrder(Product* localRoot) {
    if (localRoot != 0) {
        DisplayInOrder(localRoot->leftChild);
        localRoot->Display();
        DisplayInOrder(localRoot->rightChild);
    }
}

//Inserting a new product into tree, new product object newnode, then checks if the tree ius empty,
//inserting it, if not checking start from the root and locate the postion to insert the product.
void ProductBinaryTree::Insert(int productNumber, int price) {
   Product* newNode = new Product(productNumber, price);
    if (root == 0)
        root = newNode;
    else {
       Product* current = root;
        Product* parent;
        while (true) {
            parent = current;
            if (newNode->LessThan(newNode, current)) {
                current = current->leftChild;
                if (current == 0) {
                    parent->leftChild = newNode;
                    return;
                }
            }
            else {
                current = current->rightChild;
                if (current == 0) {
                    parent->rightChild = newNode;
                    return;
                }
            }
        }
    }
}

//find product function searching for a product that matches the input product number
bool ProductBinaryTree::findProduct(Product* root, int productNumber)
{
    if (root == NULL) {
        return false;
    }
    else if (root->productNumber == productNumber) {
        return true;
    }
    else if (productNumber <= root->productNumber) {
        return findProduct(root->leftChild, productNumber);
    }
    else {
        return findProduct(root->rightChild, productNumber);
    }
}

//find the minimum product node in the tree, returning pointer to the min node.
Product* Min(Product* root) {
    while (root->leftChild != NULL)
    {
        root = root->leftChild;
    }
    return root;
}

//Removes a product from the tree, traversing the tree and using the min fuctiuon to find the 
//minimum node in the tree
Product* ProductBinaryTree::RemoveProduct(Product* root, int productNumber) {
    if (root == NULL) {
        return root;
    }
    else if (productNumber < root->productNumber) root->leftChild =
        RemoveProduct(root->leftChild, productNumber);
    else if (productNumber > root->productNumber) root->rightChild =
        RemoveProduct(root->rightChild, productNumber);
    else
    {
        if (root->leftChild == NULL && root->rightChild == NULL) {
            delete root;
            root = NULL;
            return root;
        }
        else if (root->leftChild == NULL)
        {
            struct Product* temp = root;
            root = root->rightChild;
            delete temp;
            return root;
        }
        else if (root->rightChild == NULL)
        {
            struct Product* temp = root;
            root = root->leftChild;
            delete temp;
            return root;
        }
        else
        {
            struct Product* temp = Min(root->rightChild);
            root->productNumber = temp->productNumber;
            root->rightChild = RemoveProduct(root->rightChild, temp->productNumber);
        }
    }
    return root;


    
}

