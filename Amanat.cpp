#include "Amanat.h"
#include"Date.h"
#include"person.h"
#include "Book.h"
#include "Book_b.h"
#include "Thesis.h"
#include "Librarian.h"
#include "mag.h"
#include "Member.h"
#include <iostream>
#include<cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
// Functions related to the lending library class :

std::vector<Book_b>list_b1, list_b12;
std::vector<Thesis>list_T1, list_T12;
std::vector<mag>list_m1, list_m12;
std::vector<Member>list_M1, list_M21;
// constructor and access functions of lending library class :
Amanat::Amanat()
{
}
Amanat::Amanat(int io, std::string in, Date a, Date t) :id_ozv(io), id_neveshtar(in), A(a), T(t) {}
void Amanat::setamant()
{
	int io, d, d2, m, y;
	std::string in;
	Date a, t;

	std::cout << "\n\n  enter ID of member     :   ";
	std::cin >> io;
	setio(io);

	std::cout << "\n\n  enter ID of Documents  : ";
	std::cin >> in;
	setin(in);

	std::cout << "\n\n  enter Date of Check out : ";
	std::cout << "\n  enter day   : ";
	std::cin >> d;
	std::cout << "\n  enter month : ";
	std::cin >> m;
	std::cout << "\n  enter year  : ";
	std::cin >> y;
	a.setDate(d, m, y);
	set_A(a);

	d2 = d + 7;
	t.setDate(d2, m, y);
	set_T(t);

}
void Amanat::setio(int io)
{
	id_ozv = io;
}
void Amanat::setin(std::string in)
{
	id_neveshtar = in;
}
void Amanat::set_A(Date a)
{
	A = a;
}
void Amanat::set_T(Date t)
{
	T = t;
}

int Amanat::getio()
{
	return id_ozv;
}
std::string Amanat::getin()
{
	return id_neveshtar;
}
Date Amanat::get_A()
{
	return A;
}
Date Amanat::get_T()
{
	return T;
}


