#include <iostream>
#include <string>
using namespace std;

int countLowercaseVowels(const string &str) {
    string vowels = "aeiou";
    int count = 0;
    for (char c : str) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

// Test function
void runTests()
{
    // Test 1: Empty string
    cout << "Test 1: " << (countLowercaseVowels("") == 0 ? "Passed" : "Failed") << endl;

    // Test 2: All vowels
    cout << "Test 2: " << (countLowercaseVowels("aeiou") == 5 ? "Passed" : "Failed") << endl;

    // Test 3: Mixed string
    cout << "Test 3: " << (countLowercaseVowels("hello world") == 3 ? "Passed" : "Failed") << endl;

    // Test 4: No vowels
    cout << "Test 4: " << (countLowercaseVowels("rhythm") == 0 ? "Passed" : "Failed") << endl;

    // Test 5: Mixed case string
    cout << "Test 5: " << (countLowercaseVowels("AeIoUaeiou") == 7 ? "Passed" : "Failed") << endl;
}

int main()
{
    // string input;
    // cout << "Enter a string: ";
    // getline(cin, input);

    // int count = countLowercaseVowels(input);
    // cout << "Number of lowercase vowels: " << count << endl;

    cout << "Running test cases...\n";
    runTests();

    return 0;
}
