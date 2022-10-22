
This program requires you to implement a Binary Search Tree with the following operations to be executed on the tree : 
1)	Insert a node in the tree
2)	Delete a node from the tree
3)	Search for an element in the tree
4)	Traverse the tree in Preorder, Inorder and Postorder fashion
5)	Print the contents of the tree in preorder fashion

The program shall comprise of the following files:
TreeNode.h
BST.h
BST.cpp
Driver.cpp

The file TreeNode.h shall consist of the class TreeNode. This class shall have BST as its friend class. In addition, this file should also contain the description of the class constructor and accessor functions (thus we avoid creating a TreeNode.cpp) The outline of this file is as follows:

Class TreeNode {
                             Friend class BST;
Public:
  TreeNode();  //default constructor
  TreeNode(int i, TreeNode* L = 0; TreeNode* R = 0); //explicit value constructor
  int getItem () const; // accessor function

private:
 int item;
  TreeNode *Lchild;
  TreeNode *Rchild;
  
};

TreeNode::TreeNode()
{
    Lchild = Rchild = NULL;
}

TreeNode::TreeNode(int i, TreeNode *L = 0, TreeNode *R = 0) : item(i), Lchild(L), Rchild(R)
{}

int TreeNode::getItem() const
{ return item;}

The file BST.h shall contain the class declaration of class BST. In addition to the public member functions, have 4 utility functions which will help you to perform the search, preorder, postorder and inorder traversal operations. The file BST.cpp shall contain the public function descriptions that were declared in file BST.h. 

The file driver.cpp should test all the functionalities that you have incorporated for the BST.

NOTE: have the iterative and Recursive implementations of the basic methods!
