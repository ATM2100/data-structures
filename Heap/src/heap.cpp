#ifdef HEAP_H
#include <iostream>
template<class T>
Heap<T>::Heap(const int len) {
    capacity = len;
    size = 0;
}

template <class T>
void Heap<T>::siftUp() {
    int current = size;
    int parent = (current - 1) / 2;

    while (heap[parent] < heap[current]) {
        T temp = heap[current];
        heap[current] = heap[parent];
        heap[parent] = temp;

        current = parent;
        parent = (current - 1) / 2;
    }
}

template<class T>
void Heap<T>::insert(const T& element) {
    heap.push_back(element);
    siftUp();
    ++size;
}

template<class T>
T& Heap<T>::removeFirst() {
    T temp = heap[0];
	T& ret = temp;

	--size;
	heap[0] = heap[size];
	siftDown();

	return ret;
}

template <class T>
void Heap<T>::siftDown()
{
	int current = 0;
	int lindex = 1;
	int rindex = 2;
	int largestindex = (rindex < size && heap[lindex] < heap[rindex]) ? rindex : lindex;
	T temp;

	while(lindex < size && heap[current] < heap[largestindex])
	{
		temp = heap[current];
		heap[current] = heap[largestindex];
		heap[largestindex] = temp;

		current = largestindex;
		lindex = 2*current + 1;
		rindex = 2*current + 2;
		largestindex =  (rindex < size && heap[lindex] < heap[rindex]) ? rindex : lindex;
	}
}

template<class T>
T& Heap<T>::operator[](const int pos) {
	return heap[pos];
}

template<class T>
int Heap<T>::getSize() {
    return 0;
}

template<class T>
T* Heap<T>::heapSort() {
	T* heapArray = new T[size];
	T temp;
//	int tSize = size;
/*
	for(int i = 0; i < size; ++i)
	{
		heapArray[i*2 + 1] =
	}
*/

	for(int i = size - 1; i >= 0; --i)
	{
		temp = removeFirst();
		heapArray[i] = temp;
	}

	return heapArray;
}

template<class T>
Heap<T>::~Heap() {
}

template<class T>
void Heap<T>::print() {
}
#endif

