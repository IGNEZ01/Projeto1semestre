#ifndef LIB_H // guardas de cabeçalho, impedem inclusões cíclicas
#define LIB_H

extern int baz; // declaração de uma variável global
                // como é global, valor inicial é zero.

void Login();         // declaração de uma função
void PRegistarUser(); // outra
void mainMenu();

#endif