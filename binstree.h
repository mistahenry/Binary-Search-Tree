//Will Henry 4/12/12

//The Binary Search Class has many functions in it that make it a binary search tree.
//You can easily search for data, the tree inserts and deletes properly

#ifndef BINS_TREE
#define BINS_TREE

#include "traversal.h"
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

template <class T>
class BinSTree
{
	friend class TreeNode<T>;
	
	protected:
		TreeNode<T> *root;
		TreeNode<T> *current;
		int size;
		TreeNode<T> * FindMin(TreeNode<T> *node);
		void Delete(const T& item, TreeNode<T> *node, TreeNode<T> *node1);
		void Insert(const T& item, TreeNode<T> *node);
		void FreeTreeNode(TreeNode<T> *node);
		TreeNode<T> * CopyTree(TreeNode<T> *root);
	public:
		BinSTree();
		BinSTree(BinSTree<T>& tree);
		~BinSTree();
		BinSTree & operator= (const BinSTree &v);
		int Depth(TreeNode<T> *t);
		void PrintTree(TreeNode<T> *t, int level);
		void PrintVTree(TreeNode<T> *t, int dataWidth, int screenWidth);
		void CountLeaf(TreeNode<T> *t, int &count);
		int Find(const T &item);
		void Insert(const T &item);
		void Delete(const T &item);
		void ClearTree();
		int TreeSize();
		void Update(const T &item);
		int TreeEmpty();
		TreeNode<T>* GetRoot();		
};

//Find the minimum value in tree
template<class T>
TreeNode<T>* BinSTree<T>::FindMin(TreeNode<T> *node){	
	if(node->value == NULL){
		return NULL;
	}
	else if(node->left->value == NULL){
		return node;
	}	
	return FindMin(node->left);
}

//calls the delete operator to a node
template<class T>
void BinSTree<T>::FreeTreeNode(TreeNode<T> *node){
	delete node;
}

//Deletes a node    	
template<class T>
void BinSTree<T>::Delete(const T& item, TreeNode<T> *node, TreeNode<T> *parent){
	if(node == NULL){
		return;
	}
	if(item < node->value){
		Delete(item, node->left, node);
	}
	else if(node->value < item){
		Delete(item, node->right, node);
	}
	else if(node->left != NULL && node->right != NULL){
		if(node->left->value != NULL && node->right->value != NULL){
			node->value = (FindMin(node->right)->value);
			Delete(node->value, node->right, node);
		}
		else{
			TreeNode<T> *oldNode = new TreeNode<T>();
                	oldNode = node;
                	node = (node->left->value != NULL) ? node->left : node->right;
			if(oldNode == parent->right){
                        	parent->right = node;
                	}
              	  	else{
                        	parent->left = node;
                	}
		}

	}
	else{	
		TreeNode<T> *oldNode = new TreeNode<T>();
		oldNode = node;
		node = (node->left != NULL) ? node->left : node->right;
		if(oldNode == parent->right){
			parent->right = node;
		}
		else{
			parent->left = node;
		}
	}
}	

//Inserts a node
template<class T>
void BinSTree<T>::Insert(const T& item, TreeNode<T> *node){
	if(item < node->value){
                if(node->left != NULL){
			if(node->left->value == NULL)
				node->left->value = item;
			else
                        	Insert(item, node->left);
                } 
                else{
			TreeNode<T> *temp = new TreeNode<T>(item); 
                        node->left = temp;
                }
        }
        else{
                if(node->right != NULL){
			if(node->right->value == NULL)
				node->right->value = item;
			else
                        	Insert(item, node->right);   
                }
                else{
			TreeNode<T> *temp = new TreeNode<T>(item);
                        node->right = temp;
                }
        }

}

//copys tree and returns root of identical tree
template<class T>
TreeNode<T>* BinSTree<T>::CopyTree(TreeNode<T> *node){
	if(node == NULL)
		return NULL;
	else if(node->value == NULL)
		return NULL;
	TreeNode<T> *node1 = new TreeNode<T>(node->value, CopyTree(node->left), CopyTree(node->right));
	return node1;
}

//default constructor for class BSTree
template<class T>
BinSTree<T>::BinSTree(){
	root = new TreeNode<T>();
	current = new TreeNode<T>();
	size = 0;
}

//copy constructor
template<class T>
BinSTree<T>::BinSTree(BinSTree<T> &tree){
	root = CopyTree(tree.GetRoot());
	current = new TreeNode<T>();
	current = tree.current;
	size = tree.size;
}

//destructor
template<class T>
BinSTree<T>::~BinSTree(){
}

//overloads assignment operator
template <class T>
BinSTree<T> & BinSTree<T>::operator=(const BinSTree &v){
	if(this != &v){
		root = CopyTree(v.root);
	}
	return *this;
}

//calculates depth of tree
template<class T>
int BinSTree<T>::Depth(TreeNode<T> *node){
	if(node == NULL){
		return 0;
	}
	return max(Depth(node->left) +1, Depth(node->right) + 1);
}

//print tree
template<class T>
void BinSTree<T>::PrintTree(TreeNode<T> *node, int level){
	int depth = Depth(node);
	int y;
	int x;
	DLL<TreeNode<T>*> list;
	DLL<TreeNode<T>*> list1;
	list1.Push_back(node);
	list.Push_back(node);
	if(node == root){
		for(x = 1; x < depth; x++){
			for(y = 0; y < pow(2, x-1); y++){
				node = list.Front();
        	                list.Pop_front();
                	        if(node->left == NULL){                                        
					node->left = new TreeNode<T>();
					list.Push_back(node->left);
				}
				else{
					list.Push_back(node->left);
				}
				if(node->right == NULL){
					node->right = new TreeNode<T>();
					list.Push_back(node->right);
				}
				else{
					list.Push_back(node->right);
				}
			}
		}
	}
	node = list1.Front();
	if(node->right != NULL){
		PrintTree(node->right, level+1);
	}
	int i;
	for(i = 0; i < level; i++){
		cout<<"\t";
	}
	if(node->value != NULL)
		cout<<node->value;
	else
		cout<<" ";
	cout<<endl;
	if(node->left != NULL){
		PrintTree(node->left, level+1);
	}
}

