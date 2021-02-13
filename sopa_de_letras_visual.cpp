// sopa_de_letras_visual.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <iomanip>
#include <time.h>
#include "Letra.h"
#include "Ponto.h"
#include "Player.h"
#include "Header.h"

using namespace std;

int main()
{
    Player jogador1;
    Letra sopa;
    Apresentacao();
    jogador1.read_nome();
    
    system("cls");
    /* Teste da classe letra*/
    sopa.Set_Random_Soup();
    sopa.Load_Words();

/*  cout << "\n\n";    system("pause");     system("cls");
    //Teste da classe Ponto
    Ponto ponto1, ponto2;   
    cout << "\n\n";    system("pause");     system("cls");
*/
 
   
/* Teste da classe jogador*/


    sopa.Print_Soup();
    sopa.Show_words_in_game();

    while (jogador1.get_pontuacao() < 10)
    {
        jogador1.show_pontuacao();
        if (sopa.ask_user_a_word())
        {
            jogador1.update_pontuacao();
        } 

        if (Ask_To_Get_out() == true)
        {
            exit (0);
        }
    }
  


cout << "\n\n";
}





