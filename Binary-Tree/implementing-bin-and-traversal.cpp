#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *leftTree, *rightTree;

    Node(int value)
    {
        this->value = value;
        this->leftTree = NULL;
        this->rightTree = NULL;
    }
};

static int indx = -1;
Node *buildTree(vector<int> values)
{
    if (indx == -1)
    {
        indx = -1;
    }
    indx++;
    if (indx >= values.size() || values[indx] == -1)
    {
        return NULL;
    }
    Node *currNode = new Node(values[indx]);
    currNode->leftTree = buildTree(values);
    currNode->rightTree = buildTree(values);

    return currNode;
}

// Linear Time Complexity
void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->value << " ";
    preorderTraversal(root->leftTree);
    preorderTraversal(root->rightTree);
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->leftTree);
    cout << root->value << " ";
    inorderTraversal(root->rightTree);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->leftTree);
    postorderTraversal(root->rightTree);
    cout << root->value << " ";
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Node *curr = Q.front();
        if (curr->leftTree)
        {
            Q.push(curr->leftTree);
        }
        if (curr->rightTree)
        {
            Q.push(curr->rightTree);
        }
        cout << curr->value << " ";
        Q.pop();
    }
}

void levelOrderTraversalPrintLevel(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        Node *curr = Q.front();
        Q.pop();
        if (curr == NULL)
        {
            if (Q.empty())
            {
                break;
            }
            Q.push(NULL);
            cout << endl;
        }
        else
        {
            cout << curr->value << " ";
            if (curr->leftTree)
            {
                Q.push(curr->leftTree);
            }
            if (curr->rightTree)
            {
                Q.push(curr->rightTree);
            }
        }
    }
}

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
    vector<int> something = {1, 2, 5, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *rootNode = buildTree(something);

    preorderTraversal(rootNode);
    cout << endl;
    inorderTraversal(rootNode);
    cout << endl;
    postorderTraversal(rootNode);
    cout << endl;
    levelOrderTraversalPrintLevel(rootNode);
    cout << endl;
    cout << "Height of Tree: " << heightOfBinaryTree(rootNode) << endl;
    cout << "Total number of Nodes: " << countNumberOfNodes(rootNode) << endl;
    cout << "Sum of all Nodes: " << sumOfNodes(rootNode) << endl;
    return 0;
}