#include <stdlib.h>
#include "josefo.h"

// O "nó" da nossa lista encadeada
typedef struct no {
    int id;
    struct no* prox;
} No;

struct josefo {
    No* atual;
    int tamanho;
};

Josefo* criar_josefo(int n) {
    Josefo* j = malloc(sizeof(Josefo));
    j->tamanho = n;
    
    No* primeiro = malloc(sizeof(No));
    primeiro->id = 1;
    No* anterior = primeiro;

    for (int i = 2; i <= n; i++) {
        No* novo = malloc(sizeof(No));
        novo->id = i;
        anterior->prox = novo;
        anterior = novo;
    }
    
    // Fecha o círculo
    anterior->prox = primeiro; 
    
    // Aponta para o último, assim o próximo a ser contado é o 1º
    j->atual = anterior; 
    return j;
}

int eliminar_pessoa(Josefo* j, int m) {
    if (j->tamanho == 0) return -1;
    
    // Avança M-1 vezes (pois j->atual já está ANTES da pessoa 1)
    for (int i = 0; i < m - 1; i++) {
        j->atual = j->atual->prox;
    }
    
    No* remover = j->atual->prox;
    int id_removido = remover->id;

    // Remove o nó da roda
    j->atual->prox = remover->prox; 
    free(remover);
    j->tamanho--;

    return id_removido;
}

int pessoas_restantes(Josefo* j) {
    return j->tamanho;
}

void destruir_josefo(Josefo* j) {
    while (j->tamanho > 0) {
        eliminar_pessoa(j, 1);
    }
    free(j);
}