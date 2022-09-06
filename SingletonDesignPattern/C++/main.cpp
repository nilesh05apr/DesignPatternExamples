#include "Singleton.h"
#include <iostream>


void client1(void) {
    Singleton::getInstance()->setData(10);
    std::cout<<"The value from client one: "<<Singleton::getInstance()->getData()<<std::endl;
}



void client2(void) {
    Singleton::getInstance()->setData(50);
    std::cout<<"The value from client two: "<<Singleton::getInstance()->getData()<<std::endl;
}

int main() {
    Singleton *s = s->getInstance();
    std::cout<<s->getData()<<std::endl;
    s->setData(10);
    std::cout<<s->getData()<<std::endl;

    client1();
    client2();
    return 0;
}