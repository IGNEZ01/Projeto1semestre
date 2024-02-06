#include <stdio.h>
#include <stdlib.h>
#include "carro.h"
#include "struct_Carro.h"

void ListarCarrosDisponiveis()
{

    // instanciar a struct user com o nome read_user
    Carro read_car;

    // instancia o ficheiro
    FILE *file;

    // Abre o ficheiro "accounts.dat"
    file = fopen("carros.dat", "rb+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o ficheiro accounts.dat\n\n");
        exit(1);
    }

    while (fread(&read_car, sizeof(Carro), 1, file))
    {
        if (read_car.estado_alugado == 0)
        {
            printf("MARCA = %s MODELO: %s Matricula: %s COMBUSTIVEL: %s LUGARES: %d CELINDRADA: %d Preco: %d\n",
                   read_car.marca, read_car.modelo, read_car.matricula, read_car.alimentacao, read_car.lugares, read_car.celindrada, read_car.preco_diario);
        }
    }

    fclose(file);
}

void ListarCarros()
{

    // instanciar a struct user com o nome read_user
    Carro read_car;

    // instancia o ficheiro
    FILE *file;

    // Abre o ficheiro "accounts.dat"
    file = fopen("carros.dat", "rb+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o ficheiro accounts.dat\n\n");
        exit(1);
    }

    while (fread(&read_car, sizeof(Carro), 1, file))
    {
        printf("MARCA = %s MODELO: %s Matricula: %s COMBUSTIVEL: %s LUGARES: %d CELINDRADA: %d Disponibilidade: %d Preco: %d quantidade de alugueres: %d\n",
               read_car.marca, read_car.modelo, read_car.matricula, read_car.alimentacao, read_car.lugares, read_car.celindrada, read_car.estado_alugado, read_car.preco_diario, read_car.dias_alugado);
    }

    fclose(file);
}

