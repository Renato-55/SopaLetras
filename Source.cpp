#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "Header.h"
using namespace std;

void setForeColor(int x = 15)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //just once	
	SetConsoleTextAttribute(color, x);
}

void get_disposicao(int* pos)
{
	srand(time(NULL));
	int aux;
	aux = rand() % 8;
	*pos = aux;
}

void gotoxy(int x, int y) {
	COORD c = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void show_titule()
{
	/* --------------------------------------------------------------------------------- */
	/* -------------- Imprime Soup letter em y aleatorios de 1 a 3 --------------------- */

	string titule = "SOUP LETTER";
	int aux;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 13; i++)
		{
			gotoxy(27 + i * 2, j + 2); std::cout << char(rand() % 26 + 65);
		}
	}
	for (int i = 0; i < 11; i++)
	{
		setForeColor(2);
		aux = rand() % 3;
		gotoxy(29 + i * 2, aux + 2); std::cout << titule[i];
		setForeColor();

		if (i == 4)
		{
			gotoxy(29 + i * 2, aux + 2); std::cout << char(rand() % 26 + 65);
		}
	}
	/* -------------------------- Fim da Funcao ---------------------------------------- */
	/* --------------------------------------------------------------------------------- */
}

void showVerticalWordAt(int x, int y, char c, int charNumber)
{
	setlocale(LC_ALL, "C");
	int i = 0;
	for (i = 0; i < charNumber; i++) {
		gotoxy(x, y + i);
		printf("%c", c);
	}

	setlocale(LC_ALL, "");
}

void Apresentacao()
{
	setForeColor(15);
	gotoxy(5, 3); cout << "Trabalho realizado por : ";
	setForeColor(11); gotoxy(10, 5); cout << "Renato Barbosa  "; setForeColor(6); cout << "- 70565";
	setForeColor(11); gotoxy(10, 6); cout << "Diogo Barbosa "; setForeColor(6); cout << "- 70569";
	setForeColor(15);
	gotoxy(5, 8); 
	cout << endl << "     ";
	Sleep(1000);

}

bool Ask_To_Get_out()
{
	char aux;
	gotoxy(0,32); cout << "                                                                 ";
	gotoxy(0,32); cout << "Pressione qualquer tecla para continuar, 0 para sair: ";
	aux = _getch();
	if (aux == '0')
		return true;

	return false;
}
