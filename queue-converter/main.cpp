//
// Name Vincent Leahy
// Date 11/23/2025
// Queue Converter Programming Project
// COSC 2030
//

#include <iostream>
#include <queue>
using namespace std;


//binary search tree node

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v)
    {
        value = v;
        left = nullptr;
        right = nullptr;
    }
};


//inserting value into the BST

void insertNode(TreeNode*& root, int value)
{
    if (root == nullptr)
    {
        root = new TreeNode(value);
    }

    else if (value < root->value)
    {
        insertNode(root->left, value);
    }
    
    else
    {
        insertNode(root->right, value);
    }
}

void fillQueueInOrder(TreeNode* root, queue<int>& q)
{
    if (root == nullptr)
    return;

    fillQueueInOrder(root->left, q);
    q.push(root->value);
    fillQueueInOrder(root->right, q);
}


//main program
int main()
{
    TreeNode* root = nullptr;
    queue<int> sortedQueue;

    //insert numbers into the tree

    insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 9);
    insertNode(root, 1);
    insertNode(root, 7);
    insertNode(root, 3);

    //queue in sorted  order
    fillQueueInOrder(root, sortedQueue);

    //dequeue and display values

    cout << "Numbers in ascending order:\n";
    
    while (!sortedQueue.empty())
    {
        cout << sortedQueue.front() << " ";
        sortedQueue.pop();
    }

    cout << endl;
    return 0;
}