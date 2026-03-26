#ifndef PILHA_H
#define PILHA_H

#include <stddef.h>  // Para usar o tipo size_t
#include <stdbool.h>

typedef struct pilha Pilha;

// Cria a pilha informando o tamanho em bytes do tipo que ela vai guardar
Pilha* criar_pilha(int capacidade, size_t tamanho_elemento);

void destruir_pilha(Pilha* p);

// Recebe um ponteiro para a variável que será empilhada
void empilhar(Pilha* p, void* elemento);

// Retira do topo e copia para o endereço de memória passado em 'saida'
bool desempilhar(Pilha* p, void* saida);

bool pilha_vazia(Pilha* p);

#endif