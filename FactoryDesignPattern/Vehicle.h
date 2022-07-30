#ifndef Vehicle_H
#define Vehicle_H

class Vehicle {

    public:

    enum VType {
            TWOWHEELER, THREEWHEELER, FOURWHEELER
    };
    virtual void printVehicle() = 0;
    static Vehicle* Create(VType type);
    virtual ~Vehicle(){};

};

#endif