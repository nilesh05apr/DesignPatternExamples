#include"Vehicle.h"

#ifndef FourWheeler_h
#define FourWheeler_H

class FourWheeler: public Vehicle{
    public:
    FourWheeler(){};
    void printVehicle();
    ~FourWheeler() {};
};

#endif