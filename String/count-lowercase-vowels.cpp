#include <iostream>
#include <string>
using namespace std;

// O(m*n)
int countLowercaseVowels(const string &str)
{
    string vowels = "aeiou";
    int count = 0;
    for (char c : str)
    {
        if (vowels.find(c) != string::npos)
        {
            count++;
        }
    }
    return count;
}

// Better Approach O(n)
int countLowercaseVowels2(const string &str)
{
    bool vowels[128] = {false};
    vowels['a'] = true;
    vowels['e'] = true;
    vowels['i'] = true;
    vowels['o'] = true;
    vowels['u'] = true;
    int counter = 0;
    for (char c : str)
    {
        if (vowels[c])
        {
            counter++;
        }
    }
    return counter;
}

// Test function
void runTests()
{
    // Test 1: Empty string
    cout << "Test 1: " << (countLowercaseVowels2("") == 0 ? "Passed" : "Failed") << endl;

    // Test 2: All vowels
    cout << "Test 2: " << (countLowercaseVowels2("aeiou") == 5 ? "Passed" : "Failed") << endl;

    // Test 3: Mixed string
    cout << "Test 3: " << (countLowercaseVowels2("hello world") == 3 ? "Passed" : "Failed") << endl;

    // Test 4: No vowels
    cout << "Test 4: " << (countLowercaseVowels2("rhythm") == 0 ? "Passed" : "Failed") << endl;

    // Test 5: Mixed case string
    cout << "Test 5: " << (countLowercaseVowels2("AeIoUaeiou") == 7 ? "Passed" : "Failed") << endl;
}

int main()
{
    cout << "Running test cases...\n";
    runTests();
    return 0;
}
