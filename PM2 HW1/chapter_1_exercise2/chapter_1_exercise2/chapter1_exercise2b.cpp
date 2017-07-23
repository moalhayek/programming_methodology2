// Mhammed Alhayek Homework 1: Chapter 1 Exercise 2

#include <iostream>

using namespace std;

class Date{
public:
    Date(int m = 7, int d = 4, int y = 1776){       // creating a constuctor for the class
        year = y;
        
        // check that they entered correct amount of months
        if ( m > 0 && m<= 12)
            month = m;
        else
            throw invalid_argument("month must be 1-12");

        // check that number of days is valid
        day = checkDay(d);
    }
    
    // function that checks that the day makes sense with the month
    int checkDay( int testDay ) {
        static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        
        if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
            return testDay;
        
        if ( month == 2 && testDay == 29 && ( isLeapYear(year) ) )
            return testDay;
        
        throw invalid_argument( " Invalid day for current month and year" );
        
    }
    // get and set functions for variables
    int getMonth(){
        return month;
    }
    void setMonth(int m){
        month = m;
    }
    int getDay(){
        return day;
    }
    void setDay(int d){
        day = d;
    }
    int getYear(){
        return year;
    }
    void setYear(int y){
        year = y;
    }
    
    // function that displays the date
    void displayDate(){
        cout << "The Date is " << month << "/" << day << "/" << year << endl;
    }
    
    
    Date advanceDay(){
        // if end of year, advance year
        if (month == 12 && day == 31){
            year++;
            day = 1;
            month = 1;
            
            return Date(month,day,year);
        }
        // if end of month, advance month
        
        // advance month after day 31 for days with 31 days
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30){
            month++;
            day = 1;
            
            return Date(month,day,year);
        }
        
        // advance February
        else if (month == 2){
            // advance after day 29 for leap years
            if (isLeapYear(year)){
                if (day == 28){
                    day++;
                    
                    return Date(month,day,year);
                }
                else if (day == 29){
                    month++;
                    day = 1;
                    
                    return Date(month,day,year);
                }
            }
            // advance after day 28 for regular years
            else if (day == 28){
                month++;
                day = 1;
            
            return Date(month,day,year);
            }
        }
        
        // advance month after day 31 for months with 31 days
        else if (day == 31){
            month++;
            day = 1;
            
            return Date(month,day,year);
        }
        
        // advance the day for all other cases
        else{
            day++;
            
            return Date(month,day,year);
        }
        
        return Date(month,day,year);
    }
    
    // The purpose of this method is to check if the year is a leap year.
    // precondition: y is an int that is the year of the Date.
    // postcondition: whether or not y is a leap year is determined
    // return value: the function will return a boolean variable which is only true if y is a leap year.
    bool isLeapYear(int y)
    {
        if (y % 4 != 0)
            return false;
        if (y % 100 != 0)
            return true;
        if (y % 400 == 0)
            return true;
        else
            return false;
    }
private:
    int month;
    int day;
    int year;
};

int main(int argc, const char * argv[]){
    
    Date myDate(12,28,2016);
    
    myDate.advanceDay();
    
    myDate.displayDate();
    
    myDate.advanceDay();
    
    myDate.displayDate();

    myDate.advanceDay();
    
    myDate.displayDate();

    myDate.advanceDay();
    
    myDate.displayDate();

    
    return 0;
}
