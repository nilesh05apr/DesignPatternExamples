#include"Observer.h"
#include"CricketData.h"
#include<vector>
#include<algorithm>

CriketData::CriketData() {
    std::vector<Observer> obl;
    observerlist = obl;
}

float CriketData::getLatestOvers() {
    return 20.2;
}

int CriketData::getLatestRuns() {
    return 120;
}

int CriketData::getLatestWickets() {
    return 2;
}

void CriketData::registerObserver (Observer o) {
    observerlist.push_back(o);
}

void CriketData::unregisterObserver (Observer o) {
    std::remove(observerlist.begin(),observerlist.end(),o);
}

void CriketData::notifyObserver() {
    for(auto x: observerlist) {
        x.update(this->runs,this->wickets,this->overs);
    }
}

void CriketData::dataChanged() {
    int runs = getLatestRuns();
    int wickets = getLatestWickets();
    int overs = getLatestOvers();
    this->notifyObserver();
}