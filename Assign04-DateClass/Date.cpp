#include "stdafx.h"
#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

Date::Date()
{
	setDefaultDate();
}


Date::Date(int m, int d, int y)
{
	setDate(m, d, y);
}

void Date::setDate(int mm, int dd, int yyyy)
{
	month = mm;
	day = dd;
	year = yyyy;
	if (!validDate())
		setDefaultDate();
}

void Date::setDefaultDate()
{
	month = 01;
	day = 01;
	year = 1970;
}

int Date::getMonth()	const		//return integer value of month
{
	return month;
}

int Date::getDay()		const		//return integer value of day
{
	return day;
}

int Date::getYear()		const		//return integer value of year
{
	return year;
}

void Date::displayDate()	const
{
	cout << endl << fixed << setw(2) << month << "/" << setw(2) << day << "/" << setw(4) << year << endl;
}

bool Date::validMonth()		const
{
	bool result = false;

	if (month >= 1 && month <= 12)
	{
		result = true;
	}

	return result;
}
bool Date::validDay()		const
{
	bool result = false;
	int maxDays = 31;

	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		maxDays = 30;
	}
	else
	{
		if (month == 2)
		{
			maxDays = 28;
			if (year % 4 == 0)
			{
				maxDays = 29;
				if (year % 100 == 0)
				{
					maxDays = 28;
					if (year % 400 == 0)
					{
						maxDays = 29;
					}
				}
			}
		}	
	}
	
	if (day > 0 && day <= maxDays)
	{
		result = true;
	}

	return result;
}

bool Date::validYear()			
{
	bool result = false;
	
	if (year >= 0)
	{
		if (year < 100)
		{
			if (year > 30 && year < 100)
			{
				year += 1900;
			}
			else if (year < 30)
			{
				year += 2000;
			}
		}
		result = true;
	}
	return result;
}
bool Date::validDate()
{
	return validYear() && validMonth() && validDay();
}

