#include "Book.h"
#include "Book_b.h"
#include "Erore.h"
#include <iostream>
#include<cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
//constructor and access functions of book class  :
Book_b::Book_b()
{
}
void Book_b::setdata1()
{
	std::string R;
	std::cout << "\n\n  enter rang  : ";
	std::cin >> R;
	setrang(R);
}
void Book_b::setN_B(int N_B)
{
	this->N_B = N_B;
}
void Book_b::setrang(std::string rang)
{
	this->rang = rang;
}
void Book_b::setavail(int avail)
{
	this->avail = avail;
}
int Book_b::getN_B()
{
	return N_B;
}
std::string Book_b::getrang()
{
	return rang;
}
int Book_b::getavail()
{
	return avail;
}

std::vector<Book_b>list_b, list_b2;
std::ofstream file_b;
void Book_b::add2()//function for check the information to prevent duplicate information 
{
	int ch = 0;
	std::string b1;
	std::cout << " enter ID ";
	std::cin >> b1;
	std::ifstream file_b("Books.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	std::string e1, e2, e3, e4;
	int e5, e6;
	if (!file_b)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_b.eof())
	{
		file_b >> e1;
		file_b >> e2;
		file_b >> e3;
		file_b >> e4;
		file_b >> e5;
		file_b >> e6;
		Book_b b(e1, e2, e3, e4, e5, e6);
		list_b.push_back(b);
	}
	for (int i = 0; i < list_b.size(); i++)
	{
		if (list_b[i].ID == b1)
		{
			int B = list_b[i].N_B;
			B++;
			list_b[i].N_B = B;
			B = list_b[i].avail;
			B++;
			list_b[i].avail = B;
			temp << list_b[i].ID << "   " << list_b[i].Title << "   " << list_b[i].p_count << "   " << list_b[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;
			ch = 1;
			std::cout << " Added \n";
		}
		else if (list_b[i].ID != b1)
		{
			temp << list_b[i].ID << "   " << list_b[i].Title << "   " << list_b[i].p_count << "   " << list_b[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;
		}
	}

	file_b.close();
	temp.close();
	if (remove("Books.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Books.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
	if (ch == 0)
	{
		Add2();
	}
}
void Book_b::Add2()// add new book
{
	Book_b b;
	b.setData();
	b.setdata1();
	list_b.push_back(b);
	std::ofstream file_b("Books.txt", std::ios::app);
	if (!file_b)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	b.N_B++;
	b.avail++;
	file_b << b.ID << "   " << b.Title << "   " << b.p_count << "   " << b.rang << "   " << b.N_B << "   " << b.avail << std::endl;

	file_b.close();
	std::cout << " added \n";
}
void Book_b::Edit2(std::string iid)//edit the information of book
{
	std::ifstream file_b("Books.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	std::string e1, e2, e3, e4;
	int e5, e6;
	if (!file_b)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_b.eof())
	{
		file_b >> e1;
		file_b >> e2;
		file_b >> e3;
		file_b >> e4;
		file_b >> e5;
		file_b >> e6;
		Book_b b(e1, e2, e3, e4, e5, e6);
		list_b.push_back(b);
	}
	std::string m1, m2, m3;
	int a;
	for (int i = 0; i < list_b.size(); i++)
	{
		if (list_b[i].ID == iid)
		{
			std::cout << "    Edit   menue       \n  ";
			std::cout << "    1: ID              \n  ";
			std::cout << "    2: Title           \n  ";
			std::cout << "    3: range           \n  ";
			std::cin >> a;
			if (a == 1)
			{
				std::cout << "\n    enter ID        : ";
				std::cin >> m1;
				list_b[i].set_ID(m1);
				temp << list_b[i].ID << "   " << list_b[i].Title << "   " << list_b[i].p_count << "   " << list_b[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;
				break;
			}
			else if (a == 2)
			{
				std::cout << "\n    enter Title            : ";
				std::cin >> m2;
				list_b[i].setTitle(m2);

				temp << list_b[i].ID << "   " << list_b[i].Title << "   " << list_b[i].p_count << "   " << list_b[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;
				break;
			}
			else if (a == 3)
			{
				std::cout << "\n   enter range           : ";
				std::cin >> m3;
				list_b[i].setrang(m3);

				temp << list_b[i].ID << "   " << list_b[i].Title << "   " << list_b[i].p_count << "   " << list_b[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;
				break;
			}
		}
		else if (list_b[i].ID != iid)
		{

			temp << list_b[i].ID << "   " << list_b[i].Title << "   " << list_b[i].p_count << "   " << list_b[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;
		}

	}

	file_b.close();
	temp.close();
	if (remove("Books.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Books.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
}
void Book_b::Delet2(std::string iid)// delet the book 
{
	std::ifstream file_b("Books.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	std::string e1, e2, e3, e4;
	int e5, e6;
	if (!file_b)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_b.eof())
	{
		file_b >> e1;
		file_b >> e2;
		file_b >> e3;
		file_b >> e4;
		file_b >> e5;
		file_b >> e6;
		Book_b b(e1, e2, e3, e4, e5, e6);
		list_b.push_back(b);
	}
	for (int i = 0; i < list_b.size(); i++)
	{
		if (list_b[i].ID != iid)
		{
			list_b2.push_back(list_b[i]);
		}
		else if (list_b[i].ID == iid)
		{
			if (list_b[i].N_B > 1)
			{
				int B = list_b[i].N_B;
				B--;
				list_b[i].N_B = B;
				B = list_b[i].avail;
				B--;
				list_b[i].avail = B;
				list_b2.push_back(list_b[i]);
			}
		}
	}
	for (int i = 0; i < list_b2.size(); i++)
	{
		temp << list_b2[i].ID << "   " << list_b2[i].Title << "   " << list_b2[i].p_count << "   " << list_b2[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;
	}

	file_b.close();
	temp.close();
	if (remove("Books.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Books.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
}
void Book_b::Serch2(std::string iid)// search a specific book by id
{
	std::ifstream file_b("Books.txt", std::ios::in);
	std::string e1, e2, e3, e4;
	int e5, e6;
	if (!file_b)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_b.eof())
	{
		file_b >> e1;
		file_b >> e2;
		file_b >> e3;
		file_b >> e4;
		file_b >> e5;
		file_b >> e6;

		Book_b b(e1, e2, e3, e4, e5, e6);
		list_b.push_back(b);
	}
	for (int i = 0; i < list_b.size() - 1; i++)
	{
		if (list_b[i].ID == iid)
		{
			std::cout << list_b[i].ID << "   " << list_b[i].Title << "   " << list_b[i].p_count << "   " << list_b[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;
			_getch();
		}
	}
	file_b.close();
}
void Book_b::report_A()// report from all book
{
	std::ifstream file_b("Books.txt", std::ios::in);
	std::string e1, e2, e3, e4;
	int e5, e6;
	if (!file_b)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_b.eof())
	{
		file_b >> e1;
		file_b >> e2;
		file_b >> e3;
		file_b >> e4;
		file_b >> e5;
		file_b >> e6;
		Book_b b(e1, e2, e3, e4, e5, e6);
		list_b.push_back(b);
	}
	for (int i = 0; i < list_b.size() - 1; i++)
	{
		std::cout << list_b[i].ID << "   " << list_b[i].Title << "   " << list_b[i].p_count << "   " << list_b[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;

	}
	file_b.close();
	_getch();
}
void Book_b::report_S(std::string rang)//report of a certain category of books
{
	std::ifstream file_b("Books.txt", std::ios::in);
	std::string e1, e2, e3, e4;
	int e5, e6;
	if (!file_b)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_b.eof())
	{
		file_b >> e1;
		file_b >> e2;
		file_b >> e3;
		file_b >> e4;
		file_b >> e5;
		file_b >> e6;
		Book_b b(e1, e2, e3, e4, e5, e6);
		list_b.push_back(b);
	}
	for (int i = 0; i < list_b.size() - 1; i++)
	{
		if (list_b[i].rang == rang)
		{
			std::cout << list_b[i].ID << "   " << list_b[i].Title << "   " << list_b[i].p_count << "   " << list_b[i].rang << "   " << list_b[i].N_B << "   " << list_b[i].avail << std::endl;
		}
	}
	file_b.close();
	_getch();
}
