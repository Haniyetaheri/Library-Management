#ifndef AMANAT_H
#define AMANAT_H
#include<string>
#include"Date.h"
#include"person.h"
#include "Book.h"
#include "Book_b.h"
#include "Librarian.h"
#include "mag.h"
#include "Member.h"
class Amanat//lending library class :
{
public:
	Amanat();
	Amanat(int io, std::string in, Date a, Date t);

	void setamant();
	void setio(int io);
	void setin(std::string in);
	void set_A(Date a);
	void set_T(Date t);

	int getio();
	std::string getin();
	Date get_A();
	Date get_T();

	void enter0();
	void enter();
	int e1(std::string iid);
	int e2(std::string iid);
	int e3(std::string iid);
	void edit(int iid);
	void delet(int iid);
	void B_Fine(Date d3, int id);
	void B_edite(int f, int id);
	void C_book(std::string bb);
	void C_mag(std::string mm);
	void C_pay(std::string p);
	void serch1(std::string s1);
	void serch2(int s2);
	void Report();

private:
	int id_ozv;
	std::string id_neveshtar;
	Date A;
	Date T;
};
#endif // !AMANAT_H

