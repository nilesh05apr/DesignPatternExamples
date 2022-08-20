#include "Singleton.h"
#include <iostream>

Singleton::Singleton(){
    data = 0;
}

static Singleton Singleton::*getInstance(){
    if(!(this->instance)){
        this->instance = new Singleton;
        return instance;
    }
}

int Singleton::getData() {
    return this->data;
}

void Singleton::setData(int data) {
    this->data = data;
}