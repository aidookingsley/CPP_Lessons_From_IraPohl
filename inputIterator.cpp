#include <iostream>
#include <fstream>
#include <numeric>
using namespace std;

int main(){
    ifstream myin("../../Desktop/enq.txt");
    istream_iterator<int> in(myin);
    istream_iterator<int> eos;
    cout << "Sum of data is " << accumulate(in, eos, 0) << endl;
}