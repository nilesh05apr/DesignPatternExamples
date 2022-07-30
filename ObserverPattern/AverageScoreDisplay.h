#include"Observer.h"
#ifndef AverageScoreDisplay_H
#define AverrageScoreDisplay_H
class AverageScoreDisplay: virtual public Observer {
    private:
        int predictedScore;
        float runRate;
    public:
        void update(int runs, int wickets, float overs);
        void display();
};
#endif