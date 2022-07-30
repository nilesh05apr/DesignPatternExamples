#include"Vehicle.h"
#include"TwoWheeler.h"
#include"ThreeWheeler.h"
#include"FourWheeler.h"
#include<iostream>

Vehicle* Vehicle::Create(VType type) {
    switch(type){
        case Vehicle::VType::TWOWHEELER: return new TwoWheeler(); break;
        case Vehicle::VType::THREEWHEELER: return new ThreeWheeler(); break;
        case Vehicle::VType::FOURWHEELER: return new FourWheeler(); break;
        default: return NULL; 
    }
}
