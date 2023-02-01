#include <iostream>
using namespace std;

enum captain
{
    Avi,
    Sid,
    Robby,
    Sami,
    Jake
};

int main(){
    captain cap = Avi;
    if (cap==Avi){
        cout << "Our captain is Avi and it's value is : " << Avi << endl;
    }
    captain capi = Sami;
    if (capi == Sami)
    {
        cout << "Our next captain is Sami and it's value is : " << Sami << endl;
    }
    return 0;
}
