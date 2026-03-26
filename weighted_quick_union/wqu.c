#include <stdio.h>
#include <stdlib.h>
#include "wqu.h"

struct wqu {
    int* pai;
    int* tamanho; // NOVIDADE: Vetor para guardar o peso (quantidade de nós) de cada árvore
    int n;
};

WQU* criar_wqu(int n) {
    WQU* qu = malloc(sizeof(WQU));
    qu->n = n;
    qu->pai = malloc(n * sizeof(int));
    qu->tamanho = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        qu->pai[i] = i;
        qu->tamanho[i] = 1; // Inicialmente, toda árvore tem tamanho 1
    }
    return qu;
}

void destruir_wqu(WQU* qu) {
    free(qu->pai);
    free(qu->tamanho);
    free(qu);
}

int encontrar_raiz(WQU* qu, int i) {
    int saltos = 0;
    int original = i;
    
    while (i != qu->pai[i]) {
        i = qu->pai[i];
        saltos++;
    }
    
    if (saltos > 0) {
        printf("      -> [WQU Profiling] O elemento %d deu %d salto(s) para achar a raiz %d\n", original, saltos, i);
    }
    return i;
}

bool conectado(WQU* qu, int p, int q) {
    return encontrar_raiz(qu, p) == encontrar_raiz(qu, q);
}

void unir(WQU* qu, int p, int q) {
    int raiz_p = encontrar_raiz(qu, p);
    int raiz_q = encontrar_raiz(qu, q);
    
    if (raiz_p == raiz_q) return;
    
    // NOVIDADE: A grande otimização acontece aqui!
    // Comparamos os tamanhos das árvores antes de unir.
    if (qu->tamanho[raiz_p] < qu->tamanho[raiz_q]) {
        qu->pai[raiz_p] = raiz_q; // P (menor) vira filho de Q (maior)
        qu->tamanho[raiz_q] += qu->tamanho[raiz_p]; // Atualiza o tamanho de Q
    } else {
        qu->pai[raiz_q] = raiz_p; // Q (menor ou igual) vira filho de P (maior)
        qu->tamanho[raiz_p] += qu->tamanho[raiz_q]; // Atualiza o tamanho de P
    }
}