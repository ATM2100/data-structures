#include "priorityqueue.hpp"

int main(int argc, char *argv[]) {
    PriorityQueue<int> pq;

	pq.push(42);
	pq.push(0);
	pq.push(8);
	pq.push(10);
	pq.push(20);
	pq.push(-1);
	pq.push(90);
	pq.push(89);


	pq.print();

	std::cout << "pq.pop(): " << pq.pop() << "\n";
	std::cout << "pq.pop(): " << pq.pop() << "\n";
	std::cout << "pq.pop(): " << pq.pop() << "\n";
	
	pq.print();
	return 0;
}
