#include <iostream>
using namespace std;

template <class summable>
int main()
{
    summable sum(const summable data[], int size, summable s=0){
        for (int i = 0; i < size;++i)
            s += data[i];
        return s;
    }
}