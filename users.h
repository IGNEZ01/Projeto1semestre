#ifndef LIB_H // guardas de cabeçalho, impedem inclusões cíclicas
#define LIB_H

extern int baz; // declaração de uma variável global
                // como é global, valor inicial é zero.

void delay(int number_of_seconds); // declaração de uma função
void PMenuUser(int id);            // outra

#endif