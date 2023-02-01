#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // initializer list
    // vector<int> vector1 = {1, 2, 3, 4, 5};

    // // uniform initializtion
    // vector<int> vector2{6, 7, 8, 9, 10};

    // // method 3
    // vector<int> vector3(5, 12); // same as
    // // vector<int> vector3 = {12, 12, 12, 12, 12};

    // cout << "vector1 = ";

    // // ranged loop
    // for (const int &i : vector1)
    // {
    //     cout << i << " ";
    // }

    // cout << "\nvector2 = ";

    // // ranged loop
    // for (const int& i : vector2) {
    //     cout << i << " ";
    // }

    // cout << "\nvector3 = ";

    // // ranged loop
    // for (int i : vector3)  {
    //     cout << i << " ";
    // }

    // vector<int> num{1, 2, 3, 4, 5};

    // cout << "Initial Vector: ";
    // for (const int& i : num) {
    //     cout << i << " ";
    // }
    // // add the integers 6 and 7 to the vector
    // num.push_back(6);
    // num.push_back(7);

    // cout << "\nUpdated Vector: ";
    // for (const int& i : num) {
    //     cout << i << " ";
    // }

    // vector<int> num{1, 2, 3, 4, 5};

    // cout << "Element at Index 0: " << num.at(0) << endl;
    // cout << "Element at Index 2: " << num.at(2) << endl;
    // cout << "Element at Index 4: " << num.at(4) << endl;

    // vector<int> num{1, 2, 3};
    // cout << num[1] << endl;
    // cout << num[4] << endl;
    // cout << num.at(4);

    // vector<int> num{1, 2, 3, 4, 5};
    // cout << "Initial Vector: ";
    // for (const int& i : num) {
    //     cout << i << " ";
    // }

    // //change elements at indexes 1 and 4
    // num.at(1) = 9;
    // num.at(4) = 7;

    // cout << "\nUpdated Vector: ";
    // for (const int& i : num) {
    //     cout << i << " ";
    // }

    // vector<int> prime_numbers{2, 3, 5, 7};
    // // initial vector
    // cout
    //     << "Initial Vector: ";
    // for (int i : prime_numbers)
    // {
    //     cout << i << " ";
    // }

    // // remove the last element
    // prime_numbers.pop_back();

    // // final vector
    // cout << "\nUpdated Vector: ";
    // for (int i : prime_numbers)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
    // cout << prime_numbers.size() << endl;
    // cout << prime_numbers.front() << endl;
    // cout << prime_numbers.back() << endl;
    // cout << prime_numbers.empty() << endl;
    // cout << prime_numbers.capacity() << endl;

    // vector<int> num{1, 2, 3, 4, 5};

    // // declare iterator
    // vector<int>::iterator iter;

    // // initialize the iterator with the first element
    // iter = num.begin();

    // // print the vector element
    // cout << "num[0] = " << *iter << endl;

    // // iterator points to the 3rd element
    // iter = num.begin() + 2;
    // cout << "num[2] = " << *iter << endl;

    // // iterator points to the last element
    // iter = num.end() - 1;
    // cout << "num[4] = " << *iter;

    //iterate through vector using iterators
    vector<int> num{1, 2, 3, 4, 5};

    // declare iterator
    vector<int>::iterator iter;

    // use iterator with for loop
    for (iter = num.begin(); iter != num.end(); ++iter) {
        cout << *iter << " ";
    }

        return 0;
}