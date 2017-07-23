// PM2 Project 1
// Teller.cpp
// Implementation file for Teller class


#include "Teller.h"

using namespace std;

Teller::Teller(){}
Teller::~Teller(){}

Teller::Teller(int rate) : serviceRate(rate){}

int Teller::getRate(){
    return serviceRate;
}

void Teller::setRate(int rate){
    serviceRate = rate;             // minutes per customer
}

int Teller::getServiceStartTime(){
    return serviceStartTime;
}
void Teller::setServiceStartTime(int t){
    serviceStartTime = t;
}
