#include"AverageScoreDisplay.h"
#include<iostream>

void AverageScoreDisplay::update(int runs, int wickets, float overs){
    this->runRate = (float)(runs/overs);
    this->predictedScore = (int)(this->runRate * 50);
}

void AverageScoreDisplay::display(){
    std::cout<<"Average Score Predictions"<<std::endl;
    std::cout<<"Run Rate: "<<this->runRate<<std::endl;
    std::cout<<"Predicted Score: "<<this->predictedScore<<std::endl;    
}