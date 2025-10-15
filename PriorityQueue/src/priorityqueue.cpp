#ifdef PRIORITY_QUEUE_H
#include <functional>
#include <iostream>

template<class T>
bool PriorityQueue<T>::push(const T &val)
{
	vec.push_back(val);
	push_heap(vec.begin(), vec.end());
	return true;
}

template<class T>
T PriorityQueue<T>::pop()
{
	T ret = vec[0];
	pop_heap(vec.begin(), vec.end());
	vec.pop_back();
	return ret;
}

template<class T>
bool PriorityQueue<T>::isEmpty() const
{
	return vec.empty();
}

template<class T>
PriorityQueue<T>::PriorityQueue() {
	make_heap(vec.begin(), vec.end());
}

template <class T>
bool PriorityQueue<T>::operator==(const PriorityQueue<T> &pq) const
{
	for(int i = 0; i < vec.size(); ++i)
	{
		if(vec[i] != pq[i])
			return false;
	}
	return true;
}

template <class T>
int PriorityQueue<T>::getLength() const {
	return vec.size();
}

template <class T>
void PriorityQueue<T>::print() const
{
    std::cout << "\n";
    for (auto i = vec.begin(); i != vec.end(); i++) {
        std::cout << *i << ", ";
    }
    std::cout << "\n";
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &pq) {
	for(auto i = pq.begin(); i < pq.end(); i++)
	{
		vec.push_back(pq[i]);
	}
	make_heap(vec.begin(), vec.end());
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
}

#endif
