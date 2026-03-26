#ifndef QUICK_FIND_H
#define QUICK_FIND_H

#include <stdbool.h>

typedef struct quick_find QuickFind;

// Cria a estrutura com N elementos (de 0 a N-1)
QuickFind* criar_qf(int n);

void destruir_qf(QuickFind* qf);

// Conecta o elemento p ao elemento q
void unir(QuickFind* qf, int p, int q);

// Verifica se p e q estão no mesmo conjunto
bool conectado(QuickFind* qf, int p, int q);

#endif