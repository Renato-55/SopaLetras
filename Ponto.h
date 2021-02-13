#pragma once
#include <fstream>

class Ponto
{
private:
	int x;
	int y;

public:
	Ponto();
	Ponto(int _x, int _y);
	~Ponto();

	int get_x() { return x; }
	int get_y() { return y; }
	void set_x(int _x) { x = _x; }
	void set_y(int _y) { y = _y; }

	void update_point(int _x, char _y);
	void show_Point();
	void read_point();
	void clear_Point();
	void two_Points(Ponto& p1);

	bool big_x(const Ponto p1);
	bool big_y(const Ponto p1);
	void swap_Point_if_big_x(Ponto& p1);

	bool both_cord_dif(const Ponto p1);

};

