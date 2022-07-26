#include<iostream>
#include"Adapter.h"
#include"Target.h"
#include"Adaptee.h"
using namespace std;

void Client(Target *target) {
    std::cout<<target->Request();
}


int main(){

    std::cout<<"Client: Target Object is working fine \n";
    Target *target = new Target;
    Client(target);
    Adaptee *adaptee = new Adaptee;
    std::cout<<"Client: Adapter Interface \n";
    std::cout<<"Adaptee: "<<adaptee->AdapteeRequest();
    std::cout<<"Client: Using Adapter\n";
    Adapter *adapter = new Adapter(adaptee);
    Client(adapter);
    std::cout<<"Happy Client\n";

    return 0;
}