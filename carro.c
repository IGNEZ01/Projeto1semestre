#include <stdio.h>
#include <stdlib.h>
#include "carro.h"
#include "struct_Carro.h"


void RegistarCarro(){

    // instanciar a struct user com o nome find_user.
    Carro carro;

    // limpa o terminal
    system("cls");

    // declaraçao de variaveis necessarias para a funçao
    int i = 0;

    // escrita e leitura do "formulario" de registo
    printf("Marca:\n");

    scanf("%s", carro.marca);

    printf("Modelo do carro:\n");

    scanf(" %[^\n]s", carro.modelo);

    getchar();

    printf("\nCelindrada:");

    scanf("%d", &carro.celindrada);

    getchar();

    printf("Tipo de Combustivel");

    gets(carro.alimentacao);

    printf("\nIdade");

    scanf("%d", &carro.idade);

    getchar();

    printf("\nMatricula:\n");

    gets(carro.matricula);

    printf("\nLugares\n");

    scanf("%d", &carro.lugares);

    printf("\n");

    // user.id = rand()%100;
    carro.id = (int)time(NULL);

    // instancia o ficheiro
    FILE *outfile;

    // abre o ficheiro em modo de
    outfile = fopen("carros.dat", "a+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (outfile == NULL)
    {
        printf("Erro ao abrir ficheiro ");
        exit(1);
    }

    // escreve a struct para o ficheiro
    fwrite(&carro, sizeof(carro), 1, outfile);

    // fecha o ficheiro
    fclose(outfile);

}

void EstadoCarro(){

    

}

void AtualizarCarro(){



}

void EliminarCarro(){



}

