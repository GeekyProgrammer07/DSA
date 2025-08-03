#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter the number: ";
    cin >> n;
    int temp = 65;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << (char) temp;
            temp++;
        }
        cout << endl;
    }
    
    return 0;
}