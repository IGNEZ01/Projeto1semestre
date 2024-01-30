#include "admin.h"
#include "carro.c"
#include "struct_User.h"

void ListarClientes()
{

    // instanciar a struct user com o nome read_user
    User read_user;

    // instancia o ficheiro
    FILE *file;

    // Abre o ficheiro "accounts.dat"
    file = fopen("accounts.dat", "r");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o ficheiro accounts.dat\n\n");
        exit(1);
    }

    while (fread(&read_user, sizeof(User), 1, file))
    {
        printf("ID = %d Nome = %s  Nome de Utilizador = %s  Idade = %d   NIF= %d   Email = %s\n",
               read_user.id, read_user.nome, read_user.nome_utilizador, read_user.idade, read_user.nif, read_user.email);
    }

    fclose(file);
}

void PAdmin(int id)
{

    // instanciar a struct user com o nome user
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
        fprintf(stderr, "\nErro ao abrir o ficheiro accounts.dat\n\n");
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
        printf("\t\t\t\t\t===========PERFIL DE ADMINISTRADOR==========\n");
        printf("\t\t\t\t\t           1. Efetuar Aluger\n");
        printf("\t\t\t\t\t           2. listar clientes\n");
        printf("\t\t\t\t\t           3. listar carros\n");
        printf("\t\t\t\t\t           4. Registar novo carro\n");
        printf("\t\t\t\t\t           5. Remover Carro\n");
        printf("\t\t\t\t\t           6. Estatisticas Utilizadores\n");
        printf("\t\t\t\t\t           7. Informaçoes de Utilizador\n");
        printf("\t\t\t\t\t           8. Remover aluguer\n");
        printf("\t\t\t\t\t           8. Alterar Password\n");
        printf("\t\t\t\t\t           0. Terminar Sessao\n");
        printf("\t\t\t\t\t============================================\n");
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
            ListarClientes();
            SysPause();
            SysCLS();

            break;

        case 3:
            SysCLS();
            ListarCarros();
            SysPause();
            SysCLS();
            break;

        case 4:
            SysCLS();
            RegistarCarro();
            PAdmin(id);
            break;

        case 5:
            SysCLS();
            EliminarCarro();
            PAdmin(id);
            break;

        case 7:
            SysCLS();
            InfoUser(id);
            break;

        case 8:
            SysCLS();
            RemoverAluguer(id);
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
