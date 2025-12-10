#include <bits/stdc++.h>
#define LINKEDLIST_MAIN
#include "ll-implementation.cpp"
using namespace std;

Node *splitMid(Node *head)
{
    Node *fast = head, *slow = head, *prev = NULL;
    while (fast != NULL && fast->getNext() != NULL)
    {
        fast = (fast->getNext())->getNext();
        prev = slow;
        slow = slow->getNext();
    }
    if (prev != NULL)
    {
        prev->setNext(NULL);
    }
    return slow;
}

List merge(List &leftList, List &rightList)
{
    List ans;
    Node *l = leftList.getHead();
    Node *r = rightList.getHead();
    while (l != NULL && r != NULL)
    {
        if (l->getData() <= r->getData())
        {
            ans.push_back(l->getData());
            l = l->getNext();
        }
        else
        {
            ans.push_back(r->getData());
            r = r->getNext();
        }
    }
    while (l != NULL)
    {
        ans.push_back(l->getData());
        l = l->getNext();
    }
    while (r != NULL)
    {
        ans.push_back(r->getData());
        r = r->getNext();
    }
    return ans;
}

List merge_sort(Node *head)
{
    if (head == NULL)
    {
        return List();
    }
    if (head->getNext() == NULL)
    {
        List single;
        single.push_back(head->getData());
        return single;
    }

    Node *rightHead = splitMid(head);
    List left = merge_sort(head);
    List right = merge_sort(rightHead);
    return merge(left, right);
}

void print_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

int main()
{
    List ll;
    ll.push_back(2);
    ll.push_back(1);
    ll.push_back(7);
    ll.push_back(0);

    ll.print_list();

    List ans = merge_sort(ll.getHead());
    ans.print_list();

    return 0;
}
