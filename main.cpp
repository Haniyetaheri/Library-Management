// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<conio.h>
#include<vector>
#include<cstdio>
#include "Amanat.h"
#include "Erore.h"
#include"Date.h"
#include"person.h"
#include "Book.h"
#include "Book_b.h"
#include "Thesis.h"
#include "Librarian.h"
#include "mag.h"
#include "Member.h"


void M_menu()
{
	Member m;
	int a;
	while (true)
	{
		system("cls");
		std::cout << "\n\n\n              Member Menu                 \n\n";
		std::cout << "   --------------------------------------------------------    \n";
		std::cout << "\n           1 : Add                    ";
		std::cout << "\n           2 : Edit                   ";
		std::cout << "\n           3 : Delet                  ";
		std::cout << "\n           4 : Serch                  ";
		std::cout << "\n           5 : report                 ";
		std::cout << "\n           6 : Payment_Fine           ";
		std::cout << "\n           7 : back to main                   ";
		std::cout << "\n           your choice      :         ";
		std::cin >> a;
		if (a == 1)
		{
			m.Add();
		}
		else if (a == 2)
		{
			int id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			m.Edit(id);
		}
		else if (a == 3)
		{
			int id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			m.Delet(id);
		}
		else if (a == 4)
		{
			int id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			m.Serch(id);
		}
		else if (a == 5)
		{
			m.report();
		}
		else if (a == 6)
		{
			int id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			m.Payment_F(id);
		}
		else if (a == 7)
		{
			return;
		}
	}
}
void L_menu()
{
	Librarian L;
	int a;
	while (true)
	{
		system("cls");
		std::cout << "\n\n\n              Librarian Menu                 \n\n";
		std::cout << "   --------------------------------------------------------    \n";
		std::cout << "\n           1 : Add                    ";
		std::cout << "\n           2 : Edit                   ";
		std::cout << "\n           3 : Delet                  ";
		std::cout << "\n           4 : Serch                  ";
		std::cout << "\n           5 : report                 ";
		std::cout << "\n           6 : back to main                   ";
		std::cout << "\n           your choice      :         ";
		std::cin >> a;
		if (a == 1)
		{
			L.Add1();
		}
		else if (a == 2)
		{
			int id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			L.Edit1(id);
		}
		else if (a == 3)
		{
			int id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			L.Delet1(id);
		}
		else if (a == 4)
		{
			int id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			L.Serch1(id);
		}
		else if (a == 5)
		{
			L.report1();
		}
		else if (a == 6)
		{
			return;
		}
	}
}

void B_menu()
{
	Book_b B;
	int a;
	while (true)
	{
		system("cls");
		std::cout << "\n\n\n              Member Menu                 \n\n";
		std::cout << "   --------------------------------------------------------    \n";
		std::cout << "\n           1 : Add                            ";
		std::cout << "\n           2 : Edit                           ";
		std::cout << "\n           3 : Delet                          ";
		std::cout << "\n           4 : Serch                          ";
		std::cout << "\n           5 : report All                     ";
		std::cout << "\n           6 : report special of rang         ";
		std::cout << "\n           7 : back to main                   ";
		std::cout << "\n           your choice      :                 ";
		std::cin >> a;
		if (a == 1)
		{
			B.add2();
		}
		else if (a == 2)
		{
			std::string id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			B.Edit2(id);
		}
		else if (a == 3)
		{
			std::string id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			B.Delet2(id);
		}
		else if (a == 4)
		{
			std::string id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			B.Serch2(id);

		}
		else if (a == 5)
		{
			B.report_A();
		}
		else if (a == 6)
		{
			std::string r;
			std::cout << "\n  enter rang of book : ";
			std::cin >> r;
			B.report_S(r);
		}
		else if (a == 7)
		{
			return;
		}
	}
}
void Ma_menu()
{
	mag M;
	int a;
	while (true)
	{
		system("cls");
		std::cout << "\n\n\n              Magazine Menu                 \n\n";
		std::cout << "   --------------------------------------------------------    \n";
		std::cout << "\n           1 : Add                            ";
		std::cout << "\n           2 : Edit                           ";
		std::cout << "\n           3 : Delet                          ";
		std::cout << "\n           4 : Serch                          ";
		std::cout << "\n           5 : report All                     ";
		std::cout << "\n           6 : back to main                   ";
		std::cout << "\n           your choice      :                 ";
		std::cin >> a;
		if (a == 1)
		{
			M.add3();
		}
		else if (a == 2)
		{
			std::string id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			M.Edit3(id);
		}
		else if (a == 3)
		{
			std::string id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			M.Delet3(id);
		}
		else if (a == 4)
		{
			std::string id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			M.Serch3(id);

		}
		else if (a == 5)
		{
			M.report_A2();
		}
		else if (a == 7)
		{
			return;
		}
	}
}
void T_menu()
{
	Thesis T;
	int a;
	while (true)
	{
		system("cls");
		std::cout << "\n\n\n              Thesis Menu                 \n\n";
		std::cout << "   --------------------------------------------------------    \n";
		std::cout << "\n           1 : Add                            ";
		std::cout << "\n           2 : Edit                           ";
		std::cout << "\n           3 : Delet                          ";
		std::cout << "\n           4 : Serch                          ";
		std::cout << "\n           5 : report All                     ";
		std::cout << "\n           6 : back to main                   ";
		std::cout << "\n           your choice      :                 ";
		std::cin >> a;
		if (a == 1)
		{
			T.Add4();
		}
		else if (a == 2)
		{
			std::string id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			T.Edit4(id);
		}
		else if (a == 3)
		{
			std::string id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			T.Delet4(id);
		}
		else if (a == 4)
		{
			std::string id;
			std::cout << "\n  enter your ID : ";
			std::cin >> id;
			T.Serch4(id);

		}
		else if (a == 5)
		{
			T.report_A4();
		}
		else if (a == 6)
		{
			return;
		}
	}
}

