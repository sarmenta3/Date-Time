// Date.h 
// Date class definition; Member functions defined in Date.cpp
#ifndef DATE_H
#define DATE_H
#include "Time.h" // include class Time
class Date : public Time // inherit class Time
{
public:

	static const unsigned int monthsPerYear = 12; // months in a year
	explicit Date(int = 1, int = 2, int = 1900, Time  t = time);//default constructor
	void print() const; // print date in month/day/year format
	void increasADay(); //increment day and chech day is within months bounds
	void tick(); // increment second and chech all time variables increment accordingly
	~Date(); // provided to confirm destruction order
private:

	unsigned int month; // 1-12 (January-December)
	unsigned int day; // 1-31 based on month
	unsigned int year; // any year
	Time static time; //Time compound variable
	// utility function to check if day is proper for month and year
	unsigned int checkDay(int) const; // chech day
}; // end class Date

#endif


