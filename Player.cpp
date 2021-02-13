#include "Player.h"
#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
Player::~Player()
{
}
Player::Player()
{
	pontuacao = 0;
	nome = "";
}
Player::Player(int _pontuacao,string _nome )
{
	pontuacao = _pontuacao;
	nome = _nome;
}
void Player::read_nome()
{
	string _nome;
	cout << "Digite o seu nome : ";
	cin >> _nome;

	nome = _nome;
}
void Player::show_pontuacao()
{ 
	gotoxy(80, 5); cout << "Nome " << this->get_nome();
	gotoxy(80, 6); cout << "Pontuacao ";
	gotoxy(90, 6); cout << "      ";
	gotoxy(90, 6); cout << this->get_pontuacao();
}
void Player::update_pontuacao() 
{
	pontuacao = pontuacao + 1;
	setForeColor(2);
	for (int i = 0; i < 4; i++)
	{
		Sleep(400);
		gotoxy(90, 6); cout << " + 1";
		Sleep(400);
		gotoxy(90, 6); cout << "    ";
	}
	setForeColor(15);
};