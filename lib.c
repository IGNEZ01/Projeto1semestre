#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct_Pessoa.h"
#include <time.h>
#include "lib.h"
#include "users.c"

void Login()
{
    // instanciar a struct user com o nome find_user.
    user find_user;

    // limpa o terminal
    system("cls");

    // declaraçao de variaveis necessarias para a funçao
    char username[20];
    char password[20];
    char ch;
    int i = 0;
    int id = 0;
    int teste = 0;

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

    // escrita
    printf("\t\t\t\t    =====LOGIN=====\n");
    printf("\t\t\t\t   Nome de Utilidador:\n");

    // recebe o username
    scanf("%s", username);

    // escrita
    printf("\t\t\t\t        Password: \n");
    printf("\t\t\t\t      ");

    // "scanf" para a password em que so aparecem "*"
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            password[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else
        {
            password[i++] = ch;
            printf("*");
        }
    }
    // fim de "scanf" da password.

    // escrita
    printf("\n");
    printf("\t\t\t\t=======================================\n");

    // ciclo while responsavel por precorrer todo o ficheiro ate ser encontrada a informaçao pretendida
    while (teste = fread(&find_user, sizeof(user), 1, outfile) != NULL)
    {

        // condiçao de verificação para verificar o username e a password.
        // caso certo redireciona o utilizador para a pagina de menu de utilizador.
        if (strcmp(find_user.nome_utilizador, username) == 0 && strcmp(find_user.password, password) == 0)
        {
            id = find_user.id;
            printf("\nLogin successful.\n");
            system("cls");
            PMenuUser(id);
        }
    }
}

void PRegistarUser()
{ // metodo para mostrar o ecra de registo de novo utilizador e escrever para o ficheiro "accounts.dat"

    // instanciar a struct user com o nome find_user.
    user new_user;

    // limpa o terminal
    system("cls");

    // declaraçao de variaveis necessarias para a funçao
    char ch;
    int i = 0;

    // escrita e leitura do "formulario" de registo
    printf("Nome de Utilizador:\n");

    scanf("%s", new_user.nome_utilizador);

    printf("Primeiro e ultimo nome:\n");

    scanf(" %[^\n]s", new_user.nome);

    getchar();

    printf("\nIdade:");

    scanf("%d", &new_user.idade);

    getchar();

    printf("\nN.I.F.:");

    scanf("%d", &new_user.nif);

    getchar();

    printf("\nEmail:\n");

    gets(new_user.email);

    printf("\npassword:\n");

    // "scanf" para a password em que so aparecem "*"
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            new_user.password[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else
        {
            new_user.password[i++] = ch;
            printf("*");
        }
    }
    // fim de "scanf" da password.

    printf("\n");

    // new_user.id = rand()%100;
    new_user.id = (int)time(NULL);

    // instancia o ficheiro
    FILE *outfile;

    // abre o ficheiro em modo de
    outfile = fopen("accounts.dat", "a+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (outfile == NULL)
    {
        printf("Erro ao abrir ficheiro ");
        exit(1);
    }

    // escreve texto para o ficheiro
    if (fseek(outfile, 0, SEEK_SET) == 0)
    {
        printf("ponteiro movido");
    }

    // escreve a struct para o ficheiro
    fwrite(&new_user, sizeof(user), 1, outfile);

    // fecha o ficheiro
    fclose(outfile);
}

void mainMenu()
{ // funçao de mostra o menu inicial do sistema

    // limpa o terminal
    system("cls");

    // declaraçao de variaveis
    int choice;

    while (choice != 4)
    {
        printf("\t\t\t\t=====SISTEMA DE ALUGUER DE VEICULOS=====\n");
        printf("\t\t\t\t            1. Login\n");
        printf("\t\t\t\t            2. Registar-se\n");
        printf("\t\t\t\t            0. Fechar Sistema\n");
        printf("\t\t\t\t=======================================\n");
        printf("\t\t\t\t      ");
        scanf("%d", &choice);
        switch (choice)
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
            printf("\n\t\t\t\tObrigado por usar o sistema\n\n");
            delay(1);
            exit(0);
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
    return 0;
}
