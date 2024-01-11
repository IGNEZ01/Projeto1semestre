#ifndef structCarro
#define structCarro

struct Data
{
    int dia;
    int mes;
    int ano;
};

typedef struct
    {
        int id;
        char marca[40];
        char modelo[40];
        int celindrada;
        int lugares;
        char alimentacao[20];
        char matricula[10];
        struct Data idade;
    }Carro;

#endif