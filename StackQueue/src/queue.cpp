#ifdef QUEUE_H
#include <stdlib.h>
#include <iostream>
#include <list>


using namespace std;

template <class T>
Queue<T>::Queue() {
}

template <class T>
Queue<T>::Queue(const Queue<T> &sll) {
	for(auto i = sll.fullList.begin(); i != sll.fullList.end(); ++i)
	{
		fullList.push_back(*i);
	}

}

template <class T>
Queue<T>::~Queue() {
}

template <class T>
int Queue<T>::getLength() const {
	int length = 0;

	for(auto it = fullList.begin(); it != fullList.end(); ++it)
	{
		++length;
	}

	return length;
}

template <class T>
T& Queue<T>::first()
{
	return fullList.front();
}

template <class T>
bool Queue<T>::push(const T &val) {
	fullList.push_back(val);

	return true;
}

template <class T>
void Queue<T>::pop() {
	fullList.pop_front();
}

template <class T>
void Queue<T>::print() const {
	for(auto it = fullList.begin(); it != fullList.end(); ++it)
	{
		T temp = *it;
		std::cout << temp << "\n";
	}
}

template <class T>
bool Queue<T>::isEmpty() const {
	return fullList.empty();
}

template <class T>
bool Queue<T>::operator==(const Queue<T> &stack) const
{
	if(stack.getLength() != getLength()) {return false;}
	
	auto i = fullList.begin();
	auto it = stack.fullList.begin();
	
	while(i != fullList.end())
	{
		if(*i != *it)
		{
			return false;
		}
		++it;
		++i;
	}
	return true;
}
#endif
