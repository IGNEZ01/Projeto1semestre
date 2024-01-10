
/**********************************
C Demo how to READ with fread.
**********************************/

#include<stdio.h>
#include<stdlib.h>



struct user
    {
        int id;
        char nome_utilizador[40];
        char nome[30];
        int idade;
        int nif;
        char email[100];
        char password[10];
    }user;

void main ()
{
   FILE *infile;
   struct user read_user;
    printf("%d", sizeof(struct user));
   /*** open the accounts file ***/
   infile = fopen ("accounts.dat","r");
   if (infile == NULL)
     {
      fprintf(stderr, "\nError opening accounts.dat\n\n");
      exit (1);
     }
    
    for(;;){
      while (fread (&read_user, sizeof(struct user), 1, infile)){
          printf ("ID = %d Nome = %s  Nome de Utilizador = %s  Idade = %d   NIF= %d   Email = %s\n",
                  read_user.id, read_user.nome,read_user.nome_utilizador, read_user.idade, read_user.nif, read_user.email);
      }
    }
}