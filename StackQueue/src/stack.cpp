#ifdef STACK_H
#include <stdlib.h>
#include <iostream>
#include "stack.hpp"
#include <list>

using namespace std;

template <class T>
Stack<T>::Stack() {
}

template <class T>
Stack<T>::Stack(const Stack<T> &sll) {
	for(auto i = sll.fullList.begin(); i != sll.fullList.end(); ++i)
	{
		fullList.push_back(*i);
	}

}

template <class T>
Stack<T>::~Stack() {
}

template <class T>
int Stack<T>::getLength() const {
	int length = 0;

	for(auto it = fullList.begin(); it != fullList.end(); ++it)
	{
		++length;
	}

	return length;
}

template <class T>
bool Stack<T>::push(const T &val) {
	fullList.push_front(val);

	return true;
}

template <class T>
T& Stack<T>::top() {
	return fullList.front();
}

template <class T>
void Stack<T>::pop() {
	fullList.pop_front();
}

template <class T>
void Stack<T>::print() const {
	for(auto it = fullList.begin(); it != fullList.end(); ++it)
	{
		T temp = *it;
		std::cout << temp << "\n";
	}
}

template <class T>
bool Stack<T>::isEmpty() const {
	return fullList.empty();
}

template <class T>
bool Stack<T>::operator==(const Stack<T> &stack) const
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
