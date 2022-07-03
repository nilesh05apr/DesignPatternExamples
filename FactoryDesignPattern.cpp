#include<iostream>
using namespace std;


enum VType {
    TWOWHEELER, THREEWHEELER, FOURWHEELER
};

class Vehicle {
    // This is Base class
public:
    virtual void printVehicle() = 0;
    static Vehicle* Create(VType type);
    virtual ~Vehicle(){}
};

/*
 Multiple Inheritence

 classes TwoWheeler, ThreeWheeler, FourWheeler inheritrs 
 printVehicle function from Vehicle class

*/ 

class TwoWheeler : public Vehicle {
public:
    TwoWheeler() {}
    void printVehicle() {
        cout<<"This is Two Wheeler class"<<endl;
    }
    ~TwoWheeler() {}
};

class ThreeWheeler : public Vehicle {
public:
    ThreeWheeler() {}
    void printVehicle() {
        cout<<"This is Three Wheeler class"<<endl;
    }
    ~ThreeWheeler() {}
};

class FourWheeler : public Vehicle {
public:
    FourWheeler() {}
    void printVehicle() {
        cout<<"This is Four Wheeler class"<<endl;
    }
    ~FourWheeler() {}
};


/*
 Factory method to create objects of different types.
 Change is required only in this function to create a new object type
*/

Vehicle* Vehicle::Create(VType type) {
    switch(type){
        case TWOWHEELER: return new TwoWheeler(); break;
        case THREEWHEELER: return new ThreeWheeler(); break;
        case FOURWHEELER: return new FourWheeler(); break;
        default: return NULL; 
    }
}


class Client{
public:
    Client(){
        VType type = TWOWHEELER;
        pVehicle = Vehicle::Create(type);
    }
    ~Client(){
        if(pVehicle){
//            pVehicle->printVehicle();
            delete pVehicle;
            pVehicle = NULL;  //Safe deletion pointer
        }
    }

    Vehicle* getVehicle(){
        return pVehicle;
    }
private:
Vehicle *pVehicle;
};



int main(){
    Client *client = new Client();
    Vehicle *pv = client->getVehicle();
    pv->printVehicle();
    delete client;
    return 0;
}