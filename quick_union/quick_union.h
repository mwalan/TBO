#ifndef QUICK_UNION_H
#define QUICK_UNION_H

#include <stdbool.h>

typedef struct quick_union QuickUnion;

// Operação Init: O(N)
QuickUnion* criar_qu(int n);

void destruir_qu(QuickUnion* qu);

// Operação Find: O(N) no pior caso
int encontrar_raiz(QuickUnion* qu, int i);

// Operação Union: O(N) no pior caso
void unir(QuickUnion* qu, int p, int q);

// Operação Connected: O(N) no pior caso
bool conectado(QuickUnion* qu, int p, int q);

#endif