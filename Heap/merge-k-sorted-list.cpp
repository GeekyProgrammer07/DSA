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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // TODO: implement your logic here
        priority_queue<
            pair<int, ListNode *>,
            vector<pair<int, ListNode *>>,
            greater<pair<int, ListNode *>>>
            pq;
        for (auto &i : lists)
        {
            if (i != nullptr)
            {
                pq.push(make_pair(i->val, i));
            }
        }

        ListNode *head = new ListNode(-1);
        ListNode *tail = head;
        while (!pq.empty())
        {
            ListNode *temp = pq.top().second;
            pq.pop();
            tail->next = temp;
            if (temp->next != nullptr)
            {
                temp = temp->next;
                pq.push(make_pair(temp->val, temp));
            }
            tail = tail->next;
            tail->next = nullptr;
        }

        return head->next;
    }
};

// Create a linked list from vector
ListNode *buildList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;

    ListNode *head = new ListNode(vals[0]);
    ListNode *curr = head;

    for (int i = 1; i < vals.size(); i++)
    {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Print a linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution sol;

    // Example 1
    vector<vector<int>> input1 = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode *> lists1;
    for (auto &v : input1)
        lists1.push_back(buildList(v));

    ListNode *result1 = sol.mergeKLists(lists1);
    cout << "Test Case 1 Output: ";
    printList(result1); // Expected: 1->1->2->3->4->4->5->6

    // Example 2
    vector<ListNode *> lists2;
    ListNode *result2 = sol.mergeKLists(lists2);
    cout << "Test Case 2 Output: ";
    printList(result2); // Expected: empty

    // Example 3
    vector<vector<int>> input3 = {{}};
    vector<ListNode *> lists3;
    for (auto &v : input3)
        lists3.push_back(buildList(v));

    ListNode *result3 = sol.mergeKLists(lists3);
    cout << "Test Case 3 Output: ";
    printList(result3); // Expected: empty

    // Edge Case: single list
    vector<vector<int>> input4 = {{1, 2, 3, 4}};
    vector<ListNode *> lists4;
    for (auto &v : input4)
        lists4.push_back(buildList(v));

    ListNode *result4 = sol.mergeKLists(lists4);
    cout << "Test Case 4 Output: ";
    printList(result4); // Expected: 1->2->3->4

    return 0;
}
