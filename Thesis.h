#ifndef THESIS_H
#define THESIS_H
#include<string>
#include"Date.h"
#include"Book.h"
class Thesis : public Book
{
public:
	Thesis();
	Thesis(std::string I, std::string T, std::string p, std::string gr, std::string f, std::string g, int a) :Book(I, T, p), grade(gr), faculty(f), group(g), avail_T(a) {}
	void setdata2();
	void setgrade(std::string grade);
	void setfaculty(std::string faculty);
	void setgroup(std::string group);
	void setavail_T(int avail_T);

	std::string getgrade();
	std::string getfaculty();
	std::string getgroup();
	int getavail_T();

	void Add4();
	void Edit4(std::string iid);
	void Delet4(std::string iid);
	void Serch4(std::string iid);
	void report_A4();

private:

	std::string grade, faculty, group;
	int  avail_T = 0;

};
#endif // !THESIS_H
