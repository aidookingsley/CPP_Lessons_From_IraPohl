#include <iostream>
using namespace std;
void print_banner(string s = "PohlsBerry Inc.");
int add_increment(int i, int increment = 1);
int echo(const string s, int how_many = 2);
int compute_age(int year, month mth, int birth_year = 1989, month birth_month = january);

void author_ship(string date, string version, string programmer = "Albie B. Coder"){
    cout << programmer <<endl;
    cout << "Version Number is "<< version <<endl;
    cout << date <<endl;
}
