//
// Name Vincent Leahy
// Date 11/23/2025
// Node Counter Programming Project
// COSC 2030
//

template <class T>
int BinaryTree<T>::numNodes()
{
    return coutNodes(root);
}

template <class T>
int BinaryTree<T>:: countNodes(TreeNode *&nodePtr)
{
    if (nodePtr == NULL)
        return 0;
    else
        return 1 + countNodes(nodePtr->left) + countNodes(nodePtr->right);
}

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
    //create a binary tree to hold integers

    BinaryTree<int> tree;

    //insert some nodes inot the tree

    count << "Insertying nodes.\n";
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(3);
    tree.insertNode(12);
    tree.insertNode(9);

    //get the number of nodes
    
    cout << "\nNumber of nodes: "
        << tree.numNodes() << endl;
    count << "\nHere are the values in the tree:\n";

    //displayy the tree 
    tree.displayInOrder();

    //delete some nodes from the tree

    cout << "Deleting 8...\n";
    tree remove(8);
    cout << "Deleting 12...\n";
    tree.remove(12);

    //get the number of nodes

    cout << "\nNumber of nodes: "
        <<tree.numNodes() << endl;


    //display the nodes

    cout << "Now, here are the nodes:\n";
    tree.displayInOrder();

    return 0;
}