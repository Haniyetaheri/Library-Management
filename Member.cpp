#include "person.h"
#include "Member.h"
#include "Date.h"
#include "Erore.h"
#include <iostream>
#include<cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
//constructor and access functions of Member class  :
Member::Member() :person()
{

}
void Member::r_data()
{
	std::string T, S, f;
	try
	{
		std::cout << "\n\n    Enter Type(student or Staff )      :   ";
		std::cin >> T;
		if (!(T[0] == 's' || T[0] == 'S' || T[0] == 'f' || T[0] == 'F'))
		{
			throw Erore("Only student and Staff can join ");
		}


	}
	catch (Erore E4)
	{
		std::cout << "enter the corect type or exsist ";
		std::cin >> T;
	}
	setType(T);
	std::cout << "\n\n    Enter (student or Staff )number    :   ";
	std::cin >> S;
	St_number = S;
	Fine = 0;

}
void Member::setType(std::string Type)
{
	this->Type = Type;
}
void Member::setSt_number(std::string  St_number)
{
	this->St_number = St_number;
}
void Member::setFine(int  Fine)
{
	this->Fine = Fine;
}
std::string Member::getType()const
{
	return Type;
}
std::string Member::getSt_number()const
{
	return St_number;
}
int Member::getFine()const
{
	return Fine;
}
////////////
std::vector<Member>list_M, list_t;
std::ofstream file_M;
void Member::Add()//add new Member
{
	Member m;
	Date d;
	m.r_data();
	m.R_data();
	d = m.Birth;
	int d1, m1, y1;
	d1 = d.getD();
	m1 = d.getM();
	y1 = d.getY();
	list_M.push_back(m);
	std::ofstream file_M("Members.txt", std::ios::app);
	if (!file_M)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	file_M << std::endl << m.id << "   " << m.F_name << "   " << m.L_name << "   " << m.ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << m.Type << "   " << m.St_number << "   " << m.Fine << std::endl;

	file_M.close();

}
void Member::Edit(int iid)//edit the information of Member
{
	int g = 0;
	std::ifstream file_M("Members.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	int e;
	int e4, e5, e6, e9;
	std::string e1, e2, e3, e7, e8;
	if (!file_M)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_M.eof())
	{
		file_M >> e;
		file_M >> e1;
		file_M >> e2;
		file_M >> e3;
		file_M >> e4;
		file_M >> e5;
		file_M >> e6;
		file_M >> e7;
		file_M >> e8;
		file_M >> e9;

		Date D(e4, e5, e6);
		Member m(e, e1, e2, e3, D, e7, e8, e9);
		list_M.push_back(m);
	}
	std::string m1, m2, m3;
	int a;
	for (int i = 0; i < list_M.size(); i++)
	{
		if (list_M[i].id == iid)
		{
			if (g != 1)
			{
				std::cout << "    Edit   menue       \n  ";
				std::cout << "    1: ID_code         \n  ";
				std::cout << "    2: name            \n  ";
				std::cout << "    3: family          \n  ";
				std::cin >> a;
				if (a == 1)
				{
					std::cout << "\n    enter ID_code         : ";
					std::cin >> m1;
					list_M[i].setID_C(m1);
					Date d;
					d = list_M[i].Birth;
					int d1, m1, y1;
					d1 = d.getD();
					m1 = d.getM();
					y1 = d.getY();
					temp << list_M[i].id << "   " << list_M[i].F_name << "   " << list_M[i].L_name << "   " << list_M[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_M[i].Type << "   " << list_M[i].St_number << "   " << list_M[i].Fine << std::endl;
					g = 1;
					break;
				}
				else if (a == 2)
				{
					std::cout << "\n    enter name            : ";
					std::cin >> m2;
					list_M[i].setname(m2);

					Date d;
					d = list_M[i].Birth;
					int d1, m1, y1;
					d1 = d.getD();
					m1 = d.getM();
					y1 = d.getY();
					temp << list_M[i].id << "   " << list_M[i].F_name << "   " << list_M[i].L_name << "   " << list_M[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_M[i].Type << "   " << list_M[i].St_number << "   " << list_M[i].Fine << std::endl;
					g = 1;
					break;
				}
				else if (a == 3)
				{
					std::cout << "\n   enter family           : ";
					std::cin >> m3;
					list_M[i].setfamily(m3);
					Date d;
					d = list_M[i].Birth;
					int d1, m1, y1;
					d1 = d.getD();
					m1 = d.getM();
					y1 = d.getY();
					temp << list_M[i].id << "   " << list_M[i].F_name << "   " << list_M[i].L_name << "   " << list_M[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_M[i].Type << "   " << list_M[i].St_number << "   " << list_M[i].Fine << std::endl;
					g = 1;
					break;
				}
			}

		}
		else if (list_M[i].id != iid)
		{
			Date d;
			d = list_M[i].Birth;
			int d1, m1, y1;
			d1 = d.getD();
			m1 = d.getM();
			y1 = d.getY();
			temp << list_M[i].id << "   " << list_M[i].F_name << "   " << list_M[i].L_name << "   " << list_M[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_M[i].Type << "   " << list_M[i].St_number << "   " << list_M[i].Fine << std::endl;
		}
	}

	file_M.close();
	temp.close();
	if (remove("Members.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Members.txt") != 0)
		std::cout << "error in renaming output file " << "\n";


}
void Member::Delet(int iid)//delet the Member
{
	std::ifstream file_M("Members.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	int e;
	int e4, e5, e6, e9;
	std::string e1, e2, e3, e7, e8;

	if (!file_M)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_M.eof())
	{
		file_M >> e;
		file_M >> e1;
		file_M >> e2;
		file_M >> e3;
		file_M >> e4;
		file_M >> e5;
		file_M >> e6;
		file_M >> e7;
		file_M >> e8;
		file_M >> e9;
		Date D(e4, e5, e6);
		Member m(e, e1, e2, e3, D, e7, e8, e9);
		list_M.push_back(m);
	}
	for (int i = 0; i < list_M.size(); i++)
	{
		if (list_M[i].id != iid)
		{
			list_t.push_back(list_M[i]);

		}
	}
	for (int i = 0; i <= list_t.size(); i++)
	{
		Date d;
		d = list_t[i].Birth;
		int d1, m1, y1;
		d1 = d.getD();
		m1 = d.getM();
		y1 = d.getY();
		temp << list_t[i].id << "   " << list_t[i].F_name << "   " << list_t[i].L_name << "   " << list_t[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_t[i].Type << "   " << list_t[i].St_number << "   " << list_t[i].Fine << std::endl;
	}

	file_M.close();
	temp.close();
	if (remove("Members.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Members.txt") != 0)
		std::cout << "error in renaming output file " << "\n";


}
void Member::Serch(int iid)// search a specific Member by id
{
	Member m;
	Date d;
	std::ifstream file_M("Members.txt", std::ios::in);
	int e;
	int e4, e5, e6, e9;
	std::string e1, e2, e3, e7, e8;
	if (!file_M)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_M.eof())
	{
		file_M >> e;
		file_M >> e1;
		file_M >> e2;
		file_M >> e3;
		file_M >> e4;
		file_M >> e5;
		file_M >> e6;
		file_M >> e7;
		file_M >> e8;
		file_M >> e9;
		Date D(e4, e5, e6);
		Member m(e, e1, e2, e3, D, e7, e8, e9);
		list_M.push_back(m);
	}
	for (int i = 0; i < list_M.size(); i++)
	{
		if (list_M[i].id == iid)
		{

			d = list_M[i].Birth;
			int d1, m1, y1;
			d1 = d.getD();
			m1 = d.getM();
			y1 = d.getY();
			std::cout << list_M[i].id << "   " << list_M[i].F_name << "   " << list_M[i].L_name << "   " << list_M[i].ID_card << "   " << d1 << "/" << m1 << "/" << y1 << "   " << list_M[i].Type << "   " << list_M[i].St_number << "   " << list_M[i].Fine << std::endl;
			_getch();
			break;
		}
	}
	file_M.close();
}
bool Member::isexist(int iid)//check the library member id
{
	int B = 0;
	Member m;
	Date d;
	std::ifstream file_M("Members.txt", std::ios::in);
	int e;
	int e4, e5, e6, e9;
	std::string e1, e2, e3, e7, e8;
	if (!file_M)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_M.eof())
	{
		file_M >> e;
		file_M >> e1;
		file_M >> e2;
		file_M >> e3;
		file_M >> e4;
		file_M >> e5;
		file_M >> e6;
		file_M >> e7;
		file_M >> e8;
		file_M >> e9;
		Date D(e4, e5, e6);
		Member m(e, e1, e2, e3, D, e7, e8, e9);
		list_M.push_back(m);
	}
	for (int i = 0; i < list_M.size(); i++)
	{
		if (list_M[i].id == iid)
		{
			B = 1;
			break;
		}
	}
	file_M.close();
	if (B == 1)
	{
		return true;
	}
	else if (B == 0)
	{
		return false;
	}
}
void Member::report()// report from all Member
{
	Member m;
	Date d;
	std::ifstream file_M("Members.txt", std::ios::in);
	int e;
	int e4, e5, e6, e9;
	std::string e1, e2, e3, e7, e8;
	if (!file_M)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_M.eof())
	{
		file_M >> e;
		file_M >> e1;
		file_M >> e2;
		file_M >> e3;
		file_M >> e4;
		file_M >> e5;
		file_M >> e6;
		file_M >> e7;
		file_M >> e8;
		file_M >> e9;
		Date D(e4, e5, e6);
		Member m(e, e1, e2, e3, D, e7, e8, e9);
		list_M.push_back(m);


	}
	for (int i = 0; i < list_M.size() - 1; i++)
	{

		d = list_M[i].Birth;
		int d1, m1, y1;
		d1 = d.getD();
		m1 = d.getM();
		y1 = d.getY();
		std::cout << list_M[i].id << "   " << list_M[i].F_name << "   " << list_M[i].L_name << "   " << list_M[i].ID_card << "   " << d1 << "/" << m1 << "/" << y1 << "   " << list_M[i].Type << "   " << list_M[i].St_number << "   " << list_M[i].Fine << std::endl;
		_getch();
	}
	file_M.close();
}
void Member::Payment_F(int iid)//Payment of Fine 
{
	int p = 0;
	Member m;

	std::ifstream file_M("Members.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	int e;
	int e4, e5, e6, e9;
	std::string e1, e2, e3, e7, e8;
	if (!file_M)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_M.eof())
	{
		file_M >> e;
		file_M >> e1;
		file_M >> e2;
		file_M >> e3;
		file_M >> e4;
		file_M >> e5;
		file_M >> e6;
		file_M >> e7;
		file_M >> e8;
		file_M >> e9;
		Date D(e4, e5, e6);
		Member m(e, e1, e2, e3, D, e7, e8, e9);
		list_M.push_back(m);
	}
	for (int i = 0; i < list_M.size(); i++)
	{
		if (list_M[i].id == iid)
		{
			Date d;
			d = list_M[i].Birth;
			int d1, m1, y1;
			d1 = d.getD();
			m1 = d.getM();
			y1 = d.getY();
			std::cout << " \n  the amount of fines  :";
			std::cout << list_M[i].Fine << std::endl;
			std::cout << " \n  enter payments    :";
			std::cin >> p;
			list_M[i].Fine = 0;
			temp << list_M[i].id << "   " << list_M[i].F_name << "   " << list_M[i].L_name << "   " << list_M[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_M[i].Type << "   " << list_M[i].St_number << "   " << list_M[i].Fine << std::endl;
			std::cout << list_M[i].Fine << std::endl;
			break;
		}
		else if (list_M[i].id != iid)
		{
			Date d;
			d = list_M[i].Birth;
			int d1, m1, y1;
			d1 = d.getD();
			m1 = d.getM();
			y1 = d.getY();
			temp << list_M[i].id << "   " << list_M[i].F_name << "   " << list_M[i].L_name << "   " << list_M[i].ID_card << "   " << d1 << " " << m1 << " " << y1 << "   " << list_M[i].Type << "   " << list_M[i].St_number << "   " << list_M[i].Fine << std::endl;
		}
	}
	file_M.close();
	temp.close();
	if (remove("Members.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Members.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
}
