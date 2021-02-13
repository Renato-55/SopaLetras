#include "Letra.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <time.h>
#include <conio.h>
#include "Header.h"
using namespace std;
Letra::~Letra()
{
}

Letra::Letra()
{
	p1.update_point(0, 0);
	p2.update_point(0, 0);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			words[i][j] = ' ';
			words_fit_in[i][j] = true;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			words_used[i][j] = ' ';
		}
	}
	
}

Letra::Letra(bool _words_fit_in[20][20], char _words[20][20], char _words_used[20][10], Ponto _p1, Ponto _p2)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			words[i][j] = _words[i][j];
			words_fit_in[i][j] = _words_fit_in[i][j];
		}
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			words_used[i][j] = _words_used[i][j];
		}
	}
	p1 = _p1;
	p2 = _p2;
}

Letra::Letra(bool _words_fit_in[20][20], char _words[20][20], char _words_used[20][10], int  _x_p1, int _y_p1, int _x_p2, int _y_p2)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			words[i][j] = _words[i][j];
			words_fit_in[i][j] = _words_fit_in[i][j];
		}
	}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			words_used[i][j] = _words_used[i][j];
		}
	}
	p1.set_x(_x_p1);	p1.set_y(_y_p1);
	p2.set_x(_x_p2);	p2.set_y(_y_p2);

					
}

void Letra::Set_Random_Soup()
{
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			words[i][j] = char(rand() % 26 + 65);
		}
	}
}

void Letra::Print_Soup()
{
	system("cls");
	show_titule();

/*	cout << "\n\n\n\n\t      ";
	for (int i = 0; i < 20; i++)
		cout << setw(3) << i + 1;
*/
//	 E mais facil atraves da matriz booleana confirmar onde estao as palavras
/*	for (int i = 0; i < 20; i++)
	{
		cout << "\n\t";
		for (int j = 0; j < 20; j++)
		{
			if (j == 0)
			{
				cout << char(65 + i) << "\t";
			}
			cout << this->words_fit_in[i][j] << "  ";
		}
	} 
*/

	cout << "\n\n\n\n\t      ";
	for (int i = 0; i < 20; i++)
		cout << setw(3) << i + 1;

	cout << endl;

	for (int i = 0; i < 20; i++)
	{
		cout << "\n\t";
		for (int j = 0; j < 20; j++)
		{
			if (j == 0)
			{
				cout << char(65 + i) << "\t";
			}
			cout << this->words[i][j] << "  ";
		}
	}
}

void Letra::get_position(int* y, int* x)
{
	srand(time(NULL));
	int _aux, _aux_1;
	do
	{ 
	_aux = rand() % 20;
	*y = _aux;
	_aux_1 = rand() % 20;
	*x = _aux_1;
	} while (words_fit_in[_aux_1][_aux] == false);

}

void Letra::Load_Words() {
/********************************************************************************/
	srand(time(NULL));
	char aux1[20];
	ifstream is;
	is.open("LoadWords.txt");
	

//  vai buscar as palavras ao ficheiro de texto
	if (!is)
	{
		system("cls");
		cout << "Ficheiro nao abriu";
		system("pause");
		exit(0);
	}
	
	int n;
	char aux_v2[20][50];

	for (int i = 0; i < 50; i++)
	{
		is.getline(aux1, sizeof(aux1), '\n');	
		
		n= strlen(aux1);
		for (int j = 0; j <= n; j++)
		{
			aux_v2[j][i] = aux1[j];
		}

	}

/********************************************************************************/
//	Cria 10 numeros aleatorios que vao escolher as palavras a ser usadas na sopa de letras
	int aux_random[10];
	for (int i = 0; i < 10; i++)
	{
		aux_random[i] = rand() % 50;
		for (int j = 0; j < i; j++)
		{
			if (aux_random[j] == aux_random[i])
			{
				i--;
			}
		}
	}
	// ordena o vetor de numeros aleatorios
	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			if (aux_random[j] < aux_random[i] && i != j)
			{
				int aux_menor_maior=-1;
				aux_menor_maior = aux_random[j];
				aux_random[j] = aux_random[i];
				aux_random[i] = aux_menor_maior; 
				i = 0;
			}
		}
	}
	

	// Testes
	/*for (int i = 0; i < 10; i++)
	{
		cout << endl << aux_random[i];
	}*/


/********************************************************************************/

	// preencher o words_used
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (aux_random[j] == i)// colocar as palavras no words_used ;
			{
				//cout << endl;
				for (int d=0; d < 20; d++)
				{
					words_used[d][j] = aux_v2[d][i];

				/*	if (words_used[d][j] >= 'A' && words_used[d][j] <= 'Z')
					{
						cout << words_used[d][j];
					}*/
				}
			}
		}
	}

