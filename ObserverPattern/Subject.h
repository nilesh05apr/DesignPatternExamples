#include"Observer.h"
#ifndef Subject_H
#define Subject_h
class Subject{
    public:
    virtual void registerObserver(Observer o){}
    virtual void unregisterObserver(Observer o) {}
    virtual void notifyObserver() {}
};
#endif