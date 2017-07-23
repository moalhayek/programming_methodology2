// PM2 Project 1
// Customer.cpp
// Implementation file for Customer class

#include "Customer.h"

using namespace std;

// default constructors and destructors
Customer::Customer(){}
Customer::~Customer(){}

// constructor that initializes the time a customer arrived
Customer::Customer(int arrTime) : arrivalTime(arrTime){}

int Customer::getArrival(){
    return arrivalTime;
}

void Customer::setArrival(int arrTime){
    arrivalTime = arrTime;
}

int Customer::getQueueEnd(){
    return queueEndTime;
}

void Customer::setQueueEnd(int endTime){
    queueEndTime = endTime;
}

int Customer::getWait(){
    return waitTime;
}

void Customer::setWait(){
    // wait time is the difference between the time they left the queue and the time they entered it
    waitTime = queueEndTime - arrivalTime;
}

int Customer::getTotal(){
    return totalTime;
}
void Customer::setTotal(int tellRate){
    // total time is the wait time plus how long the teller serviced them for
    totalTime = waitTime + tellRate;
}

