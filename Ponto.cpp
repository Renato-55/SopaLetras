#include "Ponto.h"
#include "Header.h"
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>

using namespace std;
Ponto::~Ponto()
{
}

Ponto::Ponto()
{
	x = 1;
	y = 1;
}

Ponto::Ponto(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Ponto::update_point(int _x, char _y)
{
	this -> x = _x;

	if (_y >= 97  && _y <= 116)
	{
		_y = _y - 32;
	}


	int i = 0;
	while (char(65+i) != _y)
	{
		i++;
	}

	y = i ;

}

void Ponto::show_Point()
{
	gotoxy(1, 36); cout << "                                                    ";
	gotoxy(1, 36); cout << "Ponto : x -> " << x+1 << " | y -> " << y+1 << endl;
}

void Ponto::read_point () {
	
	int _x_aux ;
	char _x[10];
	char _y;
	int _y_aux;
	gotoxy(0, 33); cout << "                               ";
	gotoxy(0, 34); cout << "                              ";
	do
	{
	gotoxy(1, 33);cout << "Digite um numero (x) : ";
	cin >> _x;
	_x_aux = atoi(_x);
	gotoxy(0, 33); cout << "                               ";
	gotoxy(0, 34); cout << "                              ";
	}while (_x_aux <= 0 || _x_aux > 20 );

	do
	{
		gotoxy(1, 33); cout << "Digite um carater (y) : ";
		cin >> _y;
		this->update_point(_x_aux, _y);
		_y_aux = y;
		gotoxy(0, 33); cout << "                               ";
		gotoxy(0, 34); cout << "                              ";
	} while (_y_aux < 0 || _y_aux > 20);

	_x_aux += -1;

	this->update_point(_x_aux, _y);
	this->show_Point();

}

void Ponto::two_Points(Ponto& p1)
{
	
	gotoxy(0, 32); cout << "                                                                 ";
	gotoxy(0,32); cout << "Primeiro Ponto: "; this->read_point();
	gotoxy(0,32); cout << "Segundo Ponto: "; p1.read_point();

}

bool Ponto::big_x(const Ponto p1)
{
	if (this->get_x() > p1.x )
		return true;

	return false;
}

bool Ponto::big_y(const Ponto p1)
{
	if (this->get_y() > p1.y)
		return true;

	return false;
}

void Ponto::swap_Point_if_big_x(Ponto& p1)
{
	int _x;
	int _y;
	if (this->big_x(p1))
	{
		_x = this->get_x();
		_y = this->get_y();

		p1.x = this->get_x();
		p1.y = this->get_y();
		
		this->set_x(_x);
		this->set_y(_y);
	}

	if (this->get_x() == p1.get_x())
	{
		if (this->big_y(p1))
		{
			_x = this->get_x();
			_y = this->get_y();

			p1.x = this->get_x();
			p1.y = this->get_y();

			this->set_x(_x);
			this->set_y(_y);
		}
	}

}

bool Ponto::both_cord_dif(const Ponto p1)
{
	if (this->get_x() != p1.x)
	{
		if (this->get_y() != p1.y)
		{
			return true;
		}
	}

	return false;
}

void clear_Point()
{
	gotoxy(1, 36); cout << "                                                    ";
}