void NovoAluguer(int id)
{

    char matricula[10];

    SysCLS();

    printf("\t\t\t\t\t  =========REGISTAR NOVO ALUGUER=====\n");
    printf("\t\t\t\t\tInserir a matricula do carro pretendido\n");

    printf("\t\t\t\t\t");

    scanf("%s", matricula);

    // instanciar a struct user com o nome find_user.
    Carro carro;

    // declaraçao de variaveis necessarias para a funçao
    int duracao_aluguer = 0;

    // instancia o ficheiro
    FILE *file;

    file = fopen("carros.dat", "rb+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (file == NULL)
    {
        fprintf(stderr, "\t\t\t\t\t\nERRO AO ABRIR O FICHEIRO carros.dat\n\n");
        exit(1);
    }

    while (fread(&carro, sizeof(Carro), 1, file))
    {

        if (strcmp(carro.matricula, matricula) == 0 && carro.estado_alugado == 0)
        {
            printf("\t\t\t\t\t Carro disponivel! \n");

            printf("\t\t\t\t\t Quantos dias sera o aluger? \n");

            printf("\t\t\t\t\t");

            scanf("%d", &duracao_aluguer);

            carro.dias_alugado = carro.dias_alugado + duracao_aluguer;
            carro.id_alugado = id;
            carro.estado_alugado = 1;

            fseek(file, -sizeof(Carro), SEEK_CUR);
            fwrite(&carro, sizeof(Carro), 1, file);
            SysPause();

            break;
        }
    }

    fclose(file);
    SysPause();
}

void RemoverAluguer(int id)
{

    // instancia as cariaveis necessarias para a funçao
    char matricula[10];

    // limpa o terminal
    SysCLS();

    // Visual
    printf("\t\t\t\t\t  ============REMOVER ALUGUER==========\n");
    printf("\t\t\t\t\t     Introduza a matricula do veiculo:\n");
    printf("\t\t\t\t\t                  ");

    // Le a matricula inserida pelo utilizador
    printf("\t\t\t\t\t");
    scanf("%s", matricula);

    // instanciar a struct user com o nome find_user.
    Carro carro;

    // instancia o ficheiro
    FILE *file;

    // abre o ficheiro no modo de
    file = fopen("carros.dat", "rb+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (file == NULL)
    {
        fprintf(stderr, "\t\t\t\t\t \nErro ao abrir o ficheiro carros.dat\n\n");
        exit(1);
    }

    while (fread(&carro, sizeof(Carro), 1, file))
    {
        if (strcmp(carro.matricula, matricula) == 0)
        {

            if (carro.id_alugado != 0)
            {
                SysCLS();

                carro.estado_alugado = 0;
                carro.id_alugado = 0;

                fseek(file, -sizeof(Carro), SEEK_CUR);
                fwrite(&carro, sizeof(Carro), 1, file);

                printf("\t\t\t\t\t  =========ALUGUER REMOVIDO=======\n");

                delay(2);
                fclose(file);
                SysCLS();
                break;
            }
            else
            {

                SysCLS();
                printf("\t\t\t\t\t  =========CARRO NAO ENCONTRADO=======\n");
                delay(2);
                fclose(file);
                SysCLS();
                break;
            }

            break;
        }
    }
}

void RegistarCarro()
{

    // instanciar a struct Carro com o nome carro.
    Carro carro;

    // limpa o terminal
    SysCLS();

    // declaraçao de variaveis necessarias para a funçao
    int i = 0;

    // escrita e leitura do "formulario" de registo
    printf("\t\t\t\t\t Marca:\n");

    printf("\t\t\t\t\t");

    scanf("%s", carro.marca);

    printf("\t\t\t\t\t Modelo do carro:\n");

    printf("\t\t\t\t\t");

    scanf(" %[^\n]s", carro.modelo);

    getchar();

    printf("\t\t\t\t\t Celindrada: \n");

    printf("\t\t\t\t\t");

    scanf("%d", &carro.celindrada);

    getchar();

    printf("\t\t\t\t\t Tipo de Combustivel: \n");

    printf("\t\t\t\t\t ");

    gets(carro.alimentacao);

    printf("\t\t\t\t\t Idade: \n");

    printf("\t\t\t\t\t");

    scanf(" %d", &carro.idade);

    getchar();

    printf("\t\t\t\t\t Matricula: \n");

    printf("\t\t\t\t\t");

    scanf("%s", carro.matricula);

    printf("\t\t\t\t\t Lugares: \n");

    printf("\t\t\t\t\t");

    scanf("%d", &carro.lugares);

    printf("\t\t\t\t\t Preco: \n");

    printf("\t\t\t\t\t");

    scanf("%d", &carro.preco_diario);

    printf("\t\t\t\t\t \n");

    // certifica que o carro esta sempre disponivel quando inserido
    carro.estado_alugado = 0;
    carro.dias_alugado = 0;

    // user.id = rand()%100;
    carro.id = (int)time(NULL);

    // instancia o ficheiro
    FILE *outfile;

    // abre o ficheiro em modo de
    outfile = fopen("carros.dat", "rb+");

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

void EliminarCarro()
{

    FILE *file;

    file = fopen("carros.dat", "rb+");

    Carro carro;

    long int controleFread;
    int id = 1;
    char matricula[10];

    if (file == NULL)
    {
        printf("Could not open file.\n");
        return;
    }
    else
    {
        printf("\t\t\t\t\t  =========REMOVER CARRO=======\n");
    }

    printf("\t\t\t\t\tDigite a matricula do carro que deseja remover: \n");
    scanf("%s", matricula);
    FILE *file2 = fopen("temp.dat", "ab+");
    if (file2 == NULL)
    {
        printf("\t\t\t\t\t  =========ERRO AO CRIAR ARQUIVO=======\n");
    }
    else
    {
        rewind(file);
        while (fread(&carro, sizeof(Carro), 1, file) == 1)
        {
            if (strcmp(carro.matricula, matricula) != 0) // se a matricula for diferente do que o utilizador meteu
            {
                fwrite(&carro, sizeof(carro), 1, file2); // escreve a estrutura no arquivo temporario
            }
        }
    }

    fclose(file);
    fclose(file2);

    remove("carros.dat");
    rename("temp.dat", "carros.dat");
    printf("\t\t\t\t\t\tCarro removido com sucesso!");
}
