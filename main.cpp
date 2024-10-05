#include <iostream>
#include "PhotovolticPanel.hpp"
using namespace std;

int main(){
    PhotovolticPanel p1(2,3,5);
    cout<<p1.getPowerProduced()<<endl;
}