/********************************************************************************/
// Susbistituir a matriz de careteres da sopa com as palavras usadas
	

	int counter[10] = {0,0,0,0,0,0,0,0,0,0};
	int l = 0, k = 0;
	
	// conta o numero de letras em cada palavra;
	for (int i = 0; i < 10; i++)
	{
		l = 0;
		cout << endl;
		while (words_used[l][k] >= 'A' && words_used[l][k] <= 'Z')
		{
			counter[i]++;
			//cout << "\t" << counter[i] << " " << words_used[l][k];
			l++;
		}
		k++;
	}
	int numero_da_palavra = 0;
	bool FIT_IN = true;
	int x, y;
	int pos;


	// resetar a variaveis booleana words_fit_in
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			words_fit_in[i][j] = true;
		}
	}


	// posiciona as palavras na sopa de letras
	cout << "\n\t\t Colocar as palavras na mesa pode demorar um pouco ";
	setForeColor(2); cout << endl << "\n\t\t Loading \n     ";
	int aux_contador = 0;
	int aux_contado_v2 = 0;
	while(numero_da_palavra!= 10)
	{
		get_position(&y, &x);
		get_disposicao(&pos);
		FIT_IN = true;
	
		// working Ex 1-> PORTO    
		if (20 - x > counter [numero_da_palavra] && pos == 0) // posicao 1 
		{
			for (int i = 0; i < counter[numero_da_palavra]; i++)
			{
				if (!words_fit_in[y][x + i])
				{
					FIT_IN = false;
				}
			}
				if (FIT_IN==true)
				{
					for (int j = 0; j < counter[numero_da_palavra]; j++)
					{
						words[y][x + j] = words_used[j][numero_da_palavra];
						words_fit_in[y][x + j] = false;
					}
					numero_da_palavra++;
				}	
		}
		// working Ex 2-> OTROP	
		if (20 - x > counter[numero_da_palavra] &&  pos == 1)// posicao 2
		{
			for (int i = 0; i < counter[numero_da_palavra]; i++)
			{
				if (!words_fit_in[y][x + i])
				{
					FIT_IN = false;
				}
			}
			if (FIT_IN == true)
			{
				int j = 0;
				while (j < counter[numero_da_palavra])
				{
					words[y][x + j] = words_used[counter[numero_da_palavra]-j-1][numero_da_palavra];
					words_fit_in[y][x + j] = false;
					j++;
				}
				numero_da_palavra++;
			}
		}
		// working Ex 3-> PORTO ( para baixo no y ) 
		if (20 - y > counter[numero_da_palavra] &&  pos == 2)// posicao 3
		{
			for (int i = 0; i < counter[numero_da_palavra]; i++)
			{
				if (!words_fit_in[y + i][x] )
				{
					FIT_IN = false;
				}
			}
			if (FIT_IN == true)
			{
				for (int j = 0; j < counter[numero_da_palavra]; j++)
				{
					words[y + j][x] = words_used[j][numero_da_palavra];
					words_fit_in[y + j][x] = false;
				}
				numero_da_palavra++;
			}
		}
		// working Ex 4-> PORTO ( para cima no y ) 
		if (20 - y > counter[numero_da_palavra] &&  pos == 3)// posicao 4
		{
			for (int i = 0; i < counter[numero_da_palavra]; i++)
			{
				if (!words_fit_in[y + i][x])
				{
					FIT_IN = false;
				}
			}
			if (FIT_IN == true)
			{
				int j = 0;
				while (j < counter[numero_da_palavra])
				{
					words[y+j][x] = words_used[counter[numero_da_palavra] - j - 1][numero_da_palavra];
					words_fit_in[y+j][x] = false;
					j++;
				}
				numero_da_palavra++;
			}
		}
		// working Ex 5-> OTROP ( para baixo no y e para a direita no x    ( +x  | -y )  ) 
		if (20 - y > counter[numero_da_palavra] && 20 - x > counter[numero_da_palavra] &&  pos == 4 )// posicao 5
		{
			for (int i = 0; i < counter[numero_da_palavra]; i++)
			{
				if (!words_fit_in[y + i][x + i])
				{
					FIT_IN = false;
				}
			}
			if (FIT_IN == true)
			{
				int j = 0;
				while (j < counter[numero_da_palavra])
				{
					words[y + j][x + j] = words_used[counter[numero_da_palavra] - j - 1][numero_da_palavra];
					words_fit_in[y+j][x + j] = false;
					j++;
				}
				numero_da_palavra++;
			}
		}
		// working Ex 6-> PORTO ( para baixo no y e para a esquerda no x    ( +x  | -y )  )  
		if (20 - y > counter[numero_da_palavra] && 20 - x > counter[numero_da_palavra] &&  pos == 5)// posicao 6
		{
			for (int i = 0; i < counter[numero_da_palavra]; i++)
			{
				if (!words_fit_in[y + i][x + i])
				{
					FIT_IN = false;
				}
			}
			if (FIT_IN == true)
			{
				int j = 0;
				while (j < counter[numero_da_palavra])
				{
					words[y + j][x + j] = words_used[j][numero_da_palavra];
					words_fit_in[y + j][x + j] = false;
					j++;
				}
				numero_da_palavra++;
			}
		}
		// working Ex 7-> PORTO ( para cima no y e para a direita no x    ( +x  | +y )  )  
		if (20 - y < counter[numero_da_palavra] && 20 - x > counter[numero_da_palavra] &&  pos == 6)// posicao 7
		{
			for (int i = 0; i < counter[numero_da_palavra]; i++)
			{
				if (!words_fit_in[y - i][x + i])
				{
					FIT_IN = false;
				}
			}
			if (FIT_IN == true)
			{
				int j = 0;
				while (j < counter[numero_da_palavra])
				{
					words[y - j][x + j] = words_used[j][numero_da_palavra];
					words_fit_in[y - j][x + j] = false;
					j++;
				}
				numero_da_palavra++;
			}
		}
		// working Ex 8-> OTROP ( para cima no y e para a esquerda no x    ( +x  | +y )  ) 
		if (20 - y < counter[numero_da_palavra] && 20 - x > counter[numero_da_palavra] &&  pos == 7)// posicao 8
		{

			for (int i = 0; i < counter[numero_da_palavra]; i++)
			{
				if (!words_fit_in[y - i][x + i])
				{
					FIT_IN = false;
				}
			}
			if (FIT_IN == true)
			{
				int j = 0;
				while (j < counter[numero_da_palavra])
				{
					words[y - j][x + j] = words_used[counter[numero_da_palavra] - j - 1][numero_da_palavra];
					words_fit_in[y - j][x + j] = false;
					j++;
				}
				numero_da_palavra++;
			}
		}

		aux_contador++;
		if (aux_contador % 100000 == 0)
		{
			aux_contado_v2++;
		}
		if (aux_contado_v2 <= 100 && aux_contador %   100000 == 0)
		{
			setForeColor(15); gotoxy(7 + aux_contado_v2, 15); cout << char(178);
			setForeColor(2); gotoxy(25, 13); cout << aux_contado_v2 << "%";
			setForeColor(15);
		}
		
	 }
	
	 gotoxy(25, 17); cout << "pressione alguma tecla para continuar";
	 cin.get();
