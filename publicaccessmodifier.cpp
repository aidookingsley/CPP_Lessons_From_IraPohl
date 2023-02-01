// Example 1 : C++ public Access Modifier
#include <iostream>
using namespace std;

// // define a class
// class Sample {

//     // public elements
//     public:
//         int age;

//         void displayAge() {
//             cout << "Age = " << age << endl;
//         }
// };

// int main() {
//     // declare a class object
//     Sample obj1;

//     cout << "Enter your age: ";

//     // store input in age of the obj1 object
//     cin >> obj1.age;

//     // calls class function
//     obj1.displayAge();

//     return 0;
// }

// Example 2: C++ private Access Specifier

// define a class
// class Sample
// {

//     // private elements
// private:
//     int age;

//     // public elements
// public:
//     void displayAge(int a)
//     {
//         age = a;
//         cout << "Age = " << age << endl;
//     }
// };

// int main()
// {
//     int ageInput;

//     // declare an object
//     Sample obj1;

//     cout << "Enter your age: ";
//     cin >> ageInput;

//     // call function and pass ageInput as argument
//     obj1.displayAge(ageInput);
// }

// Example 3: C++ protected Access Specifier

// declare parent class
class Sample
{
    // protected elements
protected:
    int age;
};

// declare child class
class SampleChild : public Sample
{

public:
    void displayAge(int a)
    {
        age = a;
        cout << "Age = " << age << endl;
    }
};

int main()
{
    int ageInput;

    // declare object of child class
    SampleChild child;

    cout << "Entter your age: ";
    cin >> ageInput;

    // call child class function
    // pass ageInput as argument
    child.displayAge(ageInput);

    return 0;
}