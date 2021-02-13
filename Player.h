#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> 
#include <windows.h>
using namespace std;
class Player
{
private:

	
	int pontuacao;
	string nome;

public:
	Player();
	Player(int _pontuacao, string nome);
	~Player();


	string get_nome() { return nome; };
	int get_pontuacao() { return pontuacao; };
	void set_pontuacao(int _pontuacao) { pontuacao = _pontuacao; };
	void set_nome(int _nome) { nome = _nome; };

	void read_nome();
	void update_pontuacao();
	void show_pontuacao();
	void reset_pontuacao() { pontuacao = 0; };
};

