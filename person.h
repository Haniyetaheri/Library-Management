#ifndef PERSON_H
#define PERSON_H
#include<string>
#include"Date.h"
class person// the father class for all types of person
{
public:
	person();
	person(int i, std::string  F, std::string L, std::string I, Date B) :id(i), F_name(F), L_name(L), ID_card(I), Birth(B) {}
	void R_data();
	void set_id(int id);
	void setname(std::string name);
	void setfamily(std::string L_name);
	void setID_C(std::string ID_card);

	int get_id()const;
	std::string getname()const;
	std::string getfamily()const;
	std::string getID_C()const;
	Date getBirth();

protected:
	int id;
	std::string F_name, L_name;
	std::string ID_card;
	Date Birth;
};
#endif // !PERSON_H

