#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return NULL;

        int length = 0;
        ListNode *iterator = head;

        while (iterator)
        {
            length++;
            iterator = iterator->next;
        }

        int posFromFront = length - n;

        if (posFromFront == 0)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        iterator = head;
        for (int i = 1; i < posFromFront; i++)
        {
            iterator = iterator->next;
        }

        ListNode *temp = iterator->next;
        iterator->next = iterator->next->next;
        delete temp;

        return head;
    }
};

int main()
{

    return 0;
}
