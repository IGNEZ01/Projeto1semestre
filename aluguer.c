#include <stdio.h>
#include <stdlib.h>
#include "aluguer.h"
#include "struct_Carro.h"
//#include "carro.c"

void SelecionarCarro(){

    char matricula[10];

    printf("\t\t\t\t\t  =========REGISTAR NOVO ALUGUER=====\n");
    printf("\t\t\t\t\tInserir a matricula do carro pretendido\n");

    gets(matricula);

    // instanciar a struct user com o nome find_user.
    Carro carro;


    // declaraçao de variaveis necessarias para a funçao
    int escolha = 0;

    // instancia o ficheiro
    FILE *file;

    // abre o ficheiro no modo de
    file = fopen("carros.dat", "a+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o ficheiro carros.dat\n\n");
        exit(1);
    }

    while (fread(&carro, sizeof(Carro), 1, file))
    {
        if (strcmp(carro.matricula, matricula) == 0)
        {
            printf("matricula match");
            break;
        }
    }
    


}

void PNovoAluguer(int id){

    // declaraçao de variaveis necessarias para a funçao
    int escolha = 0;

    while (escolha != 4)
    {
        printf("\t\t\t\t\t=========NOVO ALUGUER=====\n");
        printf("\t\t\t\t\t           1. Listar Carros disponiveis\n");
        printf("\t\t\t\t\t           2. Registar Aluguer\n");       
        printf("\t\t\t\t\t           0. Voltar\n");
        printf("\t\t\t\t\t=======================================\n");
        printf("\t\t\t\t\t      ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            system("cls");
            ListarCarros();
            system("pause");
            system("cls");
            break;
        case 2:
            printf("entrou");
            SelecionarCarro();
            system("pause");
            system("cls");
            break;

        case 0:
            system("cls");
            PMenuUser(id);

            break;

        default:
            system("cls");
            printf("\n\t\t\t\t\tInsira uma opcao valida\n\n");
            system("pause");

            system("cls");
            break;
        }
    }
    
}

void RemoverAluguer(){


    
}