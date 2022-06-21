#include "Date.h"
#include "Erore.h"
#include <iostream>
#include <string>
Date::Date()
{

}
bool Date::is_y(int Y)//function for checking the year of the cisse
{
	int r = Y % 33;
	return r == 1 || r == 5 || r == 9 || r == 13 || r == 17 || r == 22 || r == 26 || r == 30;
}
int Date::d_o_m(int M, int Y)//function for checking month
{
	if (M < 7)
	{
		return 31;
	}
	else if (M >= 7 && M < 12)
	{
		return 30;
	}
	else if (M == 12)
	{
		return is_y(Y) ? 30 : 29;
	}
}
//constructor and access functions of date class  :
void Date::r_d()
{
	int d1, m1, y;
	try
	{
		std::cout << "\n\n    Enter Day / month / year  :   ";
		std::cin >> d1;
		std::cin >> m1;
		std::cin >> y;
	}
	catch (Erore e1)
	{
		std::cout << "\n\n enter agian Day / month / year  :";
		std::cin >> d1, m1, y;
	}

}
void Date::setDate(int d, int m, int y)
{

	if (y < 0 || m < 1 || m>12 || d<1 || d > d_o_m(m, y))
	{
		throw Erore(" the entered data is out of range !");
	}

	day = d;
	month = m;
	year = y;

}
void Date::setD(int day)
{
	this->day = day;
}
void Date::setM(int month)
{
	this->month = month;
}
void Date::setY(int year)
{
	this->year = year;
}
int Date::getD()
{
	return day;
}
int Date::getM()
{
	return month;
}
int Date::getY()
{
	return year;
}
void Date::print()
{
	std::cout << year << "/" << month << "/" << day;
}
Date operator+(int x, Date& D)
{
	Date temp(x + D.day, D.month, D.year);
	return temp;
}
