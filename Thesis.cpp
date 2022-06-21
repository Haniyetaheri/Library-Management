#include "Book.h"
#include "Thesis.h"
#include "Erore.h"
#include <iostream>
#include<cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
//constructor and access functions of Thesis class  :
Thesis::Thesis()
{
}
void Thesis::setdata2()
{
	std::string g;
	std::cout << "\n\n  enter grade  : ";
	std::cin >> g;
	setgrade(g);

	std::string f;
	std::cout << "\n\n  enter faculty  : ";
	std::cin >> f;
	setfaculty(f);

	std::string gr;
	std::cout << "\n\n  enter group  : ";
	std::cin >> gr;
	setgroup(gr);
}
void Thesis::setgrade(std::string grade)
{
	this->grade = grade;
}
void Thesis::setfaculty(std::string faculty)
{
	this->faculty = faculty;
}
void Thesis::setgroup(std::string group)
{
	this->group = group;
}
void Thesis::setavail_T(int avail_T)
{
	this->avail_T = avail_T;
}
std::string Thesis::getgrade()
{
	return grade;
}
std::string Thesis::getfaculty()
{
	return faculty;
}
std::string Thesis::getgroup()
{
	return group;
}
int Thesis::getavail_T()
{
	return avail_T;
}

std::vector<Thesis>list_T, list_T2;
std::ofstream file_T;
void Thesis::Add4()//add new Thesis
{
	Thesis t;
	t.setData();
	t.setdata2();
	list_T.push_back(t);
	std::ofstream file_T("Thesis.txt", std::ios::app);
	if (!file_T)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	t.avail_T++;
	file_T << t.ID << "   " << t.Title << "   " << t.p_count << "   " << t.grade << "   " << t.faculty << "   " << t.group << "   " << t.avail_T << std::endl;

	file_T.close();
	std::cout << " added \n";
}
void Thesis::Edit4(std::string iid)//edit the information of Thesis
{
	std::ifstream file_T("Thesis.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	std::string e1, e2, e3, e4, e5, e6;
	int e7;
	if (!file_T)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_T.eof())
	{

		file_T >> e1;
		file_T >> e2;
		file_T >> e3;
		file_T >> e4;
		file_T >> e5;
		file_T >> e6;
		file_T >> e7;

		Thesis T(e1, e2, e3, e4, e5, e6, e7);
		list_T.push_back(T);
	}
	std::string m1, m2, m3;
	int a;

	for (int i = 0; i < list_T.size(); i++)
	{
		if (list_T[i].ID == iid)
		{
			std::cout << "    Edit   menue       \n  ";
			std::cout << "    1: ID              \n  ";
			std::cout << "    2: Title           \n  ";
			std::cout << "    3: grade           \n  ";
			std::cout << "    4: faculty           \n  ";
			std::cin >> a;
			if (a == 1)
			{
				std::cout << "\n    enter ID        : ";
				std::cin >> m1;
				list_T[i].set_ID(m1);
				temp << list_T[i].ID << "   " << list_T[i].Title << "   " << list_T[i].p_count << "   " << list_T[i].grade << "   " << list_T[i].faculty << "   " << list_T[i].group << "   " << list_T[i].avail_T << std::endl;
				break;
			}
			else if (a == 2)
			{
				std::cout << "\n    enter Title            : ";
				std::cin >> m2;
				list_T[i].setTitle(m2);

				temp << list_T[i].ID << "   " << list_T[i].Title << "   " << list_T[i].p_count << "   " << list_T[i].grade << "   " << list_T[i].faculty << "   " << list_T[i].group << "   " << list_T[i].avail_T << std::endl;
				break;
			}
			else if (a == 3)
			{
				std::cout << "\n   enter grade           : ";
				std::cin >> m3;
				list_T[i].setgrade(m3);

				temp << list_T[i].ID << "   " << list_T[i].Title << "   " << list_T[i].p_count << "   " << list_T[i].grade << "   " << list_T[i].faculty << "   " << list_T[i].group << "   " << list_T[i].avail_T << std::endl;
				break;
			}
			else if (a == 4)
			{
				std::cout << "\n   enter faculty           : ";
				std::cin >> m3;
				list_T[i].setfaculty(m3);

				temp << list_T[i].ID << "   " << list_T[i].Title << "   " << list_T[i].p_count << "   " << list_T[i].grade << "   " << list_T[i].faculty << "   " << list_T[i].group << "   " << list_T[i].avail_T << std::endl;
				break;
			}
		}
		else if (list_T[i].ID != iid)
		{

			temp << list_T[i].ID << "   " << list_T[i].Title << "   " << list_T[i].p_count << "   " << list_T[i].grade << "   " << list_T[i].faculty << "   " << list_T[i].group << "   " << list_T[i].avail_T << std::endl;
		}

	}

	file_T.close();
	temp.close();
	if (remove("Thesis.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Thesis.txt") != 0)
		std::cout << "error in renaming output file " << "\n";

}
void Thesis::Delet4(std::string iid)//delet the Thesis
{
	std::ifstream file_T("Thesis.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	std::string e1, e2, e3, e4, e5, e6;
	int e7;
	if (!file_T)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_T.eof())
	{
		file_T >> e1;
		file_T >> e2;
		file_T >> e3;
		file_T >> e4;
		file_T >> e5;
		file_T >> e6;
		file_T >> e7;
		Thesis T(e1, e2, e3, e4, e5, e6, e7);
		list_T.push_back(T);
	}

	for (int i = 0; i < list_T.size(); i++)
	{
		if (list_T[i].ID != iid)
		{
			list_T2.push_back(list_T[i]);
		}
	}
	for (int i = 0; i < list_T2.size(); i++)
	{
		temp << list_T2[i].ID << "   " << list_T2[i].Title << "   " << list_T2[i].p_count << "   " << list_T2[i].grade << "   " << list_T2[i].faculty << "   " << list_T2[i].group << "   " << list_T2[i].avail_T << std::endl;
	}

	file_T.close();
	temp.close();
	if (remove("Thesis.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Thesis.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
}
void Thesis::Serch4(std::string iid)// search a specific Thesis by id
{
	std::ifstream file_T("Thesis.txt", std::ios::in);
	std::string e1, e2, e3, e4, e5, e6;
	int e7;
	if (!file_T)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_T.eof())
	{
		file_T >> e1;
		file_T >> e2;
		file_T >> e3;
		file_T >> e4;
		file_T >> e5;
		file_T >> e6;
		file_T >> e7;
		Thesis T(e1, e2, e3, e4, e5, e6, e7);
		list_T.push_back(T);
	}
	for (int i = 0; i < list_T.size() - 1; i++)
	{
		if (list_T[i].ID == iid)
		{
			std::cout << list_T[i].ID << "   " << list_T[i].Title << "   " << list_T[i].p_count << "   " << list_T[i].grade << "   " << list_T[i].faculty << "   " << list_T[i].group << "   " << list_T[i].avail_T << std::endl;
			_getch();
		}
	}
	file_T.close();
}
void Thesis::report_A4()//report from all Thesis
{
	std::ifstream file_T("Thesis.txt", std::ios::in);
	std::string e1, e2, e3, e4, e5, e6;
	int e7;
	if (!file_T)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_T.eof())
	{
		file_T >> e1;
		file_T >> e2;
		file_T >> e3;
		file_T >> e4;
		file_T >> e5;
		file_T >> e6;
		file_T >> e7;
		Thesis T(e1, e2, e3, e4, e5, e6, e7);
		list_T.push_back(T);
	}
	for (int i = 0; i < list_T.size() - 1; i++)
	{
		std::cout << list_T[i].ID << "   " << list_T[i].Title << "   " << list_T[i].p_count << "   " << list_T[i].grade << "   " << list_T[i].faculty << "   " << list_T[i].group << "   " << list_T[i].avail_T << std::endl;
		_getch();
	}
	file_T.close();
}
