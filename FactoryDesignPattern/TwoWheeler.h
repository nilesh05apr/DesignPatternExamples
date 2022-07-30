#include"Vehicle.h"

#ifndef TwoWheeler_h
#define TwoWheeler_H

class TwoWheeler: public Vehicle{
    public:
    TwoWheeler(){};
    void printVehicle();
    ~TwoWheeler(){};
};

#endif