//Will Henry Traversal Class 4/11/12

//This class allows you to traverse a binary search tree in four different ways

#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "treenode.h"
#include "list1.h"
#include <iostream>

using namespace std;

template <class T> 
class Traversal
{
	friend class TreeNode<T>;

	public:
		Traversal();
		~Traversal();
		void InOrderVisit(TreeNode<T> *t, void (*)(T &));
		void PreOrderVisit(TreeNode<T> *t, void (*)(T &));
		void PostOrderVisit(TreeNode<T> *t, void (*)(T &));
		void LevelScan(TreeNode<T> *t, void (*)(T &));

	private:

};

template<class T>
Traversal<T>::Traversal(){

}

template<class T>
Traversal<T>::~Traversal(){

}

//visits nodes in order
template<class T>
void Traversal<T>::InOrderVisit(TreeNode<T> *node, void (*f)(T &)){
	if(node != NULL){
		InOrderVisit(node->left, f);
		if(node->value != NULL)
			f(node->value);
		InOrderVisit(node->right,f);
	}
}

//visits nodes preorder
template<class T>
void Traversal<T>::PreOrderVisit(TreeNode<T> *node, void (*f)(T &)){
	if(node != NULL){
		if(node->value != NULL)
			f(node->value);
		PreOrderVisit(node->left, f);
		PreOrderVisit(node->right, f);
	}
}

//visits nodes postorder
template<class T>
void Traversal<T>::PostOrderVisit(TreeNode<T> *node, void (*f)(T &)){
	if(node != NULL){
		PostOrderVisit(node->left, f);
		PostOrderVisit(node->right, f);
		if(node->value != NULL)
			f(node->value);
	}
}

//visits nodes level by level
template<class T>
void Traversal<T>::LevelScan(TreeNode<T> *node, void (*f)(T &)){
	DLL<TreeNode<T>*> list;
	while(node!= NULL){
		if(node->value != NULL)
			f(node->value);
		if(node->left != NULL){
			list.Push_back(node->left);
		}
		if(node->right != NULL){
			list.Push_back(node->right);
		}
		node = list.Front();
		list.Pop_front();
	}
}

#endif 		