void A_menu()
{
	Member m;
	int id;
	int a;
	std::cout << "\n  enter your ID : ";
	std::cin >> id;

	if (m.isexist(id) == true)
	{
		Amanat A;
		int a;
		while (true)
		{
			system("cls");
			std::cout << "\n\n\n              Amanat Menu                 \n\n";
			std::cout << "   --------------------------------------------------------    \n";
			std::cout << "\n           1 : enter                          ";
			std::cout << "\n           2 : extend                         ";
			std::cout << "\n           3 : Delet                          ";
			std::cout << "\n           4 : Serch   Books                  ";
			std::cout << "\n           5 : Serch  Members                 ";
			std::cout << "\n           6 : report                         ";
			std::cout << "\n           7 : back to main                   ";
			std::cout << "\n           your choice      :                 ";
			std::cin >> a;
			if (a == 1)
			{
				A.enter0();
			}
			else if (a == 2)
			{
				int id;
				std::cout << "\n  enter your ID : ";
				std::cin >> id;
				A.edit(id);
			}
			else if (a == 3)
			{
				int id;
				std::cout << "\n  enter your ID : ";
				std::cin >> id;
				A.delet(id);
			}
			else if (a == 4)
			{
				std::string id;
				std::cout << "\n  enter book ID : ";
				std::cin >> id;
				A.serch1(id);
			}
			else if (a == 5)
			{
				int r;
				std::cout << "\n  enter ID of Member : ";
				std::cin >> r;
				A.serch2(r);
			}
			else if (a == 6)
			{
				A.Report();
			}
			else if (a == 7)
			{
				return;
			}
		}
	}
	else if (m.isexist(id) == false)
	{
		std::cout << "\n you are not a member of the library !!";
		std::cout << "\n please register first ";
		_getch();
	}

}

void main_menu()
{

	int a;
	while (true)
	{
		system("cls");
		std::cout << "\n\n\n               main Menu                 \n\n";
		std::cout << "   --------------------------------------------------------    \n";
		std::cout << "\n           1 : Members_menue          ";
		std::cout << "\n           2 : Librarian_menue        ";
		std::cout << "\n           3 : Books_menue            ";
		std::cout << "\n           4 : magazine_menue         ";
		std::cout << "\n           5 : Thesis_menue           ";
		std::cout << "\n           6 : Amanat_menue           ";
		std::cout << "\n           7 : exit                   ";
		std::cout << "\n           your choice      :         ";
		std::cin >> a;
		if (a == 1)
		{
			M_menu();
		}
		else if (a == 2)
		{
			L_menu();
		}
		else if (a == 3)
		{
			B_menu();
		}
		else if (a == 4)
		{
			Ma_menu();
		}
		else if (a == 5)
		{
			T_menu();
		}
		else if (a == 6)
		{
			A_menu();
		}
		else if (a == 7)
		{
			return;
		}
	}

}
int main()
{
	main_menu();
	_getch();
	return 0;
};
