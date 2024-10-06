#include <iostream>
#include "PhotovoltaicPanel.hpp"
using namespace std;

int main(){
    PhotovoltaicPanel p1(2,3,5);
    cout<<p1.getPowerProduced()<<endl;
}