#include "auxiliar.h"
#include <time.h>
#include "menu_Principal.h"

void delay(int number_of_seconds)
{
    // converte o tempo para milisegundos
    int milli_seconds = 1000 * number_of_seconds;

    // armazena o inicio
    clock_t start_time = clock();

    // em loop enquanto o tempo desejado nao é atingido
    while (clock() < start_time + milli_seconds);
}

int VerifAdmin(int permicoes){



}

void MensagemErro(int erro){

    switch (erro)
    {
    case 1:
        system("cls");
        printf("\t\t\t\tCHAVE DE SISTEMA ERRADA!!!");
        delay(1);
        MainMenu();
        break;
    
    default:
        break;
    }

}