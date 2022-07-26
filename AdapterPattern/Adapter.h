#include<iostream>
#include"Target.h"
#include"Adaptee.h"
using namespace std;

class Adapter: public Target{
    private:
    Adaptee *adaptee_;

    public:
    Adapter(Adaptee *adaptee);

    string Request() override;
};