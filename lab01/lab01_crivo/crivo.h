#ifndef CRIVO_H
#define CRIVO_H
#include <stdbool.h>

// Tipo opaco: esconde a estrutura interna do cliente
typedef struct crivo Crivo;

// Assinaturas das funções
Crivo* criar_crivo(long long n);
void destruir_crivo(Crivo* c);
void marcar_composto(Crivo* c, long long i);
bool eh_primo(Crivo* c, long long i);
void executar_crivo(Crivo* c);

#endif // CRIVO_H   