//print vertical tree if there is room
template<class T>
void BinSTree<T>::PrintVTree(TreeNode<T> *node, int dataWidth, int screenWidth){
	int depth = Depth(node);
	if((pow(2, depth-1)*dataWidth + (pow(2, depth-1)-1)*3) < screenWidth){
		DLL<TreeNode<T>*> list;
		DLL<TreeNode<T>*> list1;
		list1.Push_back(node);
		list.Push_back(node);
		int x;
		int y;
		for(x = 1; x < depth; x++){
			for(y = 0; y < pow(2, x-1); y++){
				node = list.Front();
				list.Pop_front();
				if(node->left == NULL){
					node->left = new TreeNode<T>();
					list1.Push_back(node->left);
					list.Push_back(node->left);
				}
				else{
					list1.Push_back(node->left);
					list.Push_back(node->left);
				}
				if(node->right == NULL){
					node->right = new TreeNode<T>();
					list1.Push_back(node->right);
					list.Push_back(node->right);
				}
				else{
					list1.Push_back(node->right);
					list.Push_back(node->right);
				}
				
			}
		}	 

		int n = 1;
		node = list1.Front();
		list1.Pop_front();
		int i;
		int l;
		for(x = 0; x < depth; x++){
			for(i = 0; i < pow(2, x); i++){
				if(x != (depth - 1)){
					if(i == 0){
						for(y = 0; y < (pow(2, depth - x) - 2); y++){
							cout<<" ";
						}
					
					}
					else{
						for(y = 0; y < (pow(2, depth - (x-1)) - 1); y++){
							cout<<" ";
						}
					}
				}
				else{
					if(i != 0){
						for(y = 0; y < 3; y++){
							cout<<" ";
						}
					}
				}
				if(node->value == NULL){
					cout<<" ";
                        	}
				else{
					cout<<node->value;
				}
				node = list1.Front();
				list1.Pop_front();
			}
			cout<<endl<<endl;
		}
		
	}	
}

//calculates number of leaves in tree
template<class T>
void BinSTree<T>::CountLeaf(TreeNode<T> *node, int &count){
	int i = 0;
	DLL<TreeNode<T>*> list;
	while(node != NULL){
		if(node->left != NULL){
			if(node->left->value != NULL)
				list.Push_back(node->left);
		}
		if(node->right != NULL){
			if(node->right->value != NULL)
				list.Push_back(node->right);
		}
		if(node->right == NULL && node->left == NULL){
			i++;
		}
		else if(node->right == NULL){
			if(node->left->value == NULL)
				i++;
		}
		else if(node->left == NULL){
			if(node->right->value == NULL)
				i++;
		}
		else{
			if(node->right->value ==NULL && node->left->value == NULL)
				i++;
		} 
		node = list.Front();
		list.Pop_front();
		
	}
	count = i;	
}

//returns 1 if found, else returns 0
template<class T>
int BinSTree<T>::Find(const T &item){
	TreeNode<T> *node = root;
	while(node != NULL){
		if(node->value == item){
			current = node;
			return 1;
		}
		if(node->value < item){
			node = node->right;
		}
		else{
			node = node->left;
		}
	}
	return 0;
}

//calls protected insert method using root as node parameter
template<class T>
void BinSTree<T>::Insert(const T& item){
	if(item == 0){
		cout<<"This tree cannot handle zero's"<<endl;
	}
	else if(root->value == NULL){
		root->value = item;
	}
	else{
		Insert(item, root);
	}
	size++;
}

//calls protected delete method using root as node parameter
template<class T>
void BinSTree<T>::Delete(const T &item){
	TreeNode<T> *parent = new TreeNode<T>();
	Delete(item, root, parent);
	size--;
}

//Clears tree but doesn't delete the tree
template<class T>
void BinSTree<T>::ClearTree(){
	TreeNode<T> *node = GetRoot();
	  DLL<TreeNode<T>*> list;
          while(node!= NULL){
                if(node->left != NULL){
                        list.Push_back(node->left);
                }
                if(node->right != NULL){
                        list.Push_back(node->right);
                }
		if(node != root){
			if(node->value != NULL){
				FreeTreeNode(node);
				size--;
			}
			else 
				FreeTreeNode(node);
		}
                node = list.Front();
                list.Pop_front();
        }	
	FreeTreeNode(root);
	root->value = NULL;
	size--;		
}

//returns the number of nodes in the tree
template<class T>
int BinSTree<T>::TreeSize(){
	return size;
}

//if current->value doesn't equal item, adds item to tree. Else performs update
template<class T>
void BinSTree<T>::Update(const T &item){
	if(current->value != item){
		Insert(item);
	}
	else{
		cout<<"Current->value = " << item <<". Update was performed.";
	}
}

//returns 1 if tree is empty else returns 0
template<class T>
int BinSTree<T>::TreeEmpty(){
	if(root->value == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

//returns the pointer to the root
template<class T>
TreeNode<T>* BinSTree<T>::GetRoot(){
	if(root->value == NULL){
		cout<<"Root's value is undefined";
	}
	else{
		return root;
	}
}
#endif
