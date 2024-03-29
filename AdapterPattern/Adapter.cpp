#include<iostream>
#include<algorithm>
#include"Adaptee.h"
#include"Target.h"
#include"Adapter.h"
using namespace std;

Adapter::Adapter(Adaptee *adaptee) :adaptee_(adaptee) {};

std::string Adapter::Request() {
    std::string to_reverse = this->adaptee_->AdapteeRequest();
    std::reverse(to_reverse.begin(),to_reverse.end());
    return "From Adapter: "+to_reverse;

}