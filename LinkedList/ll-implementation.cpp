#include <bits/stdc++.h>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }

    // This is a getter function as data is a private member
    int getData()
    {
        return this->data;
    }
    Node *getNext()
    {
        return this->next;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    Node *getHead()
    {
        return this->head;
    }

    void push_front(int data)
    {
        Node *newNode = new Node(data); // Address of the new node
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->setNext(head);
            head = newNode;
        }
    }

    void push_back(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    void insert(int data, int pos)
    {
        if (pos == 0)
        {
            cout << "Use push_front instead" << endl;
            return;
        }

        Node *newNode = new Node(data);

        if (head == NULL && pos != 0)
        {
            cout << "Invalid Position for empty list" << endl;
            delete newNode;
            return;
        }

        Node *iterator = head;
        int i;

        for (i = 0; i < pos - 1 && iterator != NULL; i++)
        {
            iterator = iterator->getNext();
        }

        if (iterator == NULL)
        {
            cout << "Invalid Position: " << pos << endl;
            delete newNode;
            return;
        }
        if (iterator == tail)
        {
            cout << "Use push_back instead" << endl;
            return;
        }

        newNode->setNext(iterator->getNext());
        iterator->setNext(newNode);
    }

    void pop_front()
    {
        if (head != NULL)
        {
            Node *temp = head;
            head = head->getNext();
            if (head == NULL)
            {
                tail = NULL;
            }
            temp->setNext(NULL);
            delete temp;
            return;
        }
        else
        {
            cout << "Linked list is empty" << endl;
            return;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->getNext() != tail)
        {
            temp = temp->getNext();
        }
        delete tail;
        temp->setNext(NULL);
        tail = temp;
    }

    int search_ll(Node *head, int key)
    {
        if (head == NULL)
        {
            return -1;
        }
        if (head->getData() == key)
        {
            return 0;
        }
        int index = search_ll(head->getNext(), key);
        if (index == -1)
        {
            return -1;
        }
        return index + 1;
    }

    void print_list()
    {
        Node *iterator = head;
        while (iterator != NULL)
        {
            cout << iterator->getData() << " ";
            iterator = iterator->getNext();
        }
        cout << endl;
    }
};

int main()
{
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.print_list();

    ll.push_back(4);
    ll.push_back(5);
    ll.print_list();

    ll.insert(0, 0);
    ll.insert(6, 6);
    ll.print_list();
    ll.insert(99, 3);
    ll.insert(100, 20);

    ll.pop_front();
    ll.print_list();
    ll.pop_back();
    ll.print_list();

    cout << "5 is at index: " << ll.search_ll(ll.getHead(), 5) << endl;
    return 0;
}