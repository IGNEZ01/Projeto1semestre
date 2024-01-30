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
    file = fopen("carros.dat", "a+");

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
            printf("MARCA = %s MODELO: %s Matricula: %s COMBUSTIVEL: %s LUGARES: %d CELINDRADA: %d\n",
                   read_car.marca, read_car.modelo, read_car.matricula, read_car.alimentacao, read_car.lugares, read_car.celindrada);
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
    file = fopen("carros.dat", "a+");

    // exceçao para qualquer erro ao abrir o ficheiro
    if (file == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o ficheiro accounts.dat\n\n");
        exit(1);
    }

    while (fread(&read_car, sizeof(Carro), 1, file))
    {
        printf("MARCA = %s MODELO: %s Matricula: %s COMBUSTIVEL: %s LUGARES: %d CELINDRADA: %d Disponibilidade: %d\n",
               read_car.marca, read_car.modelo, read_car.matricula, read_car.alimentacao, read_car.lugares, read_car.celindrada, read_car.estado_alugado);
    }

    fclose(file);
}

void NovoAluguer(int id)
{

    char matricula[10];

    SysCLS();

    printf("\t\t\t\t\t  =========REGISTAR NOVO ALUGUER=====\n");
    printf("\t\t\t\t\tInserir a matricula do carro pretendido\n");

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
        fprintf(stderr, "\nErro ao abrir o ficheiro carros.dat\n\n");
        exit(1);
    }
    
    

    while (fread(&carro, sizeof(Carro), 1, file))
    {

        if (strcmp(carro.matricula, matricula) == 0 && carro.estado_alugado == 0)
        {
            printf("carro disponivel!");

            printf("Quanto tempo sera o aluger?");

            scanf("%d", &duracao_aluguer);

            carro.id_alugado = id;

            
            printf("%d", carro.estado_alugado);
            carro.estado_alugado = 1;
            printf("%d", carro.estado_alugado);
            fseek(file, -sizeof(Carro), SEEK_CUR);
            fwrite(&carro, sizeof(Carro), 1, file);
            SysPause();


            printf("Id user alugado: %d", carro.id_alugado);
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
        fprintf(stderr, "\nErro ao abrir o ficheiro carros.dat\n\n");
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
            }else{

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

    // certifica que o carro esta sempre disponivel quando inserido
    carro.estado_alugado = 0;

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

void AtualizarCarro()
{
}

void EliminarCarro()
{
    	
    FILE *file;

    file = fopen("carros.dat","rb+");

    Carro carro;

    long int controleFread;
    int id=1;
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
    FILE *file2 = fopen("temp.dat","ab+");
    if (file2 == NULL)
    {
        printf("\t\t\t\t\t  =========ERRO AO CRIAR ARQUIVO=======\n");
    }
    else
    {
        rewind(file);
        while (fread(&carro, sizeof(Carro), 1, file) == 1)
        {
        if (strcmp(carro.matricula,matricula) != 0)// se a matricula for diferente do que o utilizador meteu
        {
            fwrite(&carro, sizeof(carro), 1, file2);// escreve a estrutura no arquivo temporario
        }
        
        }
    }

    fclose(file);
    fclose(file2);
    
    
    remove("carros.dat");
    rename("temp.dat","carros.dat");
    printf("\t\t\t\t\t\tCarro removido com sucesso!");
    
    

}
