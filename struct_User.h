#ifndef structUser
#define structUser

typedef struct
    {
        int id;
        char nome_utilizador[40];
        char nome[30];
        int idade;
        int nif;
        char email[100];
        char password[10];
        int permicoes;  //0 - user normal  |  1 - user administrador
    }User;

#endif