#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct_User.h"
#include <time.h>
#include "users.h"

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void PMenuUser(int id)
{

    // instanciar a struct user com o nome find_user.
    user selected_user;

    // limpa o terminal
    system("cls");

    // declaraçao de variaveis necessarias para a funçao
    int escolha = 0;

    // instancia o ficheiro
    FILE *outfile;

    // abre o ficheiro no modo de
    outfile = fopen("accounts.dat", "a+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opening accounts.dat\n\n");
        exit(1);
    }

    printf("Id User: %d\n", id);

    while (escolha != 4)
    {
        printf("\t\t\t\t\t=========PERFIL DE CLIENTE=====\n");
        printf("\t\t\t\t\t           1. \n");
        printf("\t\t\t\t\t           2. Registar-se\n");
        printf("\t\t\t\t\t           0. \n");
        printf("\t\t\t\t\t           0. Terminar Sessao\n");
        printf("\t\t\t\t\t           0. Terminar Sessao\n");
        printf("\t\t\t\t\t           0. \n");
        printf("\t\t\t\t\t           7. Alterar Password\n");
        printf("\t\t\t\t\t           0. Terminar Sessao\n");
        printf("\t\t\t\t\t=======================================\n");
        printf("\t\t\t\t\t      ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            system("cls");
            Login();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            PRegistarUser();
            system("pause");
            system("cls");

            break;

        case 0:
            system("cls");
            printf("\n\t\t\t\t\tA TERMINAR SESSAO...\n\n");
            delay(1);
            system("cls");
            mainMenu();

            break;

        default:
            system("cls");
            printf("\n\t\t\t\t\tInsira uma opcao valida\n\n");
            system("pause");

            system("cls");
            break;
        }
    }

    system("pause");
    system("cls");
}
