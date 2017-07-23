//
//  Teller.h
//  PM2 Project 1
//
//  Created by Mo Alhayek on 10/20/16.
//  Copyright © 2016 Mo Alhayek. All rights reserved.
//

#ifndef Teller_h
#define Teller_h


#include <queue>
#include <cstdlib>

using namespace std;

class Teller{
public:
    // default constructor and destructor
	Teller();
    ~Teller();
    
    // constructor that initializes the service rate to rate
    Teller(int rate);
    
    /** gets the teller's service rate
     @pre serviceRate is set
     @post serviceRate is returned
     */
    int getRate();
    
    /** sets the rate at which a teller services a customer
     @pre rate is > 0
     @post serviceRate is set equal to the rate at which a teller services a customer in minutes per customer
     @param rate service rate in minutes per customer
     */
    void setRate(int rate);
    
    /** gets the teller's service start time
     @pre serviceStartTime is set
     @post serviceStartTime is returned; 1 <= rate <= 60
     */
    int getServiceStartTime();
    
    /** sets the time a teller started to service a customer
     @pre t is >= 0
     @post serviceStartTime is set equal to t
     @param t time a teller started servicing a customer
     */
    void setServiceStartTime(int t);
private:
    int serviceStartTime;       // time the teller started servicing a customer
    int serviceRate;            // rate at which the teller services customers in minutes per customer
};


#endif /* Teller_h */
