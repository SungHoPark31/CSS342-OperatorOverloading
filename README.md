# CSS342-OperatorOverloading
Understanding operator overloading. Design and implement 
​TimeSpan​ class which represents a duration in hours,
minutes and seconds.

If you have a constructor that can accept double parameters, 
you do not need a separate constructor that can accept integer
parameters

You should have a private ​simplify()​ function that can simplify
any ​TimeSpan​. This function should be called after any operation
to make sure we still have valid ​TimeSpan representations.

For ​simplify​, first look at if the second is less than zero. 
If it is decrease minute by the appropriate amount to make second 
zero or a positive number. Next, check if second is greater than 59.
If it is, decrease second by the appropriate amount and increase 
minute​ (fixed 4/4) accordingly. Do the same for minute, borrowing 
or adding to hour as necessary.
