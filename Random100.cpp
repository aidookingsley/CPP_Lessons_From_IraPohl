#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;
int main()
{
    // RANDOM NUMBER GENERATOR
    // const int n = 100;
    // int sum = 0;

    // for (int i = 0; i < n; ++i)
    // {
    //     int number = rand() % 500;
    //     cout << number << endl;
    //     sum += number;
    // }

    // double avg = static_cast<double>(sum) / n;
    // cout << "Average of the random generated numbers: " << avg << endl;

    // A SIMPLE WAY TO GENERATE RANDOM NUMBERS THAN USING RAND
    // NUMBERS GENERATED BTN LOW AND HIGH INCLUSIVELY (RANGE)
    
    const int low = -51;
    const int high = 10;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dist(low, high);

    const int n = 100;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int number = dist(mt);
        cout << number << endl;
        sum += number;
    }

    double avg = static_cast<double>(sum) / n;
    cout << "The average of the random numbers is: " <<avg<< endl;
}