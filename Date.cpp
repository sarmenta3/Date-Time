// Date.cpp
// Date class member-function definitions.
#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition
#include "Time.h"// include Time class definition
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(int mn, int dy, int yr, Time t)
:Time(t) // set class Time constructor
{
	if (mn > 0 && mn <= monthsPerYear) // validate the month
		month = mn;
	else
		throw invalid_argument("month must be 1-12");

	year = yr; // could validate yr
	day = checkDay(dy); // validate the day
	// output Date object to show when its constructor is called
	cout << "Date object constructor for date "; //inform user in contructor
	print();  // print user data
	cout << endl;
} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
	//print the date and time
	cout << month << '/' << day << '/' << year << "    ";  printStandard(); cout << "     ";
	printUniversal();
} // end function print

//increaseADay Function : increments day, and checks that day is with in months bounds
void Date::increasADay() {
	try {
		checkDay(++day); //check that day is within mounths bounds
	}//end try
	catch (...) {  //invalid argument caught if days exceed months bounds
		cout << "day (" << day << ")" << " set to 1. " << endl;
		day = 1; // set day to 1
		month++;  // increment month

		//check month does not exceed 12
		if (month > 12) {
			month = 1; // set month to 1 if > 12
			year++; //increment year
		}//end month if
	}//end catch
}//end increaseADay function

void Date::tick() {
	//working with class Time functions
	int s = getSecond(); //set s to seconds
	int m = getMinute();//set m to minutes
	int h = getHour();//set h to hour
	s++; //increment second

	//insure second is less than 60
	if (s > 59)
	{
		s = 0; //set s to 0
		m++; //increment months

		//nested minute if: insure minute is less than 60
		if (m > 59)
		{
			m = 0; //set m to 0
			h++; //increse hour

			//nested hour if: insure hour is less than 24
			if (h > 23) {
				h = 0; // set hour to 12 am
				increasADay(); //increase day via increaseADay function
			}//end of hour if
		}//end of minute if
	}//end second if

	setSecond(s); //Set Class Time Seconds
	setMinute(m); //Set Class Time minutes
	setHour(h);  //Set Class Time hour
	setTime(getHour(), getMinute(), getSecond()); //Set class Time setTime Function
}//end tick function

// output Date object to show when its destructor is called
Date::~Date()
{
	cout << "Date object destructor for date "; //inform user destructor called
	print();  // print all data
	cout << endl;
} // end ~Date destructor

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay(int testDay) const
{
	static const array< int, monthsPerYear + 1 > daysPerMonth =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;

	// February 29 check for leap year 
	if (month == 2 && testDay == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		return testDay;

	throw invalid_argument("Invalid day for current month and year");
} // end function checkDay