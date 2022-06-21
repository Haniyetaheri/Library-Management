#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include<string>
#include"Date.h"
#include"person.h"

class Librarian :public person
{
private:

	std::string Doucu, posta;

public:

	Librarian();
	Librarian(int i, std::string  F, std::string L, std::string I, Date B, std::string D, std::string P) :person(i, F, L, I, B), Doucu(D), posta(P) {}
	void r_data1();

	void setDoucu(std::string Doucu);
	void setposta(std::string  posta);

	std::string getDouc()const;
	std::string getposta()const;

	void Add1();
	void Edit1(int iid);
	void Delet1(int iid);
	void report1();
	void Serch1(int iid);

};

#endif
