#include <string>
#include <time.h>
#include "Ponto.h"

class Letra
{
private:
	char words[20][20];
	bool words_fit_in[20][20];
	char words_used[20][10];
	Ponto p1;
	Ponto p2;
public:
	Letra();
	Letra(bool _words_fit_in[20][20], char _words[20][20], char _words_used[20][10], Ponto _p1, Ponto _p2);
	Letra(bool _words_fit_in[20][20], char _words[20][20], char _words_used[20][10], int  _x_p1, int _y_p1, int _x_p2, int _y_p2);
	~Letra();

	void clear_word(int number_of_word);

	void Set_Random_Soup();
	void get_position(int* x, int* y);

	void Print_Soup();
	void Show_words_in_game();
	void Update_words_in_game();

	void Load_Words();
	
	bool ask_user_a_word();
	
};

