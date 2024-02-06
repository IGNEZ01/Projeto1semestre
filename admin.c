#include "admin.h"
#include "carro.c"
#include "struct_User.h"


void dashboardSistema(){

    int quantidade_carros = 0;
    int quantidade_users = 0;
    double faturacao_total = 0;
    double cache_faturacao = 0;
    int cache_carro_mais_alugado = 0;
    int id_mais_alugado = 0;
    char carro_mais_alugado[10];

    // instanciar a struct user com o nome read_user
    Carro read_car;
    User read_user;

    // instancia o ficheiro
    FILE *carros_file;
    FILE *user_file;

    // Abre o ficheiro "accounts.dat"
    carros_file = fopen("carros.dat", "rb+");
    user_file = fopen("accounts.dat", "rb+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (carros_file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o ficheiro carros.dat\n\n");
        exit(1);
    }

    if (user_file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o ficheiro accounts.dat\n\n");
        exit(1);
    }



    while (fread(&read_car, sizeof(Carro), 1, carros_file))
    {

        quantidade_carros = quantidade_carros + 1;
        cache_faturacao = read_car.preco_diario * read_car.dias_alugado;

        if (cache_carro_mais_alugado < read_car.dias_alugado)
        {
            cache_carro_mais_alugado = read_car.dias_alugado;
            id_mais_alugado = read_car.id;
        }
         

        faturacao_total = faturacao_total + cache_faturacao;

    }

    while (fread(&read_car, sizeof(Carro), 1, carros_file))
    {

        if (read_car.id == id_mais_alugado)
        {
            strcpy(carro_mais_alugado, read_car.matricula);
        }

    }

    while (fread(&read_user, sizeof(User), 1, user_file))
    {

        quantidade_users = quantidade_users + 1;

    }

    SysCLS();
    printf("\t\t\t\t\t=========DASHBOARD DO SISTEMA=====\n");
    printf("\t\t\t\t\t    Quantidade de Carros no Sistema: %d\n", quantidade_carros);
    printf("\t\t\t\t\t    Quantidade de Utilizadores no Sistema: %d\n", quantidade_users);
    printf("\t\t\t\t\t    Faturacao total: %.2f\n", faturacao_total);
    printf("\t\t\t\t\t=======================================\n");
    printf("\t\t\t\t\t      ");

    fclose(carros_file);
    fclose(user_file);

    SysPause();

}

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
    file = fopen("accounts.dat", "rb+");

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
        printf("\t\t\t\t\t           6. Dashboard\n");
        printf("\t\t\t\t\t           7. Informaçoes de Utilizador\n");
        printf("\t\t\t\t\t           8. Remover aluguer\n");
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

        case 6:
            SysCLS();
            dashboardSistema();
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
