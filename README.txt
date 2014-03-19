First off, when you compile you will get a lot of warnings. All these warnings say is that I am using NULL in arithmetic.
I do that because I build a virtual tree, which is necessary for spacing the tree correctly when printing vertically and the tree is not perfect (some nodes only have one child).
Therefore, my binary search tree will work for a domain of natural numbers, or even all numbers that are not zero. Inserting zero will not work.

To compile type:
	make compile
To run type:
	make run
To clean binary type:
	make clean

To run a file of your own, open up the make file and replace main.cc with another .cc file. 

All files must include "traversal.h", "binstree.h", and "treenode.h". The main file must include "stack.h".

If you wish to change the prefix expression, open up expr.txt and replace it.
	-must be a valid prefix expression.
	-place no spaces between operators and operands
	-I have included a sample expr.txt
Output of successful main run:

The prefix representation retrieved from the file :
+-a/*bcde

The Vertical Tree representation:
                              +

              -                               e

      a               /

                  *       d

                b   c




The Infix representation:
a - b * c / d + e


The Postfix representation:
a b c * d / - e +
