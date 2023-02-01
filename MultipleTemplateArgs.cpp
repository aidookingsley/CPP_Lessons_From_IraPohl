#include <iostream>
#include <complex>
using namespace std;

template<class T1, class T2>
void copy(const T1 source[], T2 destination[], int size){
    for (int i = 0; i < size;++i)
        destination[i] = static_cast<T2>(source[i]);
}