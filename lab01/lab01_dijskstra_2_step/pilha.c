#include <stdlib.h>
#include <string.h> // Para usar memcpy
#include "pilha.h"

struct pilha {
    void* dados;             // Vetor genérico de bytes
    int topo;                // Índice do topo
    int capacidade;          // Capacidade máxima
    size_t tamanho_elemento; // Tamanho de cada item (ex: 8 para double, 1 para char)
};

Pilha* criar_pilha(int capacidade, size_t tamanho_elemento) {
    Pilha* p = malloc(sizeof(Pilha));
    p->capacidade = capacidade;
    p->tamanho_elemento = tamanho_elemento;
    p->topo = 0;
    
    // Aloca (capacidade * tamanho do tipo) bytes
    p->dados = malloc(capacidade * tamanho_elemento); 
    return p;
}

void destruir_pilha(Pilha* p) {
    free(p->dados);
    free(p);
}

void empilhar(Pilha* p, void* elemento) {
    if (p->topo == p->capacidade) return; // Pilha cheia (num cenário real, poderíamos dobrar o tamanho)
    
    // Calcula o endereço de memória exato onde o novo elemento deve entrar
    void* destino = (char*)p->dados + (p->topo * p->tamanho_elemento);
    
    // Copia os bytes da variável do usuário para dentro do vetor da pilha
    memcpy(destino, elemento, p->tamanho_elemento);
    p->topo++;
}

bool desempilhar(Pilha* p, void* saida) {
    if (pilha_vazia(p)) return false;
    
    p->topo--; // Desce o topo
    
    // Calcula o endereço do elemento que está saindo
    void* origem = (char*)p->dados + (p->topo * p->tamanho_elemento);
    
    // Copia os bytes da pilha de volta para a variável do usuário
    memcpy(saida, origem, p->tamanho_elemento);
    return true;
}

bool pilha_vazia(Pilha* p) {
    return p->topo == 0;
}