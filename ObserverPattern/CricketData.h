#include"Observer.h"
#include<vector>
#include"Subject.h"
#ifndef CricketData_H
#define CriketData_H

class CriketData: public Subject {
    private:    
        int runs;
        int wickets;
        float overs;
        std::vector <Observer> observerlist;

        int getLatestRuns();
        int getLatestWickets(); 
        float getLatestOvers();   

    public:
        CriketData(); 
        void registerObserver(Observer o) override;
        void unregisterObserver(Observer o) override;
        void notifyObserver() override;
        void dataChanged();

};

#endif