#include<iostream>
#include"CurrentScoreDisplay.h"

void CurrentScoreDisplay::display() {
    std::cout<<"Current Scores "<<std::endl;
    std::cout<<"Runs: "<<runs<<std::endl;
    std::cout<<"Wickets: "<<wickets<<std::endl;
    std::cout<<"Overs: "<<overs<<std::endl;    
}

void CurrentScoreDisplay::update(int runs, int wickets, float overs) {
    this->runs = runs;
    this->wickets = wickets;
    this->overs = overs;
}