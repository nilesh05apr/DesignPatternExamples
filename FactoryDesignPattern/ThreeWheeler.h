#include"Vehicle.h"

#ifndef ThreeWheeler_h
#define ThreeWheeler_H

class ThreeWheeler: public Vehicle{
    public:
    ThreeWheeler(){};
    void printVehicle();
    ~ThreeWheeler() {};
};

#endif