#include "person.h"
#include "Date.h"
#include "Erore.h"
#include <iostream>
#include<cstdio>
#include <string>
//constructor and access functions of person class  :
person::person()
{

}
void person::R_data()
{

	int i;
	std::string F, L, I;
	int d, m, y;
	std::cout << "\n\n    Enter id             :   ";
	std::cin >> i;
	id = i;
	try
	{
		std::cout << "\n\n    Enter first name  :   ";
		std::cin >> F;
		for (int i = 0; i < 3; i++)
		{
			for (int i = 0; i < F.length(); i++)
			{
				if ((F[i] == 1 || F[i] == 2 || F[i] == 3 || F[i] == 4 || F[i] == 5 || F[i] == 6 || F[i] == 7 || F[i] == 8 || F[i] == 0 || F[i] == 9))
				{
					throw Erore("the name must have no number or anather charecters!");
				}
				else
				{
					break;
				}
			}
			if (F.length() > 5)
			{
				throw Erore("the name must have no more than 5 characters!");
			}
			else
			{
				break;
			}
		}

	}
	catch (Erore E1)
	{
		E1.get_massae();
		std::cout << "\n\n   enter agian name       ";
		std::cin >> F;
	}
	setname(F);
	try
	{
		std::cout << "\n\n    Enter last name      :   ";
		std::cin >> L;
		if (L.length() > 6)
		{
			throw Erore("the family must have no more than 6 characters!");
		}
		for (int i = 0; i < L.length(); i++)
		{
			if ((L[i] == 1 || L[i] == 2 || L[i] == 3 || L[i] == 4 || L[i] == 5 || L[i] == 6 || L[i] == 7 || L[i] == 8 || L[i] == 0 || L[i] == 9))
			{
				throw Erore("the family must have no number or anather charecters!");
			}
		}

	}
	catch (Erore E2)
	{
		E2.get_massae();
		std::cout << "\n\n    enter agian last name    ";
		std::cin >> L;
	}
	setfamily(L);
	try
	{
		std::cout << "\n\n    Enter ID_Code    :   ";
		std::cin >> I;
		if (I.length() > 8)
		{
			throw Erore("the ID_code must have no more than 8 characters!");
		}

	}
	catch (Erore E3)
	{
		E3.get_massae();
		std::cout << "\n\n   enter agian ID_code ";
		std::cin >> I;

	}
	setID_C(I);
	try
	{
		std::cout << "\n\n    Enter Day / month / year  :   ";
		std::cin >> d;
		std::cin >> m;
		std::cin >> y;
		Birth.setDate(d, m, y);

	}
	catch (Erore e1)
	{
		e1.get_massae();
		std::cout << "\n\n enter agian Day / month / year  :";
		std::cin >> d, m, y;
	}

}
void person::set_id(int id)
{
	this->id = id;
}
void person::setname(std::string name)
{
	this->F_name = name;
}
void person::setfamily(std::string L_name)
{
	this->L_name = L_name;
}
void person::setID_C(std::string ID_card)
{
	this->ID_card = ID_card;
}

int person::get_id()const
{
	return id;
}
std::string person::getname()const
{
	return F_name;
}
std::string person::getfamily()const
{
	return L_name;
}
std::string person::getID_C()const
{
	return ID_card;
}
Date person::getBirth()
{
	return Birth;
}
