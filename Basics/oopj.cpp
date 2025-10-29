#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
using namespace std;

class Student
{
    string name;
    int age;
    int favNum;

public:
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void getStudent()
    {
        cout << "Student name is: " << this->name << " age is: " << this->age << endl;
    }

private:
    void wassup(int something)
    {
        favNum = something;
    }
    void greet()
    {
        cout << "Hello There" << endl;
    }
};

int main()
{
    Student s1("suman", 23);
    s1.getStudent();

    Student s2("raghav", 45);
    s2.getStudent();
    // cout << std::type_name(s1) << endl;
    // int status;
    // string demangled = abi::__cxa_demangle(typeid(s1).name(), 0, 0, &status);
    // cout << demangled << endl;

    return 0;
}