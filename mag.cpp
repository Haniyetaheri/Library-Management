#include "Book.h"
#include "mag.h"
#include "Erore.h"
#include <iostream>
#include<cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
//constructor and access functions of magazin class  :
mag::mag()
{
}
void mag::setN_M(int N_M)
{
	this->N_M = N_M;
}
void mag::setavail_M(int avail_M)
{
	this->avail_M = avail_M;
}
int mag::getN_M()
{
	return N_M;
}
int mag::getavail_M()
{
	return avail_M;
}

std::vector<mag>list_m, list_m2;
std::ofstream file_m;
void mag::add3()//function for check the information to prevent duplicate information 
{
	int ch = 0;
	std::string m1;
	std::cout << " enter ID ";
	std::cin >> m1;
	std::ifstream file_m("magezins.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);

	std::string e1, e2, e3;
	int e5, e6;
	if (!file_m)
	{
		std::cout << " the filecan not be opend \n";
	}
	while (!file_m.eof())
	{
		file_m >> e1;
		file_m >> e2;
		file_m >> e3;
		file_m >> e5;
		file_m >> e6;

		mag m(e1, e2, e3, e5, e6);
		list_m.push_back(m);
	}
	for (int i = 0; i < list_m.size(); i++)
	{
		if (list_m[i].ID == m1)
		{
			int M = list_m[i].N_M;
			M++;
			list_m[i].N_M = M;
			M = list_m[i].avail_M;
			M++;
			list_m[i].avail_M = M;
			temp << list_m[i].ID << "   " << list_m[i].Title << "   " << list_m[i].p_count << "   " << list_m[i].N_M << "   " << list_m[i].avail_M << std::endl;
			ch = 1;
			std::cout << " Added \n";
		}
		else if (list_m[i].ID != m1)
		{

			temp << list_m[i].ID << "   " << list_m[i].Title << "   " << list_m[i].p_count << "   " << list_m[i].N_M << "   " << list_m[i].avail_M << std::endl;
		}
	}

	file_m.close();
	temp.close();
	if (remove("magezins.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "magezins.txt") != 0)
		std::cout << "error in renaming output file " << "\n";

	if (ch == 0)
	{
		Add3();
	}
}
void mag::Add3()//add new magazin
{
	mag m;
	m.setData();
	list_m.push_back(m);
	std::ofstream file_m("magezins.txt", std::ios::app);
	if (!file_m)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	m.N_M++;
	m.avail_M++;
	file_m << m.ID << "   " << m.Title << "   " << m.p_count << "   " << m.N_M << "   " << m.avail_M << std::endl;

	file_m.close();
	std::cout << " added \n";
}
void mag::Edit3(std::string iid)//edit the information of magazin
{
	std::ifstream file_m("magezins.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	std::string e1, e2, e3;
	int e5, e6;
	if (!file_m)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_m.eof())
	{
		file_m >> e1;
		file_m >> e2;
		file_m >> e3;
		file_m >> e5;
		file_m >> e6;
		mag m(e1, e2, e3, e5, e6);
		list_m.push_back(m);
	}
	std::string m1, m2;
	int a;

	for (int i = 0; i < list_m.size(); i++)
	{
		if (list_m[i].ID == iid)
		{
			std::cout << "    Edit   menue       \n  ";
			std::cout << "    1: ID              \n  ";
			std::cout << "    2: Title           \n  ";
			std::cin >> a;
			if (a == 1)
			{
				std::cout << "\n    enter ID        : ";
				std::cin >> m1;
				list_m[i].set_ID(m1);
				temp << list_m[i].ID << "   " << list_m[i].Title << "   " << list_m[i].p_count << "   " << list_m[i].N_M << "   " << list_m[i].avail_M << std::endl;
			}
			else if (a == 2)
			{
				std::cout << "\n    enter Title            : ";
				std::cin >> m2;
				list_m[i].setTitle(m2);
				temp << list_m[i].ID << "   " << list_m[i].Title << "   " << list_m[i].p_count << "   " << list_m[i].N_M << "   " << list_m[i].avail_M << std::endl;
			}
		}
		else if (list_m[i].ID != iid)
		{
			temp << list_m[i].ID << "   " << list_m[i].Title << "   " << list_m[i].p_count << "   " << list_m[i].N_M << "   " << list_m[i].avail_M << std::endl;
		}
	}

	file_m.close();
	temp.close();
	if (remove("magezins.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "magezins.txt") != 0)
		std::cout << "error in renaming output file " << "\n";


}
void mag::Delet3(std::string iid)//delet the magazin
{

	std::ifstream file_m("magezins.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);

	std::string e1, e2, e3;
	int e5, e6;
	if (!file_m)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_m.eof())
	{
		file_m >> e1;
		file_m >> e2;
		file_m >> e3;
		file_m >> e5;
		file_m >> e6;
		mag m(e1, e2, e3, e5, e6);
		list_m.push_back(m);
	}

	for (int i = 0; i < list_m.size(); i++)
	{
		if (list_m[i].ID != iid)
		{
			list_m2.push_back(list_m[i]);
		}
		else if (list_m[i].ID == iid)
		{
			if (list_m[i].N_M > 1)
			{
				int M = list_m[i].N_M;
				M--;
				list_m[i].N_M = M;
				M = list_m[i].avail_M;
				M--;
				list_m[i].avail_M = M;
				list_m2.push_back(list_m[i]);
			}
		}
	}
	for (int i = 0; i < list_m2.size(); i++)
	{
		temp << list_m2[i].ID << "   " << list_m2[i].Title << "   " << list_m2[i].p_count << "   " << list_m[i].N_M << "   " << list_m[i].avail_M << std::endl;
	}

	file_m.close();
	temp.close();
	if (remove("magezins.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "magezins.txt") != 0)
		std::cout << "error in renaming output file " << "\n";

}
void mag::Serch3(std::string iid)// search a specific magazin by id
{
	std::ifstream file_m("magezins.txt", std::ios::in);
	std::string e1, e2, e3;
	int e5, e6;
	if (!file_m)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_m.eof())
	{
		file_m >> e1;
		file_m >> e2;
		file_m >> e3;
		file_m >> e5;
		file_m >> e6;

		mag m(e1, e2, e3, e5, e6);
		list_m.push_back(m);
	}
	for (int i = 0; i < list_m.size() - 1; i++)
	{
		if (list_m[i].ID == iid)
		{
			std::cout << list_m[i].ID << "   " << list_m[i].Title << "   " << list_m[i].p_count << "   " << list_m[i].N_M << "   " << list_m[i].avail_M << std::endl;
			_getch();
		}
	}
	file_m.close();
}
void mag::report_A2()// report from all magazin
{
	std::ifstream file_m("magezins.txt", std::ios::in);
	std::string e1, e2, e3;
	int e5, e6;
	if (!file_m)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_m.eof())
	{
		file_m >> e1;
		file_m >> e2;
		file_m >> e3;
		file_m >> e5;
		file_m >> e6;
		mag m(e1, e2, e3, e5, e6);
		list_m.push_back(m);
	}
	for (int i = 0; i < list_m.size() - 1; i++)
	{
		std::cout << list_m[i].ID << "   " << list_m[i].Title << "   " << list_m[i].p_count << "   " << list_m[i].N_M << "   " << list_m[i].avail_M << std::endl;
		_getch();
	}
	file_m.close();
}
