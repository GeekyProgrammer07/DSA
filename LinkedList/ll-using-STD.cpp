#include <bits/stdc++.h>
using namespace std;

void print(list<int> ll) {
    list<int>::iterator itr;
    for (itr = ll.begin(); itr != ll.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}   

int main() {
    list<int> ll;
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(5);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(2);

    list<int>::iterator itr = ll.begin();
    advance(itr, 3);
    ll.insert(itr, 5,14);

    print(ll);

    return 0;
}