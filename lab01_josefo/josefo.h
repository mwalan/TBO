#ifndef JOSEFO_H
#define JOSEFO_H

typedef struct josefo Josefo;

Josefo* criar_josefo(int n);
void destruir_josefo(Josefo* j);

// Avança M posições, elimina a pessoa e retorna o seu número (de 1 a N)
int eliminar_pessoa(Josefo* j, int m);

// Retorna a quantidade de pessoas ainda vivas
int pessoas_restantes(Josefo* j);

#endif