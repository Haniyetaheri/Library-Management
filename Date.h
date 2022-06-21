#ifndef DATE_H
#define DATE_H
class Date//class for date piking
{
	friend Date operator+(int x, Date& D);
public:
	Date();
	Date(int d, int m, int y) : day(d), month(m), year(y) {}
	void r_d();
	void setDate(int d, int m, int y);
	void setD(int day);
	void setM(int month);
	void setY(int year);
	bool is_y(int Y);
	int d_o_m(int M, int Y);

	int getD();
	int getM();
	int getY();
	void print();

private:
	int day, month, year;
};
#endif // !DATE_H

