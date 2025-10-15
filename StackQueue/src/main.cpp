#include <stdlib.h>
#include <iostream>
#include "stack.hpp"
#include "queue.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
	Queue<int> myQueue;
	cout << myQueue.isEmpty() << "\n";
	
	myQueue.push(12);	
	myQueue.push(42);	
	myQueue.push(3);	
	myQueue.push(0);	

	cout << myQueue.isEmpty() << "\n";

	myQueue.print();

	myQueue.pop();
	myQueue.print();

	Queue<int> myQueue2(myQueue);



/*    Stack<int> stack;

	stack.push(12);	
	stack.push(42);	
	stack.push(3);	
	stack.push(0);	

	cout << stack.top() << "\n";

	stack.print();
	
	stack.getLength();
	stack.isEmpty();

	Stack<int> stack2(stack);
	cout << (stack == stack2);*/
}


