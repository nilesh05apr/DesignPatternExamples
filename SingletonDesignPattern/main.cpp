#include "Singleton.h"
#include <iostream>

Singleton *Singleton::instance = 0;

int main() {
    Singleton *s = s->getInstance();
    std::cout<<s->getData()<<std::endl;
    s->setData(10);
    std::cout<<s->getData()<<std::endl;
    return 0;
}