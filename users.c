#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct_User.h"
#include "users.h"
#include "auxiliar.c"

// chave do sistema
char chave_sistema[10] = "eYKoQFNc8N";
char chave_inserida[10];

void InfoUser(int id)
{

    // instanciar a struct user com o nome find_user.
    User user;

    // limpa o terminal
    // SysCLS();

    // instancia o ficheiro
    FILE *file;

    // abre o ficheiro no modo de
    file = fopen("accounts.dat", "r");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o ficheiro accounts.dat\n\n");
        exit(1);
    }

    while (fread(&user, sizeof(User), 1, file))
    {
        if (user.id == id)
        {
            SysCLS();
            printf("\t\t\t\t\t=========INFORMACOES DE PERFIL=====\n");
            printf("\t\t\t\t\t         Nome: %s\n", user.nome);
            printf("\t\t\t\t\t         Nome de utilizador: %s\n", user.nome_utilizador);
            printf("\t\t\t\t\t         Idade: %d\n", user.idade);
            printf("\t\t\t\t\t         N.I.F.: %d\n", user.nif);
            printf("\t\t\t\t\t         Email: %s\n", user.email);
            printf("\t\t\t\t\t=======================================\n");
            printf("\t\t\t\t\t      ");
            break;
        }
    }
    
    SysPause();
    SysCLS();
    fclose(file);
}

void PRegistarUser()
{ // metodo para mostrar o ecra de registo de novo utilizador e escrever para o ficheiro "accounts.dat"

    // instanciar a struct user com o nome find_user.
    User user;

    // limpa o terminal
    SysCLS();

    // declaraçao de variaveis necessarias para a funçao
    char ch;
    int i = 0;

    // escrita e leitura do "formulario" de registo
    printf("Nome de Utilizador:\n");

    scanf("%s", user.nome_utilizador);

    printf("Primeiro e ultimo nome:\n");

    scanf(" %[^\n]s", user.nome);

    getchar();

    printf("\nIdade:");

    scanf("%d", &user.idade);

    getchar();

    printf("\nN.I.F.:");

    scanf("%d", &user.nif);

    getchar();

    printf("\nEmail:\n");

    gets(user.email);

    printf("Novo utilizador é Admin?\n");
    printf("1 - Admin  |  0 - Cliente");

    scanf("%d", &user.permicoes);

    if (user.permicoes == 1)
    {
        printf("Insira a chave do sistema:");

        scanf("%s", chave_inserida);

        if (strcmp(chave_inserida, chave_sistema) != 0)
        {

            MensagemErro(1);
        }
        else
        {

            printf("MODO ADMIN\n");
        }
    }

    printf("\npassword:\n");

    // "scanf" para a password em que so aparecem "*"
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            user.password[i] = '\0';
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
            user.password[i++] = ch;
            printf("*");
        }
    }
    // fim de "scanf" da password.

    printf("\n");

    // user.id = rand()%100;
    user.id = (int)time(NULL);

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

    // escreve a struct para o ficheiro
    fwrite(&user, sizeof(user), 1, outfile);

    // fecha o ficheiro
    fclose(outfile);
}

void PMenuUser(int id)
{

    // instanciar a struct user com o nome find_user.
    User user;

    // limpa o terminal
    SysCLS();

    // declaraçao de variaveis necessarias para a funçao
    int escolha = 0;

    // instancia o ficheiro
    FILE *file;

    // abre o ficheiro no modo de
    file = fopen("accounts.dat", "a+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening accounts.dat\n\n");
        exit(1);
    }

    while (fread(&user, sizeof(User), 1, file))
    {
        if (user.id == id)
        {
            break;
        }
    }

    printf("Ola %s\n", user.nome);

    while (escolha != 4)
    {
        printf("\t\t\t\t\t============PERFIL DE CLIENTE==========\n");
        printf("\t\t\t\t\t         1. Efetuar Aluger\n");
        printf("\t\t\t\t\t         2. Listar Carros disponiveis\n");
        printf("\t\t\t\t\t         3. Informaçoes de Utilizador\n");
        printf("\t\t\t\t\t         4. Alterar Password\n");
        printf("\t\t\t\t\t         0. Terminar Sessao\n");
        printf("\t\t\t\t\t=======================================\n");
        printf("\t\t\t\t\t      ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            SysCLS();
            NovoAluguer(id);
            SysPause();
            SysCLS();
            break;

        case 2:
            SysCLS();
            ListarCarrosDisponiveis();
            SysPause();
            SysCLS();
            break;

        case 3:
            SysCLS();
            InfoUser(id);
            SysPause();
            SysCLS();
            break;

        case 0:
            SysCLS();
            printf("\n\t\t\t\t\tA TERMINAR SESSAO...\n\n");
            delay(1);
            SysCLS();
            MainMenu();

            break;

        default:
            SysCLS();
            printf("\n\t\t\t\t\tInsira uma opcao valida\n\n");
            SysPause();

            SysCLS();
            break;
        }
    }

    SysPause();
    SysCLS();
    fclose(file);
}

void ApagarUser()
{
}

