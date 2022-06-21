#include "Book.h"
#include "Erore.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
//constructorand access functions of father class of writings  :
Book::Book()
{
}
Book::Book(std::string ID, std::string Title, std::string p_count)
{
	this->ID = ID;
	this->Title = Title;
	this->p_count = p_count;
}
void Book::setData()
{
	std::string I, C, P;
	std::cout << "\n\n  enter ID : ";
	std::cin >> I;
	set_ID(I);

	std::cout << "\n\n    Enter Caption      :   ";
	std::cin >> C;
	setTitle(C);

	std::cout << "\n\n    Enter Number of pages of book (or text )     :   ";
	std::cin >> P;
	setp_count(P);

}
void Book::set_ID(std::string ID)
{
	this->ID = ID;
}
void Book::setTitle(std::string Title)
{
	this->Title = Title;
}
void Book::setp_count(std::string p_count)
{
	this->p_count = p_count;
}

std::string Book::get_ID()const
{
	return ID;
}
std::string Book::getTitle()const
{
	return Title;
}
std::string Book::getp_count()const
{
	return p_count;
}
