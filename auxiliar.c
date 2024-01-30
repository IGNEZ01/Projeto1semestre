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

void SysPause(){

    #ifdef _WIN32
        system("pause");
    #else defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
        getchar();
    
    #endif

}

void SysCLS(){

    #ifdef _WIN32
        system("cls");
    #else defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
        system("clear");
    
    #endif


}

void MensagemErro(int erro){

    switch (erro)
    {
    case 1:
        SysCLS();
        printf("\t\t\t\tCHAVE DE SISTEMA ERRADA!!!");
        delay(1);
        MainMenu();
        break;
    
    default:
        break;
    }

}