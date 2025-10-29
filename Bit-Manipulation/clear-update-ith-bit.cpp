#include <iostream>
using namespace std;

// int updatedNum(int num, int pos, int val) {
//     int ans;
//     int bitMask;
//     switch (val)
//     {
//     case 0:
//         bitMask = ~(1 << pos);
//         ans = num & bitMask;
//         break;
//     case 1:
//         bitMask = 1 << pos;
//         ans = num | bitMask;
//         break;
//     default:
//         cout << "No val provided" << endl;
//         break;        
//     }
//     return ans;
// }

int updatedNum(int num, int pos, int val) {
    num = num & ~(1 << pos);
    return num | (val << pos);
}

int clearLast(int num, int i) {
    int bitMask = ~0 << i;
    return num & bitMask;
}

int main() {
    cout << updatedNum(7,2,0) << endl;
    cout << updatedNum(7,3,1) << endl;
    cout << clearLast(15,2) << endl;
    cout << clearLast(7,3) << endl;
    return 0;
}