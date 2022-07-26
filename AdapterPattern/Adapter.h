#include"Target.h"
#include"Adaptee.h"

#ifndef Adapter_H
#define Adapter_H
class Adapter: public Target{
    private:
    Adaptee *adaptee_;

    public:
    Adapter(Adaptee *adaptee);

    std::string Request() override;
};
#endif