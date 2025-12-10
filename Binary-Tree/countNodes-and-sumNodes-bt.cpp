#include <bits/stdc++.h>
using namespace std;

// Temp Class
class Node
{
public:
    int value;
    Node *leftTree, *rightTree;
};

int countNumberOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftcount = countNumberOfNodes(root->leftTree);
    int rightcount = countNumberOfNodes(root->rightTree);
    int totalCount = leftcount + rightcount + 1;
    return totalCount;
}

int sumOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = sumOfNodes(root->leftTree);
    int rightSum = sumOfNodes(root->rightTree);
    int total = leftSum + rightSum + root->value;
    return total;
}

int main()
{
    // This file only has the funciton
    return 0;
}