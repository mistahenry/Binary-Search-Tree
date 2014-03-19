
#ifndef STACK_CLASS
#define STACK_CLASS

#include <iostream>
#include <stdlib.h>

#include "list1.h"

template <class T>
class Stack
{
    private:
    	// a linked list object to hold the stack items
    	DLL<T> stackList;

	public:
    	// constructor
		Stack(void);
		
        // stack access methods
        void Push(const T& item);
        void Pop(void);
        T Peek(void);
        // stack test and clear methods
        int StackEmpty(void) const;
};

// constructor
template <class T>
Stack<T>::Stack()
{}

 
// use the LinkedList method InsertFront to push item
template <class T>
void Stack<T>::Push(const T& item)
{
	stackList.Push_front(item);
}

template <class T>
T Stack<T>::Peek(){
	return stackList.Front();
}
// use the LinkedList method DeleteFront to pop stack
template <class T>
void Stack<T>::Pop()
{
	// check for an empty linked list
	if (stackList.IsEmpty())
	{
		cerr << "Popping an empty stack" << endl;
		exit(1);
	}
	// delete first node and return its data value
	else{
		 stackList.Pop_front();
	}
}


// use the LinkedList method ListEmpty to test for empty stack
template <class T>
int Stack<T>::StackEmpty(void) const
{
    return stackList.IsEmpty();
}

#endif  // STACK_CLASS

