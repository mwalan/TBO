#include <stdio.h>
#include "quick_find.h"

int main() {
    int N = 10;
    QuickFind* qf = criar_qf(N);
    
    printf("--- Iniciando Caso de Teste Quick Find ---\n\n");
    
    // Fazendo algumas uniões
    printf("Unindo 4 e 3...\n"); unir(qf, 4, 3);
    printf("Unindo 3 e 8...\n"); unir(qf, 3, 8);
    printf("Unindo 6 e 5...\n"); unir(qf, 6, 5);
    printf("Unindo 9 e 4...\n"); unir(qf, 9, 4);
    printf("Unindo 2 e 1...\n"); unir(qf, 2, 1);
    
    // Neste ponto, temos os conjuntos: {8, 3, 4, 9}, {5, 6}, {1, 2}, {0}, {7}
    
    printf("\n--- Verificando Conexoes ---\n");
    
    // 8 e 9 estão conectados? (Sim, através do 3 e 4)
    printf("8 esta conectado a 9? %s\n", conectado(qf, 8, 9) ? "SIM" : "NAO");
    
    // 5 e 4 estão conectados? (Não, estão em componentes diferentes)
    printf("5 esta conectado a 4? %s\n", conectado(qf, 5, 4) ? "SIM" : "NAO");
    
    printf("\nFazendo mais unioes...\n");
    printf("Unindo 5 e 0...\n"); unir(qf, 5, 0);
    printf("Unindo 7 e 2...\n"); unir(qf, 7, 2);
    printf("Unindo 6 e 1...\n"); unir(qf, 6, 1);
    
    // Agora unimos os conjuntos {5, 6, 0} com {1, 2, 7}
    
    printf("\n--- Verificando Novas Conexoes ---\n");
    // 0 e 7 estão conectados agora? (Sim, através do 5, 6, 1 e 2)
    printf("0 esta conectado a 7? %s\n", conectado(qf, 0, 7) ? "SIM" : "NAO");
    
    destruir_qf(qf);
    return 0;
}