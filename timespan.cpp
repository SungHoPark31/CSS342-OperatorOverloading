/*
  timespan.cpp
  Assignment2

  This is the cpp / implementation of the header file.
 
  Created by Sung Ho Park on 10/14/19.
  Copyright © 2019 Sung Ho Park. All rights reserved.
*/

#include <stdio.h>
#include "timespan.h"
#include <iostream>
#include <iomanip>


using namespace std;

TimeSpan::TimeSpan()
{
    hour = 0;
    minutes = 0;
    seconds = 0;
}

TimeSpan::TimeSpan(double h)
{
    hour = h;
    minutes = 0;
    seconds = 0;
    this->simplify();
}

TimeSpan::TimeSpan(double h, double min)
{
    hour = h;
    minutes = min;
    seconds = 0;
    this->simplify();
}

TimeSpan::TimeSpan(double h, double min, double sec)
{
    hour = h;
    minutes = min;
    seconds = sec;
    this->simplify();
}

TimeSpan::TimeSpan(const TimeSpan &time)
{
    hour = time.hour;
    minutes = time.minutes;
    seconds = time.seconds;
    this->simplify();
}

double TimeSpan::getHour()
{
    return hour;
}

double TimeSpan::getMin()
{
    return minutes;
}

double TimeSpan::getSec()
{
    return seconds;
}

TimeSpan& TimeSpan::simplify()
{
    //Convert everything to seconds
    double secondHour = hour * 3600;
    double secondMinutes = minutes * 60;
    int secondSecond = seconds;
       
    //Add them all together to get the total seconds
    int totalSeconds = (int) secondHour +
                (int) secondMinutes + secondSecond;
       
    //1 hour is 3600 seconds so divide the total seconds by 3600
    //to get the hour.
    hour = totalSeconds / 3600;
    
    //To get minutes, you need to get the remainder of the hour. 
    int remainingHour = totalSeconds % 3600;
    
    //You only have remainder of the hour, so divide by 60 to get
    //the actual minutes
    minutes = remainingHour / 60;
    
    //To get the seconds of the remainder of the hour, get the remainder
    //of remainingHour divided by 60.
    seconds = remainingHour % 60;

    return *this;
}

TimeSpan TimeSpan::operator+(const TimeSpan &time) const
{
    //Create a temporary object.
    TimeSpan temp;
    
    //add this objects instance variables with the time instance
    //variables.
    temp.hour = hour + time.hour;
    temp.minutes = minutes + time.minutes;
    temp.seconds = seconds + time.seconds;
    
    //After that, simplify the temporary variables.
    temp.simplify();
    
    //Return the temporary object.
    return temp;
}

TimeSpan TimeSpan::operator-(const TimeSpan &time) const
{
    //Create a temporary object.
    TimeSpan temp;
    
    //subtract this objects instance variables with the time instance
    //variables.
    temp.hour = hour - time.hour;
    temp.minutes = minutes - time.minutes;
    temp.seconds = seconds - time.seconds;
    
    //After that, simplify the temporary variables.
    temp.simplify();
    
    //Return the temporary object.
    return temp;
}

TimeSpan TimeSpan::operator*(int num) const
{
    //Create a temporary object.
    TimeSpan temp;
    
    //Multiply this objects instance variables with the int
    //value
    temp.hour = hour * num;
    temp.minutes = minutes * num;
    temp.seconds = seconds * num;
    
    //After that, simplify the temporary variables.
    temp.simplify();
    
    //Return the temporary object.
    return temp;
}

TimeSpan TimeSpan::operator*(const TimeSpan &time) const
{
    //Create a temporary object.
    TimeSpan temp;
    
    //subtract this objects instance variables with the time instance
    //variables.
    
    temp.hour = hour * time.hour;
    temp.minutes = minutes * time.minutes;
    temp.seconds = seconds * time.seconds;
    
    //After that, simplify the temporary variables.
    temp.simplify();
    
    //Return the temporary object.
    return temp;
}

TimeSpan& TimeSpan::operator=(const TimeSpan &time)
{
    //Set all the variables to the object being passed in.
    hour = time.hour;
    minutes = time.minutes;
    seconds = time.seconds;
    
    //After that, simplify the variables.
    simplify();
    
    //Return the temporary object.
    return *this;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &time)
{
    //Update each time by adding the variables together.
    hour += time.hour;
    minutes += time.minutes;
    seconds += time.seconds;
    
    //simplify this object's variables.
    simplify();
    
    //Since this is a pointer, dereference it to return it.
    return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan &time)
{
    //Update each time by adding the variables together.
    hour -= time.hour;
    minutes -= time.minutes;
    seconds -= time.seconds;
    
    //simplify this object's variables.
    simplify();
    
    //Since this is a pointer, dereference it to return it.
    return *this;
}

