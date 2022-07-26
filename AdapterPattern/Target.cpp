#include<iostream>
#include"Target.h"
using namespace std;

// class Target{
//     public:
//     virtual std::string Request() const{
//         return "This is default Target behaviour: \n";

//     }
//     virtual ~Target() = default;

// };

std::string Target::Request(){
    return "This is Default Target behaviour: \n";
}

Target::~Target() = default;