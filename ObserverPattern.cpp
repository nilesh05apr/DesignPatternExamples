#include <iostream>
#include <vector>
using namespace std;

class Observer {
    public:
    virtual void update(int runs, int wickets, float overs){}
};

class Subject {
    public:
    virtual void registerObserver(Observer o){}
    virtual void unregisterObserver(Observer o) {}
    virtual void notifyObserver() {}
};


class CricketData: virtual public Subject {
    public:
        CricketData(){
            vector<Observer> observerlist;
        }
        void registerObserver(Observer o){
            observerlist.push_back(o);
        }
        void unregisterObserver(Observer o){
            observerlist.pop_back();
        }
        void notifyObserver(){
            for(auto x : observerlist){
                x.update(this->runs,this->wickets,this->overs);
            }
        }
        void dataChanged() {
            int runs = getLatestRuns();
            int wickets = getLatestWickets();
            float overs = getLatestOvers();
            this->notifyObserver();
        }


    private:
    
        int runs;
        int wickets;
        float overs;
        vector <Observer> observerlist;

        int getLatestRuns() {return 100;}
        int getLatestWickets() {return 2;}
        float getLatestOvers() {return (float)10.2;}    
};


class AverageScoreDisplay : virtual public Observer {
    private:
        float runRate;
        int predictedScore;
    public:
        void update(int runs, int wickets, float overs){
            this->runRate = (float)runs/overs;
            this->predictedScore = (int) (this->runRate * 50);
            this->display();
        }
        void display(){
            cout<<"Average Score Predictions"<<endl;
            cout<<"Run Rate: "<<this->runRate<<endl;
            cout<<"Predicted Score: "<<this->predictedScore<<endl;
        }
};

class CurrentScoreDisplay: virtual public Observer {
    private:
        int runs, wickets;
        float overs;
    public:
        void display(){
            cout<<"Current Scores "<<endl;
            cout<<"Runs: "<<runs<<endl;
            cout<<"Wickets: "<<wickets<<endl;
            cout<<"Overs: "<<overs<<endl;
        }
        void update(int runs, int wickets, float overs){
            this->runs = runs;
            this->wickets = wickets;
            this->overs = overs;
            this->display();
        }

};



int main(){
        AverageScoreDisplay averageScoreDisplay;
        CurrentScoreDisplay currentScoreDisplay;
  
        // pass the displays to Cricket data
        CricketData cricketData;
  
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