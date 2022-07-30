#include"Observer.h"
#include<iostream>

#ifndef CurrentScoreDisplay_H
#define CurrentScoreDisplay_H
class CurrentScoreDisplay: virtual public Observer {
    private:
        int runs,wickets;
        float overs;
    public:
        void update(int runs,int wickets,float overs);
        void display();
};
#endif