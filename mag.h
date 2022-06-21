#ifndef MAG_H
#define MAG_H
#include<string>
#include"Date.h"
#include"Book.h"
class mag : public Book
{
public:
	mag();
	mag(std::string I, std::string T, std::string p, int N, int a) :Book(I, T, p), N_M(N), avail_M(a) {}
	void setN_M(int N_M);
	void setavail_M(int avail_M);

	int getN_M();
	int getavail_M();

	void add3();
	void Add3();
	void Edit3(std::string iid);
	void Delet3(std::string iid);
	void Serch3(std::string iid);
	void report_A2();

private:

	int N_M = 0, avail_M = 0;

};
#endif
