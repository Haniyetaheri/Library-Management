#ifndef MEMBER_H
#define MEMBER_H
#include<string>
#include"Date.h"
#include"person.h"
class Member :public person
{
private:

	std::string Type, St_number;
	int Fine;

public:

	Member();
	Member(int i, std::string  F, std::string L, std::string I, Date B, std::string T, std::string St, int Fi = 0) :person(i, F, L, I, B), Type(T), St_number(St), Fine(Fi) {}
	void r_data();

	void setType(std::string Type);
	void setSt_number(std::string  St_number);
	void setFine(int  Fine);

	std::string getType()const;
	std::string getSt_number()const;
	int getFine()const;

	void Add();
	void Edit(int iid);
	void Delet(int iid);
	void report();
	void Serch(int iid);
	bool isexist(int iid);
	void Payment_F(int iid);

};
#endif // !MEMBER_H

