/*
  assignment2.cpp
  Assignment2

  This is a tester class and the main purpose of this is to
  test specific cases.
 
  Created by Sung Ho Park on 10/15/19.
  Copyright © 2019 Sung Ho Park. All rights reserved.
*/

#include <stdio.h>
#include <iostream>

#include <sstream>
#include <cassert>

#include "timespan.h"

using namespace std;

// testing constructor

void test1()
{
    TimeSpan ts(1, 20, 30);
    stringstream ss;
    ss << ts;
    cout << ss.str() << endl;
    assert(ss.str() == "1:20:30");
    
    cout << endl;
    
    TimeSpan ts2(4, -20, -90);
    ss.str("");
    ss << ts2;
    cout << ss.str() << endl;
    assert(ss.str() == "3:38:30");

    cout << endl;
    
    TimeSpan ts3(1.5, 30.5, -90);
    ss.str("");
    ss << ts3;
    cout << ss.str() << endl;
    assert(ss.str() == "1:59:00");
    
    cout << endl;
    
    TimeSpan ts4(0, 0.07, 0);
    ss.str("");
    ss << ts4;
    cout << ss.str() << endl;
    assert(ss.str() == "0:00:04");
    
    cout << endl;
}

// testing equality, addition, subtraction, multiplication

void test2()
{
    TimeSpan ts(1, 20, 30);
    TimeSpan ts2(1, 20, 30);
    TimeSpan ts3(0, 0, 0);

    assert(ts == ts2);
    assert(!(ts != ts2));
    assert(ts != ts3);
    assert((ts + ts + ts) == (ts2 * 3));
    assert((ts * 5) == (ts2 * 4) + ts2);
    assert((ts * 5) == (ts2 * 6) - ts2);
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    assert((ts - ts2) == ts3);
    assert((ts3 * 5) == ts3);
}

//Testing for comparison

void test3()
{
    TimeSpan t1(2, 5, 70);
    TimeSpan t2(2, 4, 70);
    TimeSpan t3(4, 4, 70);
    TimeSpan t4(4, 4, 20);
    TimeSpan t5(4, 4, 20);
    TimeSpan t6(0, 01, -10);
    TimeSpan t7(0, 00, 50);
    
    TimeSpan t8(1, 4, 0);
    TimeSpan t9(1, 4, 8);
    
    assert(t1 > t2);
    assert(t1 >= t2);
    assert(t2 < t3);
    assert(t2 <= t3);
    assert(t3 > t4);
    assert(t3 >= t4);
    assert(t4 >= t5);
    assert(t4 <= t5);
    assert(t6 == t7);
    assert(!(t6 != t7));
    assert(t8 < t9);
}

//Testing negatives.
void test4()
{
    TimeSpan ts(-4, -70, -30);
    cout << ts << endl;
    
    TimeSpan ts2(-4, -70, -30);
    cout << ts2 << endl;
    
    TimeSpan ts3(0, 0, 0);
    cout << ts3 << endl;
    
    assert(ts == ts2);
    assert(!(ts != ts2));
    assert(ts != ts3);
    assert((ts + ts + ts) == (ts2 * 3));
    assert((ts * 5) == (ts2 * 4) + ts2);
    assert((ts * 5) == (ts2 * 6) - ts2);
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    assert((ts - ts2) == ts3);
    assert((ts3 * 5) == ts3);
    
    
    //Copy using assignment
    ts3 = ts2;
    assert(ts3 == ts);
    
    TimeSpan ts4(ts3);
    assert(ts4 == ts3);
    
}

void testAll()
{
    test1();
    test2();
    test3();
    test4();
}

int main()
{
    testAll();
    cout << "Done." << std::endl;
    return 0;
}
