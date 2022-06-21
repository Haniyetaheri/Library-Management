#ifndef BOOK_B_H
#define BOOK_B_H
#include<string>
#include"Date.h"
#include"Book.h"
class Book_b : public Book//
{
public:
	Book_b();
	Book_b(std::string I, std::string T, std::string p, std::string ra, int N, int a) :Book(I, T, p), rang(ra), N_B(N), avail(a) {}
	void setdata1();
	void setN_B(int N_B);
	void setrang(std::string rang);
	void setavail(int avail);

	int getN_B();
	std::string getrang();
	int getavail();

	void add2();
	void Add2();
	void Edit2(std::string iid);
	void Delet2(std::string iid);
	void Serch2(std::string iid);
	void report_A();
	void report_S(std::string rang);

private:

	std::string  rang;
	int N_B = 0, avail = 0;

};
#endif