bool TimeSpan::operator==(const TimeSpan &time) const
{
    //If each individual variable equals one another, then return
    //true.
    if(this->hour == time.hour && this->minutes == time.minutes
       && this->seconds == time.seconds)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TimeSpan::operator!=(const TimeSpan &time) const
{
    //Even if one of the variables is not equal to each other,
    //return true because they don't equal each other.
    if(this->hour != time.hour || this->minutes != time.minutes
       || this->seconds != time.seconds)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TimeSpan::operator<=(const TimeSpan &time) const
{
    //Even if one of the variables in this object is less than
    //or equal to the other object, return true.
    if(this->hour <= time.hour || this->minutes <= time.minutes
       || this->seconds <= time.seconds)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TimeSpan::operator>=(const TimeSpan &time) const
{
    //Even if one of the variables is greater than or equal to
    //each other.
    if(this->hour >= time.hour || this->minutes >= time.minutes
       || this->seconds >= time.seconds)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TimeSpan::operator>(const TimeSpan &time) const
{
    //Even if one of the variables is greater than
    //the other object, return true.
    if(this->hour > time.hour || this->minutes > time.minutes
       || this->seconds > time.seconds)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TimeSpan::operator<(const TimeSpan &time) const
{
    //Even if one of the variables in this object is less than
    //the other object, return true.
    if(this->hour < time.hour || this->minutes < time.minutes
       || this->seconds < time.seconds)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream &operator<<(ostream &outStream, const TimeSpan &time)
{
    //Not necessary, but it'll save doing time.instanceVariable
    //over and over again.
    int h = time.hour;
    int m = time.minutes;
    int s = time.seconds;
    
    //If hour is less than zero and both the min and the seconds are
    //less than -10
    if(h < 0 && m < -10 && s < -10)
    {
        return outStream << "-" << h  * -1
                        << ":" << m * -1 << ":" << s * -1;
    }
    
    //If hour is less than zero and both the minutes are equal to zero
    if(h < 0 && m == 0 && s == 0)
    {
        return outStream << "-" << h  * -1 << ":00:00";
    }
    
    //If hour is less than zero, the minutes is in between zero and
    // -10, the seconds is equal to zero
    if(h < 0 && (m < 0 && m > -10) && s == 0)
    {
        return outStream << "-" << h * -1 << ":0" << m * -1 << ":00";
    }
    
    //If hour is less than zero, the seconds is in between zero and
    // -10, the minutes is equal to zero
    if(h < 0 && m == 0 && (s < 0 && s > -10))
    {
        return outStream << "-" << h * -1 << ":00:0" << s * -1;
    }
    
    //If hour is less than zero and both the minute and seconds is
    //in between 0 and -10.
    if(h < 0 && (m < 0 && m > -10) && (s < 0 && s > -10))
    {
        return outStream << "-" << h * -1<< ":0" << m * -1 << ":0" << s * -1;
    }
    
    //If hour is zero and both minutes and seconds is less than -10
    if(h == 0 && m < -10 && s < -10)
    {
        return outStream << "-0:" << m * -1 << ":" << s * -1;
    }
    
    //If hour is zero, minutes is in between zero and -10, and seconds
    //is zero
    if(h == 0 && (m < 0 && m > -10) && s == 0)
    {
        return outStream << "-0:0" << m * -1 << ":00";
    }
    
    //If hour is zero and both minutes and seconds is in between zero
    //and -10
    if(h == 0 && (m < 0 && m > -10) && (s < 0 && s > -10))
    {
        return outStream << "-0:0" << m * -1 << ":0" << s * -1;
    }
    
    //If all the time is zero.
    if(h == 0 && m == 0 && s == 0)
    {
        return outStream << "0:00:00";
    }
    
    
    //Output the outStream if both min and sec are 0.
    if(m == 0 && s == 0)
    {
        return outStream << h << ":00:00";
    }
    
    //if not, then output the outStream if min is 0 and sec is
    //less than 10.
    if((m == 0) && (s < 10 && s >= 0))
    {
        return outStream << h << ":00:0" << s;
    }
    
    //if not, then output the outStream if min is 0.
    if(m == 0)
    {
        return outStream << h << ":00:" << s;
    }
    
    //if not, then output the outStream if min is less than 0
    if(m >= 0 && m < 10)
    {
        return outStream << h << ":0" << m << ":" << s;
    }
    
    //if not, then output the outStream if sec is
    //less than 10.
    if(s >= 0 && s < 10)
    {
        return outStream << h << ":" << m << ":0" << s;
    }
    
    //if not, then output the outStream if sec is 0
    if(s == 0)
    {
        return outStream << h << ":" << m << ":00";
    }
       
    //If none of the conditions are met, then print out the
    //time. 
    return outStream << h << ":" << m << ":" << s;
}
