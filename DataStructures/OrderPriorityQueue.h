#pragma once

//defining a template class that is generic
template <class T>
class OrderPriorityQueue {
	//Max size of the prioity queue
	int size;
	//Pointer to an array of pointers to items in the piority queue
	T** data;
	//Count of items in the prioity queue
	int count;
public:
	//Constructor
	OrderPriorityQueue(int size);
	//Desctructor
	~OrderPriorityQueue();
	//inserts an item into the priority queue based on its priority
	void Insert(T* item);
	// Remove and returns the item with the highest prioity
	T* Remove();
	//returns a pinter to the itehm with the highest prioity
	T* PeakMin();
	//check if the prioity queue is empty 
	bool IsEmpty();
	//check is the prioity queue is full
	bool IsFull();
	//returns the max size of the queue
	int Size();
	//T* Display();
};
//construcor iniialising size and alocating memory for the data dynamically, 
//allocate memory for an array of pointers to ojects of type T
template <class T>
OrderPriorityQueue<T>::OrderPriorityQueue(int size) :size(size) {
	data = new T * [size];
	count = 0;
}
//Destructor
template <class T>
OrderPriorityQueue<T>::~OrderPriorityQueue() {
}
//Insert an item into the queue based on its prioity, if the prioity is empty add the item,
//at the index then incrementing the count, if the queue is not empty it then interates
//from the last index toward the start of the queue, comparing qeue items to other items 
//if the item has higher prioity shifts the current item up, then inserts new item at the
//correct index incrementing the count.
template <class T>
void OrderPriorityQueue<T>::Insert(T* item) {
	// Queue is empty
	if (count == 0) {
		data[count++] = item;
	}
	else {
		int j;
		// Start at the end work backwards 
		for (j = (count - 1); j >= 0; j--) {
			// If the new item is larger than current
			if (*item > *data[j]) {
				// Shift the current up
				data[j + 1] = data[j];
			}
			else {
				// Finished shifting
				break;
			}
		}
		data[j + 1] = item;
		count++;
	}
}
//removes item highest prioity in the queue and decrements count
template <class T>
T* OrderPriorityQueue<T>::Remove() {
	return data[--count];
}
//returns pointer to item with highest prioity 
template <class T>
T* OrderPriorityQueue<T>::PeakMin() {
	return data[count - 1];
}
//checks if the queue is empty by comparing count to 0;
template <class T>
bool OrderPriorityQueue<T>::IsEmpty() {
	return count == 0;
}
//compares count to size 
template <class T>
bool OrderPriorityQueue<T>::IsFull() {
	return count == size;
}
//returns the max size of the queue
template <class T>
int OrderPriorityQueue<T>::Size() {
	return size;
}