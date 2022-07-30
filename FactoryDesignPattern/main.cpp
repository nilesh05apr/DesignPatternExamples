#include"Vehicle.h"
#include"TwoWheeler.h"
#include"ThreeWheeler.h"
#include"FourWheeler.h"
#include<iostream>
using namespace std;


class Client{
public:
    Client(){
        auto type = Vehicle::VType::TWOWHEELER;
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