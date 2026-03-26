#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    // 1. Criando as duas pilhas (capacidade 100 como exemplo seguro)
    // Veja como reutilizamos o MESMO código para tipos totalmente diferentes!
    Pilha* p_valores = criar_pilha(100, sizeof(double)); 
    Pilha* p_operadores = criar_pilha(100, sizeof(char));

    char token[50]; // String temporária para ler da tela
    printf("Digite a expressao infixada separada por espacos (Ctrl+D para encerrar):\n");
    printf("Exemplo: ( 5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) )\nAo final aperte ctrl+D para indicar EOF (end of file)\n");

    // Lê palavra por palavra (separadas por espaço)
    while (scanf("%s", token) != EOF) {
        
        if (strcmp(token, "(") == 0) {
            // Regra 1: Ignore abre parênteses
            continue; 
        } 
        else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
                 strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            // Regra 2: Empilhe operadores
            char op = token[0];
            empilhar(p_operadores, &op);
        } 
        else if (strcmp(token, ")") == 0) {
            // Regra 3: Fecha parênteses. Desempilha operador e dois operandos, calcula e empilha resultado.
            char op;
            double val1, val2, resultado;
            
            desempilhar(p_operadores, &op);
            desempilhar(p_valores, &val2); // O primeiro a sair é o segundo operando!
            desempilhar(p_valores, &val1);
            
            if (op == '+') resultado = val1 + val2;
            else if (op == '-') resultado = val1 - val2;
            else if (op == '*') resultado = val1 * val2;
            else if (op == '/') resultado = val1 / val2;

            empilhar(p_valores, &resultado);
        } 
        else {
            // Regra 4: É um número. Converte string para double e empilha.
            double valor = atof(token);
            empilhar(p_valores, &valor);
        }
    }

    // Ao final, o resultado da expressão inteira estará sozinho na pilha de valores
    double resultado_final;
    if (desempilhar(p_valores, &resultado_final)) {
        printf("Resultado: %.2f\n", resultado_final);
    }

    // Libera a memória
    destruir_pilha(p_valores);
    destruir_pilha(p_operadores);

    return 0;
}