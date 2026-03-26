#include <stdio.h>
#include <stdlib.h>
#include "wqu.h"

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) {
        printf("Erro ao ler N.\n");
        return 1;
    }

    WQU* qu = criar_wqu(n);
    printf("\n[ Weighted Quick Union inicializado com %d elementos ]\n", n);

    char op;
    int p, q;

    while (scanf(" %c", &op) == 1) {
        if (op == 'S' || op == 's') break;
        
        if (op == 'U' || op == 'u') {
            if (scanf("%d %d", &p, &q) == 2) {
                unir(qu, p, q);
                printf(" -> Uniao realizada entre %d e %d\n", p, q);
            }
        } 
        else if (op == 'C' || op == 'c') {
            if (scanf("%d %d", &p, &q) == 2) {
                bool res = conectado(qu, p, q);
                printf(" -> %d e %d estao conectados? %s\n", p, q, res ? "SIM" : "NAO");
            }
        }
    }

    destruir_wqu(qu);
    return 0;
}