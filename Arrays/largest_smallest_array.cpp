#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4};
    int min = arr[0], max = arr[0];
    
    for(int i = 1; i < sizeof(arr)/sizeof(int); i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "The max element is: " << max << endl;
    cout << "The min element is: " << min << endl;
    return 0;
}