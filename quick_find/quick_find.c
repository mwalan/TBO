#include <stdlib.h>
#include "quick_find.h"

struct quick_find {
    int* id;
    int tamanho;
};

QuickFind* criar_qf(int n) {
    QuickFind* qf = malloc(sizeof(QuickFind));
    qf->tamanho = n;
    qf->id = malloc(n * sizeof(int));
    
    // Inicialmente, cada elemento está no seu próprio conjunto (seu ID é ele mesmo)
    for (int i = 0; i < n; i++) {
        qf->id[i] = i;
    }
    
    return qf;
}

void destruir_qf(QuickFind* qf) {
    free(qf->id);
    free(qf);
}

bool conectado(QuickFind* qf, int p, int q) {
    // Busca incrivelmente rápida O(1)
    return qf->id[p] == qf->id[q];
}

void unir(QuickFind* qf, int p, int q) {
    int pid = qf->id[p];
    int qid = qf->id[q];
    
    // Se já estão no mesmo conjunto, não faz nada
    if (pid == qid) return;
    
    // Varre o vetor inteiro O(N) mudando todos os IDs 'pid' para 'qid'
    for (int i = 0; i < qf->tamanho; i++) {
        if (qf->id[i] == pid) {
            qf->id[i] = qid;
        }
    }
}