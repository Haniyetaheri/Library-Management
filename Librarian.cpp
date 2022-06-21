#include "person.h"
#include "Librarian.h"
#include "Date.h"
#include "Erore.h"
#include <iostream>
#include<cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
//constructorand access functions of Librarian class :
Librarian::Librarian() :person()
{
}
void Librarian::r_data1()
{
	std::string P, Do;

	std::cout << "\n\n    Enter post      :   ";
	std::cin >> P;
	posta = P;
	std::cout << "\n\n    Enter Doucument     :   ";
	std::cin >> Do;
	Doucu = Do;

}
void Librarian::setDoucu(std::string Doucu)
{
	this->Doucu = Doucu;
}
void Librarian::setposta(std::string  posta)
{
	this->posta = posta;
}
std::string Librarian::getDouc()const
{
	return Doucu;
}
std::string Librarian::getposta()const
{
	return posta;
}
////////////
std::vector<Librarian>list_L, list_L2;
std::ofstream file_L;
void Librarian::Add1()//add new Librarian
{
	Librarian l;
	Date d;
	l.r_data1();
	l.R_data();

	d = l.Birth;
	int d1, m1, y1;
	d1 = d.getD();
	m1 = d.getM();
	y1 = d.getY();
	file_L.close();

	list_L.push_back(l);
	std::ofstream file_L("Librarians.txt", std::ios::app);
	if (!file_L)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	file_L << std::endl << l.id << "   " << l.F_name << "   " << l.L_name << "   " << l.ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << l.Doucu << "   " << l.posta << std::endl;

	file_L.close();

}
void Librarian::Edit1(int iid)//edit the information of Librarian
{
	std::ifstream file_L("Librarians.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	int e;
	int e4, e5, e6;
	std::string e1, e2, e3, e7, e8;
	int g = 0;
	if (!file_L)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_L.eof())
	{
		file_L >> e;
		file_L >> e1;
		file_L >> e2;
		file_L >> e3;
		file_L >> e4;
		file_L >> e5;
		file_L >> e6;
		file_L >> e7;
		file_L >> e8;

		Date D(e4, e5, e6);
		Librarian l(e, e1, e2, e3, D, e7, e8);
		list_L.push_back(l);

	}
	std::string L1, L2, L3, L4, L5;
	int a;

	for (int i = 0; i < list_L.size(); i++)
	{
		if (list_L[i].id == iid)
		{
			if (g != 1)
			{
				std::cout << "    Edit   menue       \n  ";
				std::cout << "    1: ID_code         \n  ";
				std::cout << "    2: name            \n  ";
				std::cout << "    3: family          \n  ";
				std::cout << "    4:post             \n  ";
				std::cout << "    5:Document         \n  ";
				std::cin >> a;
				if (a == 1)
				{
					std::cout << "\n    enter ID_code         : ";
					std::cin >> L1;
					list_L[i].setID_C(L1);
					Date d;
					d = list_L[i].Birth;
					int d1, m1, y1;
					d1 = d.getD();
					m1 = d.getM();
					y1 = d.getY();
					temp << list_L[i].id << "   " << list_L[i].F_name << "   " << list_L[i].L_name << "   " << list_L[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_L[i].Doucu << "   " << list_L[i].posta << std::endl;
					g = 1;
				}
				else if (a == 2)
				{
					std::cout << "\n    enter name            : ";
					std::cin >> L2;
					list_L[i].setname(L2);
					Date d;
					d = list_L[i].Birth;
					int d1, m1, y1;
					d1 = d.getD();
					m1 = d.getM();
					y1 = d.getY();
					temp << list_L[i].id << "   " << list_L[i].F_name << "   " << list_L[i].L_name << "   " << list_L[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_L[i].Doucu << "   " << list_L[i].posta << std::endl;
					g = 1;
				}
				else if (a == 3)
				{
					std::cout << "\n   enter family           : ";
					std::cin >> L3;
					list_L[i].setfamily(L3);
					Date d;
					d = list_L[i].Birth;
					int d1, m1, y1;
					d1 = d.getD();
					m1 = d.getM();
					y1 = d.getY();
					temp << list_L[i].id << "   " << list_L[i].F_name << "   " << list_L[i].L_name << "   " << list_L[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_L[i].Doucu << "   " << list_L[i].posta << std::endl;
					g = 1;
				}
				else if (a == 4)
				{
					std::cout << "\n   enter post           : ";
					std::cin >> L3;
					list_L[i].setposta(L4);
					Date d;
					d = list_L[i].Birth;
					int d1, m1, y1;
					d1 = d.getD();
					m1 = d.getM();
					y1 = d.getY();
					temp << list_L[i].id << "   " << list_L[i].F_name << "   " << list_L[i].L_name << "   " << list_L[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_L[i].Doucu << "   " << list_L[i].posta << std::endl;
					g = 1;
				}
				else if (a == 5)
				{
					std::cout << "\n   enter Document           : ";
					std::cin >> L3;
					list_L[i].setDoucu(L5);
					Date d;
					d = list_L[i].Birth;
					int d1, m1, y1;
					d1 = d.getD();
					m1 = d.getM();
					y1 = d.getY();
					temp << list_L[i].id << "   " << list_L[i].F_name << "   " << list_L[i].L_name << "   " << list_L[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_L[i].Doucu << "   " << list_L[i].posta << std::endl;
					g = 1;
				}
			}

		}
		else if (list_L[i].id != iid)
		{
			Date d;
			d = list_L[i].Birth;
			int d1, m1, y1;
			d1 = d.getD();
			m1 = d.getM();
			y1 = d.getY();
			temp << list_L[i].id << "   " << list_L[i].F_name << "   " << list_L[i].L_name << "   " << list_L[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_L[i].Doucu << "   " << list_L[i].posta << std::endl;
		}

	}
	file_L.close();
	temp.close();
	if (remove("Librarians.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Librarians.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
}
void Librarian::Delet1(int iid)//delet the Librarian
{

	std::ifstream file_L("Librarians.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	int e;
	int e4, e5, e6;
	std::string e1, e2, e3, e7, e8;

	if (!file_L)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_L.eof())
	{
		file_L >> e;
		file_L >> e1;
		file_L >> e2;
		file_L >> e3;
		file_L >> e4;
		file_L >> e5;
		file_L >> e6;
		file_L >> e7;
		file_L >> e8;

		Date D(e4, e5, e6);
		Librarian L(e, e1, e2, e3, D, e7, e8);
		list_L.push_back(L);

	}

	for (int i = 0; i < list_L.size(); i++)
	{
		if (list_L[i].id != iid)
		{
			list_L2.push_back(list_L[i]);

		}
	}
	for (int i = 0; i <= list_L2.size(); i++)
	{
		Date d;
		d = list_L2[i].Birth;
		int d1, m1, y1;
		d1 = d.getD();
		m1 = d.getM();
		y1 = d.getY();
		temp << list_L2[i].id << "   " << list_L2[i].F_name << "   " << list_L2[i].L_name << "   " << list_L2[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_L2[i].Doucu << "   " << list_L2[i].posta << std::endl;
	}

	file_L.close();
	temp.close();
	if (remove("Librarians.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Librarians.txt") != 0)
		std::cout << "error in renaming output file " << "\n";

}
void Librarian::Serch1(int iid)// search a specific Librarian by id
{
	Date d;
	std::ifstream file_L("Librarians.txt", std::ios::in);
	int e;
	int e4, e5, e6;
	std::string e1, e2, e3, e7, e8;
	if (!file_L)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_L.eof())
	{
		file_L >> e;
		file_L >> e1;
		file_L >> e2;
		file_L >> e3;
		file_L >> e4;
		file_L >> e5;
		file_L >> e6;
		file_L >> e7;
		file_L >> e8;
		Date D(e4, e5, e6);
		Librarian L(e, e1, e2, e3, D, e7, e8);
		list_L.push_back(L);
	}
	for (int i = 0; i < list_L.size(); i++)
	{
		if (list_L[i].id == iid)
		{

			d = list_L[i].Birth;
			int d1, m1, y1;
			d1 = d.getD();
			m1 = d.getM();
			y1 = d.getY();
			std::cout << list_L[i].id << "   " << list_L[i].F_name << "   " << list_L[i].L_name << "   " << list_L[i].ID_card << "   " << d1 << "/" << m1 << "/" << y1 << "   " << list_L[i].Doucu << "   " << list_L[i].posta << std::endl;
			_getch();
		}
	}
	file_L.close();
}
void Librarian::report1()// report from all Librarian
{
	Date d;
	std::ifstream file_L("Librarians.txt", std::ios::in);
	int e;
	int e4, e5, e6;
	std::string e1, e2, e3, e7, e8;
	if (!file_L)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_L.eof())
	{
		file_L >> e;
		file_L >> e1;
		file_L >> e2;
		file_L >> e3;
		file_L >> e4;
		file_L >> e5;
		file_L >> e6;
		file_L >> e7;
		file_L >> e8;
		Date D(e4, e5, e6);
		Librarian L(e, e1, e2, e3, D, e7, e8);
		list_L.push_back(L);
	}
	for (int i = 0; i < list_L.size(); i++)
	{

		d = list_L[i].Birth;
		int d1, m1, y1;
		d1 = d.getD();
		m1 = d.getM();
		y1 = d.getY();
		std::cout << list_L[i].id << "   " << list_L[i].F_name << "   " << list_L[i].L_name << "   " << list_L[i].ID_card << "   " << d1 << "/" << m1 << "/" << y1 << "   " << list_L[i].Doucu << "   " << list_L[i].posta << std::endl;
		_getch();
	}
	file_L.close();
}
