#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

#include "binstree.h"          // include  BinSTree class
#include "traversal.h"        // for Inorder scan
#include "treenode.h"
#include "stack.h"

using namespace std;

//determines if value of node is an operand
int isOperand(TreeNode<char> *node){
	char c = node->value;
	if ( ((c >= 'a') && (c <= 'z'))  || ((c >= 'A') && (c <= 'Z')) ){
		return true;
	}
	
	//determines if operator has children, which basically makes it an operand
	else if(node->left != NULL & node->right != NULL){
		 if(node->left->value != NULL && node->right->value != NULL){
			return true;
		}
		else 
			false;
	}
	else{
		return false;
	}	
}

//builds expression tree 
TreeNode<char> *BuildExpTree(char arr[], int length){
	int i;
	char c;
	TreeNode<char> *lc = new TreeNode<char>();
        TreeNode<char> *rc= new TreeNode<char>();
        TreeNode<char> *op= new TreeNode<char>();

	Stack<TreeNode<char> *> s;
	for(i = 0; i < length; i++){
		c = arr[i];
		TreeNode<char> *node = new TreeNode<char>(c);		
		s.Push(node);
		int count;
		int success = 1;
		while(success){
			count = 0;
			while(count < 3){
				if(count == 0){
					rc = s.Peek();
					s.Pop();
					if(s.StackEmpty()){                                            
                	                        s.Push(rc);
                        	                count = 3;
						success = 0;
	                                }
				}
				else if(count == 1){
					lc = s.Peek();
					s.Pop();
					if(s.StackEmpty()){
        	                                s.Push(lc);
                	                        s.Push(rc);
                        	        	count = 3;
						success = 0;
					}
				}
				else{
					op = s.Peek();
					s.Pop();
					if(isOperand(lc) && isOperand(rc) && !isOperand(op)){
						op->left = lc;
						op->right = rc;	
						s.Push(op);
					}
					else{
						s.Push(op);
						s.Push(lc);
						s.Push(rc);
						success = 0;
					}	
				}
				count++;
			}
		}	
	}
	return op;
}

void PrintChar(char& item)
{
	cout << item << " ";
}



int main(int argc, const char* argv[]){
    
	//declare a tree of Word objects read from stream fin
	ifstream fin;
	BinSTree<char> tree;
	TreeNode<char> *t;
	Traversal<char> *trav;
	char s[50];
    
    
        //open the file "expr.txt"
	fin.open("expr.txt", ios::in);
        if (!fin)
        {
        	cerr << "Cannot open \"expr.txt\"\n";
        	exit(1);
	}


    	//test BuildExpTree, PrintVTree and display infix and postfix forms
    	while(fin >> s)
	{
		cout << "The prefix representation retrieved from the file : " << endl;
		cout << s << endl << endl;
	}
	int i;
	i = strlen(s);    
	t = BuildExpTree(s, i);

        // print the tree 
	cout << "The Vertical Tree representation: " << endl;
	tree.PrintVTree(t, 2, 2000);
	
	//skip some space
	cout << endl << endl << endl;

	//Infix display
	cout << "The Infix representation: " << endl;
	trav->InOrderVisit(t, PrintChar);
	cout << endl << endl << endl;

	//Postfix display
	cout << "The Postfix representation: " << endl;
	trav->PostOrderVisit(t, PrintChar);
	cout << endl << endl << endl;
    
     
	
 
}


