/*
 TimeSpan.h
 Assignment2
 
 This is a header class that only has the function headers. This whole
 programs main function is to do basic arithmetic with time. Also,
 this program can convert time if its more than 60 and it will convert
 if the time is negative
 
 Created by Sung Ho Park on 10/14/19.
*/

#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <iostream>
#include <stdio.h>

using namespace std;

class TimeSpan
{
    /*
     This is the friend function. This will allow the function to
     have access to the private instance variables of the classes.
     
     Precondition: The object is not null and contains values.
     
     Postcondition: It prints out the values in the class.
     */
    friend ostream& operator<<(ostream &outStream, const TimeSpan &time);
    
private:
    //Instance variables
    double hour;
    double minutes;
    double seconds;
    
    /*
     This is a private method that helps with simplification of the
     time.
     
     Precondition: The object is made.
     
     Postcondition: It should return a simplified version of the class
     time. 
     */
    TimeSpan& simplify();
    
    
public:
    //Constructors and their parameters
    TimeSpan();
    TimeSpan(double h);
    TimeSpan(double h, double m);
    TimeSpan(double h, double m, double s);
    
    //Copy Constructor
    TimeSpan(const TimeSpan &time);
    
    //Getters for debugging purposes. 
    double getHour();
    double getMin();
    double getSec();
    
    /*
     This method overloads the + operator to add two objects
     and their private instance variables together.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: The two object's private variables are added
     together.
     */
    TimeSpan operator+(const TimeSpan &time) const;
    
    /*
     This method overloads the - operator and subtracts the two objects
     and their private instance variables.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: The two object's private variables are subtracted.
     */
    TimeSpan operator-(const TimeSpan &time) const;
    
    /*
     This method overloads the * operator and multiplies this object
     and their private instance variables to the int value.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: The object's private variables is multiplied by the
     int value.
     */
    TimeSpan operator*(int num) const;
    
    /*
     This method overloads the * operator and multiplies this object
     and their private instance variables to the int value.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: The two object's private variables are multiplied.
     */
    TimeSpan operator*(const TimeSpan &time) const;
    
    
    /*
     This method overloads the += operator and modify the existing object
     but adding this object and the object in the parameter.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: Update the current object by adding it to the
     parameter object.
     */
    TimeSpan& operator+=(const TimeSpan &time);
    
    
    /*
     This method gives you a deep copy of the time being passed in. 
     */
    TimeSpan& operator=(const TimeSpan &time);
    
    /*
     This method overloads the -= operator and modify the existing object
     but subtracting this object and the object in the parameter.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: Update the current object by subtracting it to the
     parameter object.
     */
    TimeSpan& operator-=(const TimeSpan &time);
    
    /*
     This method overloads the == operator to check if this object is
     equal to the object being passed in.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: Returns true if the objects are the same. False if
     not.
     */
    bool operator==(const TimeSpan &time) const;
    
    /*
     This method overloads the != operator to check if this object is
     not equal to the object being passed in.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: Returns true if the objects are not equal. False if
     not.
     */
    bool operator!=(const TimeSpan &time) const;
    
    /*
     This method overloads the > operator to check if the instance
     variables of this object is greater than the object being passed in.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: Returns true if this object is greater than the
     object being passed in. False if not.
     */
    bool operator>(const TimeSpan &time) const;
    
    /*
     This method overloads the < operator to check if the instance
     variables of this object is less than the object being passed in.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: Returns true if this object is less than the
     object being passed in. False if not.
     */
    bool operator<(const TimeSpan &time) const;
    
    /*
     This method overloads the >= operator to check if the instance
     variables of this object is greater than or equal to the object
     being passed in.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: Returns true if this object is greater than or equal
     to the object being passed in. False if not.
     */
    bool operator>=(const TimeSpan &time) const;
    
    /*
     This method overloads the <= operator to check if the instance
     variables of this object is less than or equal to the object
     being passed in.
     
     Precondition: The object passed in is not null and contains values.
     
     Postcondition: Returns true if this object is less than or equal
     to the object being passed in. False if not.
     */
    bool operator<=(const TimeSpan &time) const;
};

#endif /* TimeSpan_h */
