#include <bits/stdc++.h>
using namespace std;

// Temp Class
class Node
{
public:
    Node *leftTree, *rightTree;
};

int heightOfBinaryTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = heightOfBinaryTree(root->leftTree);
    int rightHeight = heightOfBinaryTree(root->rightTree);

    int height = max(leftHeight, rightHeight) + 1;
    return height;
}

int main()
{
    // This file only has the funciton
    return 0;
}