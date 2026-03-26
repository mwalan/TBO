#ifndef WQU_H
#define WQU_H

#include <stdbool.h>

typedef struct wqu WQU;

WQU* criar_wqu(int n);
void destruir_wqu(WQU* qu);

int encontrar_raiz(WQU* qu, int i);
void unir(WQU* qu, int p, int q);
bool conectado(WQU* qu, int p, int q);

#endif