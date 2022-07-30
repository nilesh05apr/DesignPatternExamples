#include<iostream>
#include"Observer.h"
#include"Subject.h"
#include"AverageScoreDisplay.h"
#include"CurrentScoreDisplay.h"
#include"CricketData.h"


int main() {
    AverageScoreDisplay averageScoreDisplay;
    CurrentScoreDisplay currentScoreDisplay;

    // pass the displays to Cricket data
    CriketData cricketData;

    // register display elements
    cricketData.registerObserver(averageScoreDisplay);
    cricketData.registerObserver(currentScoreDisplay);

    // call this function when data changes
    cricketData.dataChanged();

    //remove an observer
    cricketData.unregisterObserver(averageScoreDisplay);

    // now only currentScoreDisplay gets the
    // notification
    cricketData.dataChanged();

    return 0;
}