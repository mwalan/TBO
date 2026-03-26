#include <stdlib.h>
#include "quick_union.h"

struct quick_union {
    int* pai; // Agora o vetor guarda o "pai" de cada elemento
    int tamanho;
};

QuickUnion* criar_qu(int n) {
    QuickUnion* qu = malloc(sizeof(QuickUnion));
    qu->tamanho = n;
    qu->pai = malloc(n * sizeof(int));
    
    // Init: Cada elemento começa como raiz de si mesmo
    for (int i = 0; i < n; i++) {
        qu->pai[i] = i; 
    }
    
    return qu;
}

void destruir_qu(QuickUnion* qu) {
    free(qu->pai);
    free(qu);
}

int encontrar_raiz(QuickUnion* qu, int i) {
    int saltos = 0;
    int elemento_original = i;
    
    // Find: Sobe na árvore até encontrar o pai de si mesmo
    while (i != qu->pai[i]) {
        i = qu->pai[i];
        saltos++; // Conta o esforço do algoritmo
    }
    
    if (saltos > 0) {
        printf("      -> Custo: O elemento %d precisou de %d salto(s) para achar a raiz %d\n", elemento_original, saltos, i);
    }
    return i;
}

bool conectado(QuickUnion* qu, int p, int q) {
    // Connected: Dois elementos estão conectados se possuem a MESMA raiz
    return encontrar_raiz(qu, p) == encontrar_raiz(qu, q);
}

void unir(QuickUnion* qu, int p, int q) {
    // Union: Encontra as raízes de ambos
    int raiz_p = encontrar_raiz(qu, p);
    int raiz_q = encontrar_raiz(qu, q);
    
    // Se já têm a mesma raiz, já estão conectados
    if (raiz_p == raiz_q) return;
    
    // O pulo do gato: A raiz de P passa a apontar para a raiz de Q
    qu->pai[raiz_p] = raiz_q; 
}