#ifndef BOOK_H
#define BOOK_H
#include<string>
#include"Date.h"
class Book// the father class for all types of writing
{
public:
	Book();
	Book(std::string ID, std::string Title, std::string p_count);
	void setData();
	void set_ID(std::string DI);
	void setTitle(std::string Title);
	void setp_count(std::string p_count);

	std::string get_ID()const;
	std::string getTitle()const;
	std::string getp_count()const;
protected:
	std::string ID, Title, p_count;

};

#endif
