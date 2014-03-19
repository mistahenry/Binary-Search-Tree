//Will Henry TreeNode Class 4/9/12

//This class creates an individual treenode that can be used to build a tree

#ifndef TREENODE_H
#define TREENODE_H

//#include "traversal.h"
#include <stddef.h>

template<class T> class BSTree;

template<class T> 
class TreeNode{

	friend class BSTree<T>;
	//friend class Traversal<T>;
public:
	T value;
	TreeNode(): value(NULL), left(NULL), right(NULL){};
	TreeNode(const T &v): value(v), left(NULL), right(NULL){};
	TreeNode(const T &v, TreeNode<T> *node): value(v), left(node), right(NULL){};
	TreeNode(const T &v, TreeNode<T> *node1, TreeNode<T> *node2): value(v), left(node1), right(node2){};
	TreeNode<T> * GetLeftChild();
	TreeNode<T> * GetRightChild();
public:
	TreeNode<T> *left;
	TreeNode<T> *right;
};

template<class T>
TreeNode<T> *TreeNode<T>::GetLeftChild(){
	return left;
}

template<class T>
TreeNode<T> *TreeNode<T>::GetRightChild(){
	return right;
}
#endif
