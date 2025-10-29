#include <iostream>
using namespace std;

using ll = long long;

ll calculate_factorial(int num) {
    int factorial = 1;
    while (num > 1)
    {
        factorial *= num;
        num--;
    }
    return factorial;
}

int binomial_coefficient(int n, int r) {
    int answer = calculate_factorial(n)/((calculate_factorial(r))*calculate_factorial(n-r));
    return answer;
}

int main() {
    int n, r;
    cout << "Enter the numbers: ";
    cin >> n >> r;
    cout << binomial_coefficient(n,r) << endl;
    return 0;
}