/**********************************************************************************/

}

void Letra::Show_words_in_game()
{
	setForeColor(11);
	showVerticalWordAt(80,8,char(124),22);
	setForeColor(15);
	
	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (words_used[j][i] >= 'A' && words_used[j][i]<='Z')
			{
				gotoxy(82 + j, 10 + i * 2); cout << words_used[j][i];
			}
		}
	}

}

void Letra::Update_words_in_game()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			gotoxy(82 + j, 10 + i); cout << " ";
		}
	}
	Show_words_in_game();
}

void Letra::clear_word(int number_of_word)
{
	for (int i = 0; i < 20; i++)
	{
		words_used[i][number_of_word] = ' ';
	}
}

bool Letra::ask_user_a_word()
{
	int counter[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int l = 0, k = 0;
	// conta o numero de letras em cada palavra;
	for (int i = 0; i < 10; i++)
	{
		l = 0;
		cout << endl;
		while (words_used[l][k] >= 'A' && words_used[l][k] <= 'Z')
		{
			counter[i]++;
			//cout << "\t" << counter[i] << " " << words_used[l][k];
			l++;
		}
		k++;
	}

	
	p1.two_Points(p2);
	p1.swap_Point_if_big_x(p2); // para o p1 ser sempre o que possui o x mais pequeno, no caso de serem iguais, ve qual y é maior
	
	int size = 0;
	int test = 0;
	bool swap_lecture = false ;
	bool what_should_return = false;
	int word_to_get_out;

	// vamos avereguiar a direcao da palavra
	// Direção Norte - Sul e Sul - Norte working
	// Direção Oeste - Este e Este - Oeste working
	// Direção Suldoeste - Sudeste e Sudeste - Suldoeste working
	// Direção Nordeste - Noroeste e Noroeste - Nordeste working
	if (p1.get_x() == p2.get_x())// y varia | x igual
	{
		size = p2.get_y() - p1.get_y() + 1;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < size; i++)// working // o palavra começa em cima com direcao para sul(baixo)
			{
				if (words[p1.get_y() + i][p1.get_x()] == words_used[i][j])
				{
					test++;
				}
				else if (words[p1.get_y() + i][p1.get_x()] != words_used[i][j])
				{
					test = 0;
				}
				if (test == size)
				{
					what_should_return = true;
					word_to_get_out = j;
					break;
				}
			}

			if (j == 9)
			{
				if (!swap_lecture)
				{
					swap_lecture = true;
					j = 0; test = 0;
				}
			}

			if (swap_lecture)// working // o palavra começa em baixo com direcao para norte(baixo)
			{
				for (int i = 0; i < size; i++)
				{
					if (words[p2.get_y() - i][p1.get_x()] == words_used[i][j])
					{
						test++;
					}
					else if (words[p2.get_y() - i][p1.get_x()] != words_used[i][j])
					{
						test = 0;
					}
					if (test == size)
					{
						what_should_return = true;
						word_to_get_out = j;
						break;
					}
				}
			}
		}
	}

	if (p1.get_y() == p2.get_y())// y igual | x varia
	{
		size = p2.get_x() - p1.get_x() + 1;
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < size; i++)
			{
				if (words[p1.get_y()][p1.get_x() + i] == words_used[i][j])
				{
					test++;
				}
				else if (words[p1.get_y()][p1.get_x() + i] != words_used[i][j])
				{
					test = 0;
				}
				if (test == size)
				{
					what_should_return = true;
					word_to_get_out = j;
					break;
				}
			}
			
			if (j == 9)
			{
				if (!swap_lecture)
				{
					swap_lecture = true;
					j = 0; test = 0;
				}
			}
		
			if (swap_lecture)
			{
				for (int i = 0; i < size; i++)
				{
					if (words[p1.get_y()][p2.get_x()-i] == words_used[i][j])
					{
						test++;
					}
					else if (words[p1.get_y()][p1.get_x() - i] != words_used[i][j])
					{
						test = 0;
					}
					if (test == size)
					{
						what_should_return = true;
						word_to_get_out = j;
						break;
					}
				}
			}
		}
	}

	if (p1.both_cord_dif(p2)/* && !p1.big_y(p2)*/) // Ambas as cordenadas diferentes, palavras na diagonal palavra
	{
		size = p2.get_x() - p1.get_x() + 1;// p1 vai ser sempre o menor x, o ponto inicial, neste caso, com y inicial menor
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < size; i++)
			{
				if (words[p1.get_y() - i][p1.get_x() + i] == words_used[i][j])
				{
					test++;
				}
				else if (words[p1.get_y() - i][p1.get_x() + i] != words_used[i][j])
				{
					test = 0;
				}
				if (test == size)
				{
					what_should_return = true;
					word_to_get_out = j;
					break;
				}
			}
		
			if (j == 9)
			{
				if (!swap_lecture)
				{
					swap_lecture = true;
					j = 0; test = 0;
				}
			}

			if (swap_lecture)
			{
				for (int i = 0; i < size; i++)
				{
					if (words[p2.get_y()-i][p2.get_x() - i] == words_used[i][j])
					{
						test++;
					}
					else if (words[p2.get_y() - i][p2.get_x() - i] != words_used[i][j])
					{
						test = 0;
					}
					if (test == size)
					{
						what_should_return = true;
						word_to_get_out = j;
						break;
					}
				}
			}
		}
	}

	if (p1.both_cord_dif(p2)/* && p1.big_y(p2)*/)
	{
		size = p2.get_x() - p1.get_x() + 1;// p1 vai ser sempre o menor x, o ponto inicial, neste caso, com y inicial menor
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < size; i++)
			{
				if (words[p1.get_y() + i][p1.get_x() + i] == words_used[i][j])
				{
					test++;
				}
				else if (words[p1.get_y() + i][p1.get_x() + i] != words_used[i][j])
				{
					test = 0;
				}
				if (test == size)
				{
					what_should_return = true;
					word_to_get_out = j;
					break;
				}
			}

			if (j == 9)
			{
				if (!swap_lecture)
				{
					swap_lecture = true;
					word_to_get_out = j;
					j = 0; test = 0;
				}
			}

			if (swap_lecture)
			{
				for (int i = 0; i < size; i++)
				{
					if (words[p2.get_y() - i][p2.get_x() - i] == words_used[i][j])
					{
						test++;
					}
					else if (words[p2.get_y() - i][p2.get_x() - i] != words_used[i][j])
					{
						test = 0;
					}
					if (test == size)
					{
						what_should_return = true;
						break;
					}
				}
			}
		}
	}


	if (what_should_return)
	{
		clear_word(word_to_get_out);
		_sleep(500);
		Update_words_in_game();
		return true;
	}

		
	return false;
}












