
#ifndef LIST1_H
#define LIST1_H

#include <new>
#include "node.h"

using namespace std;

template <class T> class DLL
{
 	friend class Node <T>;
	
	public:
		DLL();
		~DLL();
		int IsEmpty() const;
		int Length() const;
		void Push_front(const T &);
		void Push_back(const T &);
		void Pop_front();
		void Pop_back();
		const T Front() const;
		const T Back() const;
		void Print() const;
		void PrintBack() const;
		void Iterate(void (*)(T &));
		void Reverse();
		
	private:
		Node <T> *header;
		int length;
};

// default constructor for class DLL (default size empty)
template<class T>
DLL<T>::DLL() : length(0){
	header = new Node<T> ; // Create new header node
} // end DLL default constructor

template<class T>
DLL<T>::~DLL(){
	if(length >1){
		Node <T> *temp = new Node<T>;
                temp = header;
                for(int i =0; i < length-1; i++){
                        temp = temp->next;
			delete(temp->prev);
			
                }

	}
	delete(header);
}

//returns whether or not the list is empty
template<class T>
int DLL<T>::IsEmpty() const{
	if(length == 0){
		return 1;
	}
	else{
		return 0;
	}
}

//returns the number of items in the list
template<class T>
int DLL<T>::Length() const{
	return length;
}

//pushes data on back of list
template<class T>
void DLL<T>::Push_front(const T &data){
	if(length == 0){
		header->value = data;
	}
	  else if(length ==1){
                Node <T> *temp = new Node<T>;
                temp->value = header->value;
                temp->prev = header;
                header->value = data;
                header->next = temp;
        }

	else{
		Node <T> *old = new Node<T>;
		old->next = header->next;
		old->value = header->value;
		header->value = data;
		header->next = old;
		old->next->prev = old;
		old->prev = header;
	}
	length++;	
}

//pushes data on back of list
template<class T>
void DLL<T>::Push_back(const T &data){
	if(length == 0){
                header->value = data;
        }
	else{
		Node <T> *temp = new Node<T>;
		temp = header;
		for(int i =0; i < length-1; i++){
			temp = temp->next;
		}
		Node <T> *back = new Node<T>;
		back->value = data;
		back->prev = temp;
		temp->next = back; 
	}	
	length++;
}

template<class T>
void DLL<T>::Pop_front(){
	if(length > 2){
		header->next->next->prev = header;
		header->value = header->next->value;
		header->next = header->next->next;	
	}
	else if(length==2){
		header = header->next;
		header->prev = NULL;
	}
	else{
		header->next = NULL;
		header->prev = NULL;
		header->value = NULL;
	}
	length--;
}

template<class T>
void DLL<T>::Pop_back(){
	if(length > 1){
		 Node <T> *temp = new Node<T>;
        	temp = header;
        	int i;
        	for(i =0; i < length-1; i++){
                	temp = temp->next;
        	}
	}
	else{
		header->next = NULL;
                header->prev = NULL;
                header->value = NULL;
	}
	length--;
}

//returns value of front node
template<class T>
const T DLL<T>::Front() const{
	return header->value;
}

//returns value of back node
template<class T>
const T DLL<T>::Back() const{
	 Node <T> *temp = new Node<T>;
        temp = header;
        int i;
	for(i =0; i < length-1; i++){
                temp = temp->next;
        }
       	return temp->value;

}

//goes thru each node and implements a function on the value
template<class T>
void DLL<T>::Iterate(void (*f)(T &)){
	f(header->value);
	Node <T> *temp = new Node<T>;
        temp = header;
        int i;
        for(i =0; i < length-1; i++){
                temp = temp->next;
		f(temp->value);
 	}
}

//reverses the list
template<class T>
void DLL<T>::Reverse(){
	Node <T> *temp = new Node<T>;
        temp = header;
        int i;
	for(i =0; i < length-1; i++){
                temp = temp->next;
	}
	header = temp;
	header->next = temp->prev;
	for(i =0; i < length-1; i++){
                temp = temp->prev;
		temp->next = temp->prev;
        }
	 temp = header;
	 for(i =0; i < length-1; i++){
 	        temp->next->prev = temp;
		temp = temp->next;
        }
	temp->next = NULL;
	header->prev = NULL;
}


#endif
