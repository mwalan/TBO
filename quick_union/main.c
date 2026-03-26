#include <stdio.h>
#include <stdlib.h>
#include "quick_union.h"

int main() {
    int n;
    
    // Lê o tamanho inicial N
    if (scanf("%d", &n) != 1) {
        printf("Erro ao ler o tamanho N.\n");
        return 1;
    }

    QuickUnion* qu = criar_qu(n);
    printf("\n[ Quick Union inicializado com %d elementos ]\n", n);
    printf("Comandos: 'U p q' (Unir), 'C p q' (Conectado?), 'S' (Sair)\n\n");

    char op;
    int p, q;

    // Lê os comandos em loop até encontrar 'S' ou o Fim do Arquivo (EOF)
    while (scanf(" %c", &op) == 1) {
        if (op == 'S' || op == 's') {
            printf("Encerrando testes.\n");
            break;
        } 
        else if (op == 'U' || op == 'u') {
            if (scanf("%d %d", &p, &q) != 2) {
                printf("Erro na leitura dos operandos. Abortando...\n");
                break;
            }
            unir(qu, p, q);
            printf(" -> Uniao realizada entre %d e %d\n", p, q);
        } 
        else if (op == 'C' || op == 'c') {
            if (scanf("%d %d", &p, &q) != 2) {
                printf("Erro na leitura dos operandos. Abortando...\n");
                break;
            }
            bool res = conectado(qu, p, q);
            printf(" -> %d e %d estao conectados? %s\n", p, q, res ? "SIM" : "NAO");
        } 
        else {
            printf("Comando invalido.\n");
        }
    }

    destruir_qu(qu);
    return 0;
}