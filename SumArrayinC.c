#include <stdio.h>
double sum(double data[], int size){
    double s=0.0;
    int i;
    for(i=0;i<size;++i)
        s +=data[i];
    return s;
}