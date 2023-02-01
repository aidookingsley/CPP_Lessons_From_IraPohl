#include <iostream>
using namespace std;

enum Supercars
{
    Venom_F5=301, Veryon=268, Valkyrie=240, Roadster=250
};

int main(){
    Supercars speed1;
    Supercars speed2;

    speed1 = Valkyrie;
    speed2 = Roadster;

    if(speed1<speed2){
        cout << "It's a win for Roadster with the speed of " << speed2;
    }
    else{
        cout << "It's a win for Valkyrie with the speed of " << speed1;
    }
}