std::vector<Amanat>list_A, list_A2;
std::ofstream file_A;
void Amanat::enter0()//The functiont to check user information in order to record new information 
{
	int id, c_n = 0;
	std::cout << "\n  enter your ID : ";
	std::cin >> id;
	std::ifstream file_A("Amanat.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	std::string e;
	int e1, e2, e3, e4, e5, e6, e7;
	if (!file_A)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_A.eof())
	{
		file_A >> e1;
		file_A >> e;
		file_A >> e2;
		file_A >> e3;
		file_A >> e4;
		file_A >> e5;
		file_A >> e6;
		file_A >> e7;
		Date d1(e2, e3, e4);
		Date d2(e5, e6, e7);
		Amanat A(e1, e, d1, d2);
		list_A.push_back(A);
	}
	for (int i = 0; i < list_A.size(); i++)
	{
		if (list_A[i].id_ozv == id)
		{
			int t1, t2, t3, t4, t5, t6;
			Date d3 = list_A[i].A;
			t1 = d3.getD();
			t2 = d3.getM();
			t3 = d3.getY();
			Date d4 = list_A[i].T;
			t4 = d4.getD();
			t5 = d4.getM();
			t6 = d4.getY();
			temp << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;
			c_n++;
		}
		else if (list_A[i].id_ozv != id)
		{
			int t1, t2, t3, t4, t5, t6;
			Date d3 = list_A[i].A;
			t1 = d3.getD();
			t2 = d3.getM();
			t3 = d3.getY();
			Date d4 = list_A[i].T;
			t4 = d4.getD();
			t5 = d4.getM();
			t6 = d4.getY();
			temp << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;
		}
	}
	file_A.close();
	temp.close();
	if (remove("Amanat.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Amanat.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
	if (c_n >= 3)
	{
		std::cout << "\n you may not post new entries !";
	}
	else if (c_n < 3)
	{
		std::cout << "\n you can ";
		enter();
	}

}
void Amanat::enter()// function to record new information 
{
	Amanat a;
	std::string id;
	std::cout << "\n\n   enter ID of Documents : ";
	std::cin >> id;
	int j;
	if (id[0] == 'B')
	{
		j = e1(id);
	}
	else if (id[0] == 'm')
	{
		j = e2(id);
	}
	else if (id[0] == 'T')
	{
		j = e3(id);
	}
	if (j == 1)
	{
		Date a1, a2;
		int d, d1, m, m1, y, y1;
		a.setamant();
		list_A.push_back(a);
		std::ofstream file_A("Amanat.txt", std::ios::app);
		if (!file_A)
		{
			std::cout << " the filecan not be opend " << "\n";
		}
		a1 = a.A;
		d = a1.getD();
		m = a1.getM();
		y = a1.getY();
		a2 = a.T;
		d1 = a2.getD();
		m1 = a2.getM();
		y1 = a2.getY();
		file_A << a.id_ozv << "   " << a.id_neveshtar << "   " << d << " " << m << " " << y << "    " << d1 << " " << m1 << " " << y1 << std::endl;
		file_A.close();
		std::cout << " entered \n";
	}
	else
	{
		std::cout << "\n  not exist  \n";
	}
}
//functions to check Books files tocheck inventory
int Amanat::e1(std::string iid)
{
	int j = 0;
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
		list_b1.push_back(b);
	}
	for (int i = 0; i < list_b1.size(); i++)
	{

		if (list_b1[i].get_ID() == iid)
		{
			if (j != 1)
			{
				if (list_b1[i].getavail() >= 1)
				{
					int B = list_b1[i].getavail();
					B--;
					list_b1[i].setavail(B);
					temp << list_b1[i].get_ID() << "   " << list_b1[i].getTitle() << "   " << list_b1[i].getp_count() << "   " << list_b1[i].getrang() << "   " << list_b1[i].getN_B() << "   " << list_b1[i].getavail() << std::endl;
					j = 1;
				}
			}
		}
		else if (list_b1[i].get_ID() != iid)
		{

			temp << list_b1[i].get_ID() << "   " << list_b1[i].getTitle() << "   " << list_b1[i].getp_count() << "   " << list_b1[i].getrang() << "   " << list_b1[i].getN_B() << "   " << list_b1[i].getavail() << std::endl;
		}

	}

	file_b.close();
	temp.close();
	if (remove("Books.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Books.txt") != 0)
		std::cout << "error in renaming output file " << "\n";

	return j;

}
int Amanat::e2(std::string iid)
{
	int j = 0;
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
		list_m1.push_back(m);
	}
	for (int i = 0; i < list_m1.size(); i++)
	{
		if (list_m1[i].get_ID() == iid)
		{
			if (j != 1)
			{
				if (list_m1[i].getavail_M() > 1)
				{
					int M = list_m1[i].getavail_M();
					M--;
					list_m1[i].setavail_M(M);
					temp << list_m1[i].get_ID() << "   " << list_m1[i].getTitle() << "   " << list_m1[i].getp_count() << "   " << list_m1[i].getN_M() << "   " << list_m1[i].getavail_M() << std::endl;
					j = 1;
				}
			}
		}
		else if (list_m1[i].get_ID() != iid)
		{
			temp << list_m1[i].get_ID() << "   " << list_m1[i].getTitle() << "   " << list_m1[i].getp_count() << "   " << list_m1[i].getN_M() << "   " << list_m1[i].getavail_M() << std::endl;
		}
	}

	file_m.close();
	temp.close();
	if (remove("magezins.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "magezins.txt") != 0)
		std::cout << "error in renaming output file " << "\n";

	return j;
}
int Amanat::e3(std::string iid)
{
	int j = 0;
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
		list_T1.push_back(T);
	}
	std::string m1, m2, m3;
	int a;
	for (int i = 0; i < list_T1.size(); i++)
	{
		if (list_T1[i].get_ID() == iid)
		{
			if (j != 1)
			{
				if (list_T1[i].getavail_T() == 1)
				{
					int T = list_T1[i].getavail_T();
					T--;
					list_T1[i].setavail_T(T);
					temp << list_T1[i].get_ID() << "   " << list_T1[i].getTitle() << "   " << list_T1[i].getp_count() << "   " << list_T1[i].getgrade() << "   " << list_T1[i].getfaculty() << "   " << list_T1[i].getgroup() << "   " << list_T1[i].getavail_T() << std::endl;
					j = 1;
				}
			}
		}
		else if (list_T1[i].get_ID() != iid)
		{
			temp << list_T1[i].get_ID() << "   " << list_T1[i].getTitle() << "   " << list_T1[i].getp_count() << "   " << list_T1[i].getgrade() << "   " << list_T1[i].getfaculty() << "   " << list_T1[i].getgroup() << "   " << list_T1[i].getavail_T() << std::endl;
		}
	}
	file_T.close();
	temp.close();
	if (remove("Thesis.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Thesis.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
	return j;
}

void Amanat::edit(int iid)//function to extend the tex or book delivery deadline
{
	int j = 0;
	std::string idd;
	std::cout << "\n enter ID of Documents  : ";
	std::cin >> idd;
	std::ifstream file_A("Amanat.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	std::string e;
	int e1, e2, e3, e4, e5, e6, e7;

	if (!file_A)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_A.eof())
	{
		file_A >> e1;
		file_A >> e;
		file_A >> e2;
		file_A >> e3;
		file_A >> e4;
		file_A >> e5;
		file_A >> e6;
		file_A >> e7;
		Date d1(e2, e3, e4);
		Date d2(e5, e6, e7);
		Amanat A(e1, e, d1, d2);
		list_A.push_back(A);
	}
	int a;
	for (int i = 0; i < list_A.size(); i++)
	{
		if (list_A[i].id_ozv == iid)
		{
			if (j != 1)
			{
				if (list_A[i].id_neveshtar == idd)
				{
					int t1, t2, t3, t4, t5, t6;
					Date d3 = list_A[i].A;
					t1 = d3.getD();
					t2 = d3.getM();
					t3 = d3.getY();
					Date d4 = list_A[i].T;
					d4 = 7 + d4;
					t4 = d4.getD();
					t5 = d4.getM();
					t6 = d4.getY();
					temp << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;
					std::cout << "\n Ok!!!  ";
					j = 1;
				}
				else if (list_A[i].id_neveshtar != idd)
				{
					int t1, t2, t3, t4, t5, t6;
					Date d3 = list_A[i].A;
					t1 = d3.getD();
					t2 = d3.getM();
					t3 = d3.getY();
					Date d4 = list_A[i].T;
					t4 = d4.getD();
					t5 = d4.getM();
					t6 = d4.getY();
					temp << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;

				}

			}

		}
		else if (list_A[i].id_ozv != iid)
		{
			int t1, t2, t3, t4, t5, t6;
			Date d3 = list_A[i].A;
			t1 = d3.getD();
			t2 = d3.getM();
			t3 = d3.getY();
			Date d4 = list_A[i].T;
			t4 = d4.getD();
			t5 = d4.getM();
			t6 = d4.getY();
			temp << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;

		}
	}

	file_A.close();
	temp.close();
	if (remove("Amanat.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Amanat.txt") != 0)
		std::cout << "error in renaming output file " << "\n";

}
void Amanat::delet(int iid)//function ror book delvery
{
	int j = 0;
	std::string idd, idi;
	std::cout << "\n enter ID of Documents  : ";
	std::cin >> idd;
	Date n;
	int ni;
	std::ifstream file_A("Amanat.txt", std::ios::in);
	std::ofstream temp("temp.txt", std::ios::out);
	std::string e;
	int e1, e2, e3, e4, e5, e6, e7;

	if (!file_A)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_A.eof())
	{
		file_A >> e1;
		file_A >> e;
		file_A >> e2;
		file_A >> e3;
		file_A >> e4;
		file_A >> e5;
		file_A >> e6;
		file_A >> e7;
		Date d1(e2, e3, e4);
		Date d2(e5, e6, e7);
		Amanat A(e1, e, d1, d2);
		list_A.push_back(A);
	}

	for (int i = 0; i <= list_A.size(); i++)
	{
		if (list_A[i].id_ozv == iid)
		{
			if (list_A[i].id_neveshtar == idd)
			{
				n = list_A[i].T;
				ni = list_A[i].id_ozv;
				idi = list_A[i].id_neveshtar;
				j = 1;
			}
			else if (list_A[i].id_neveshtar != idd)
			{
				int t1, t2, t3, t4, t5, t6;
				Date d3 = list_A[i].A;
				t1 = d3.getD();
				t2 = d3.getM();
				t3 = d3.getY();
				Date d4 = list_A[i].T;
				t4 = d4.getD();
				t5 = d4.getM();
				t6 = d4.getY();
				temp << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;
			}

		}
		else if (list_A[i].id_ozv != iid)
		{
			int t1, t2, t3, t4, t5, t6;
			Date d3 = list_A[i].A;
			t1 = d3.getD();
			t2 = d3.getM();
			t3 = d3.getY();
			Date d4 = list_A[i].T;
			t4 = d4.getD();
			t5 = d4.getM();
			t6 = d4.getY();
			temp << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;

		}
	}

	file_A.close();
	temp.close();
	if (remove("Amanat.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Amanat.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
	if (j == 1)
	{
		B_Fine(n, ni);
		if (idi[0] == 'B')
		{
			C_book(idi);
		}
		else if (idi[0] == 'm')
		{
			C_mag(idi);
		}
		else if (idi[0] == 'T')
		{
			C_pay(idi);
		}

	}

}
void Amanat::B_Fine(Date d3, int id)//functions to check and calculate the amount of the members fine
{
	int fine = 0;
	int f1 = 0, f2 = 0;
	int d, m, y, t4, t5, t6;
	std::cout << "\n\n  enter Date of Check in : ";
	std::cout << "\n  enter day   : ";
	std::cin >> d;
	std::cout << "\n  enter month : ";
	std::cin >> m;
	t4 = d3.getD();
	t5 = d3.getM();
	t6 = d3.getY();
	if (d > t4)
	{
		std::cout << "\n  you were fine !!!  ";
		if (m > t5)
		{
			f2 = m - t5;
			f2 = f2 * 30;
			f1 = d + f2;
			f1 = f1 - t4;
			f1 = f1 * 500;
			fine = f1;
		}
		else
		{
			f1 = d - t4;
			fine = f1;
		}
		B_edite(fine, id);
	}
	else if (d <= t4)
	{
		std::cout << "\n  no fine ";
	}


}
void Amanat::B_edite(int f, int id)//functions to edit the amount of the members fine
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
		list_M1.push_back(m);
	}
	std::string m1, m2, m3;
	for (int i = 0; i < list_M1.size(); i++)
	{
		if (list_M1[i].get_id() == id)
		{
			int fine = list_M1[i].getFine();
			fine = fine + f;
			list_M1[i].setFine(fine);
			Date d;
			d = list_M1[i].getBirth();
			int d1, m1, y1;
			d1 = d.getD();
			m1 = d.getM();
			y1 = d.getY();
			temp << list_M1[i].get_id() << "   " << list_M1[i].getname() << "   " << list_M1[i].getfamily() << "   " << list_M1[i].getID_C() << "   " << d1 << " " << m1 << " " << y1 << "   " << list_M1[i].getType() << "   " << list_M1[i].getSt_number() << "   " << list_M1[i].getFine() << std::endl;

		}
		else if (list_M1[i].get_id() != id)
		{
			Date d;
			d = list_M1[i].getBirth();
			int d1, m1, y1;
			d1 = d.getD();
			m1 = d.getM();
			y1 = d.getY();
			temp << list_M1[i].get_id() << "   " << list_M1[i].getname() << "   " << list_M1[i].getfamily() << "   " << list_M1[i].getID_C() << "   " << d1 << " " << m1 << " " << y1 << "   " << list_M1[i].getType() << "   " << list_M1[i].getSt_number() << "   " << list_M1[i].getFine() << std::endl;
		}
	}

	file_M.close();
	temp.close();
	if (remove("Members.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Members.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
}
//functions to edit and add the amount of the book
void Amanat::C_book(std::string bb)
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
		list_b1.push_back(b);
	}
	for (int i = 0; i < list_b1.size(); i++)
	{
		if (list_b1[i].get_ID() == bb)
		{
			int B = list_b1[i].getavail();
			B++;
			list_b1[i].setavail(B);
			temp << list_b1[i].get_ID() << "   " << list_b1[i].getTitle() << "   " << list_b1[i].getp_count() << "   " << list_b1[i].getrang() << "   " << list_b1[i].getN_B() << "   " << list_b1[i].getavail() << std::endl;

		}
		else if (list_b1[i].get_ID() != bb)
		{
			temp << list_b1[i].get_ID() << "   " << list_b1[i].getTitle() << "   " << list_b1[i].getp_count() << "   " << list_b1[i].getrang() << "   " << list_b1[i].getN_B() << "   " << list_b1[i].getavail() << std::endl;
		}
	}

	file_b.close();
	temp.close();
	if (remove("Books.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Books.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
}
void Amanat::C_mag(std::string mm)
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
		list_m1.push_back(m);
	}

	for (int i = 0; i < list_m1.size(); i++)
	{
		if (list_m1[i].get_ID() == mm)
		{
			int M = list_m1[i].getavail_M();
			M++;
			list_m1[i].setavail_M(M);
			temp << list_m1[i].get_ID() << "   " << list_m1[i].getTitle() << "   " << list_m1[i].getp_count() << "   " << list_m1[i].getN_M() << "   " << list_m1[i].getavail_M() << std::endl;

		}
		else if (list_m1[i].get_ID() != mm)
		{
			temp << list_m1[i].get_ID() << "   " << list_m1[i].getTitle() << "   " << list_m1[i].getp_count() << "   " << list_m1[i].getN_M() << "   " << list_m1[i].getavail_M() << std::endl;
		}
	}
	file_m.close();
	temp.close();
	if (remove("magezins.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "magezins.txt") != 0)
		std::cout << "error in renaming output file " << "\n";

}
void Amanat::C_pay(std::string p)
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
		list_T1.push_back(T);
	}

	for (int i = 0; i < list_T1.size(); i++)
	{
		if (list_T1[i].get_ID() == p)
		{
			int T = list_T1[i].getavail_T();
			T++;
			list_T1[i].setavail_T(T);
			temp << list_T1[i].get_ID() << "   " << list_T1[i].getTitle() << "   " << list_T1[i].getp_count() << "   " << list_T1[i].getgrade() << "   " << list_T1[i].getfaculty() << "   " << list_T1[i].getgroup() << "   " << list_T1[i].getavail_T() << std::endl;

		}
		else if (list_T1[i].get_ID() != p)
		{
			temp << list_T1[i].get_ID() << "   " << list_T1[i].getTitle() << "   " << list_T1[i].getp_count() << "   " << list_T1[i].getgrade() << "   " << list_T1[i].getfaculty() << "   " << list_T1[i].getgroup() << "   " << list_T1[i].getavail_T() << std::endl;
		}
	}

	file_T.close();
	temp.close();
	if (remove("Thesis.txt") != 0)
		std::cout << "error in deleting orginal file " << "\n";
	if (rename("temp.txt", "Thesis.txt") != 0)
		std::cout << "error in renaming output file " << "\n";
}
void Amanat::serch1(std::string s1)// search for a specific type of book borrowed
{
	std::ifstream file_A("Amanat.txt", std::ios::in);
	std::string e;
	int e1, e2, e3, e4, e5, e6, e7;
	if (!file_A)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_A.eof())
	{
		file_A >> e1;
		file_A >> e;
		file_A >> e2;
		file_A >> e3;
		file_A >> e4;
		file_A >> e5;
		file_A >> e6;
		file_A >> e7;
		Date d1(e2, e3, e4);
		Date d2(e5, e6, e7);
		Amanat A(e1, e, d1, d2);
		list_A.push_back(A);
	}
	for (int i = 0; i < list_A.size() - 1; i++)
	{
		if (list_A[i].id_neveshtar == s1)
		{
			int t1, t2, t3, t4, t5, t6;
			Date d3 = list_A[i].A;
			t1 = d3.getD();
			t2 = d3.getM();
			t3 = d3.getY();
			Date d4 = list_A[i].T;
			t4 = d4.getD();
			t5 = d4.getM();
			t6 = d4.getY();
			std::cout << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;

		}
	}
	file_A.close();
	_getch();
}
void Amanat::serch2(int s2)// search for books borrowed by a specific person 
{
	std::ifstream file_A("Amanat.txt", std::ios::in);
	std::string e;
	int e1, e2, e3, e4, e5, e6, e7;
	if (!file_A)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_A.eof())
	{
		file_A >> e1;
		file_A >> e;
		file_A >> e2;
		file_A >> e3;
		file_A >> e4;
		file_A >> e5;
		file_A >> e6;
		file_A >> e7;
		Date d1(e2, e3, e4);
		Date d2(e5, e6, e7);
		Amanat A(e1, e, d1, d2);
		list_A.push_back(A);
	}
	for (int i = 0; i < list_A.size() - 1; i++)
	{
		if (list_A[i].id_ozv == s2)
		{
			int t1, t2, t3, t4, t5, t6;
			Date d3 = list_A[i].A;
			t1 = d3.getD();
			t2 = d3.getM();
			t3 = d3.getY();
			Date d4 = list_A[i].T;
			t4 = d4.getD();
			t5 = d4.getM();
			t6 = d4.getY();
			std::cout << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;

		}
	}
	file_A.close();
	_getch();
}
void Amanat::Report()//A repert of people who have to deliver books on a certain data
{
	int d, m;
	std::cout << "\n\n  enter Date of Today : ";
	std::cout << "\n  enter day   : ";
	std::cin >> d;
	std::cout << "\n  enter month : ";
	std::cin >> m;
	std::ifstream file_A("Amanat.txt", std::ios::in);
	std::string e;
	int e1, e2, e3, e4, e5, e6, e7;
	if (!file_A)
	{
		std::cout << " the filecan not be opend " << "\n";
	}
	while (!file_A.eof())
	{
		file_A >> e1;
		file_A >> e;
		file_A >> e2;
		file_A >> e3;
		file_A >> e4;
		file_A >> e5;
		file_A >> e6;
		file_A >> e7;
		Date d1(e2, e3, e4);
		Date d2(e5, e6, e7);
		Amanat A(e1, e, d1, d2);
		list_A.push_back(A);
	}
	for (int i = 0; i < list_A.size() - 1; i++)
	{
		int t4, t5;
		Date d4 = list_A[i].T;
		t4 = d4.getD();
		t5 = d4.getM();
		if (t4 == d && t5 == m)
		{
			int t1, t2, t3, t6, t7, t8;
			Date d3 = list_A[i].A;
			t1 = d3.getD();
			t2 = d3.getM();
			t3 = d3.getY();
			Date d5 = list_A[i].T;
			t6 = d5.getD();
			t7 = d5.getM();
			t8 = d5.getY();
			std::cout << list_A[i].id_ozv << "   " << list_A[i].id_neveshtar << "   " << t1 << " " << t2 << " " << t3 << "   " << t4 << " " << t5 << " " << t6 << std::endl;
			
		}
	}
	file_A.close();
    _getch();
}
