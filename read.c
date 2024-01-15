
/**********************************
C Demo how to READ with fread.
**********************************/

#include<stdio.h>
#include<stdlib.h>
#include "struct_User.h"

void main ()
{
   User read_user;
   FILE *infile;
    printf("%d", sizeof(User));
   /*** open the accounts file ***/
   infile = fopen ("accounts.dat","r");
   if (infile == NULL)
     {
      fprintf(stderr, "\nError opening accounts.dat\n\n");
      exit (1);
     }
    
    for(;;){
      while (fread (&read_user, sizeof(User), 1, infile)){
          printf ("A = %d ID = %d Nome = %s  Nome de Utilizador = %s  Idade = %d   NIF= %d   Email = %s\n",read_user.permicoes,
                  read_user.id, read_user.nome,read_user.nome_utilizador, read_user.idade, read_user.nif, read_user.email);
      }
    }
}