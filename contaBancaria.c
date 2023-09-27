#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contaBancaria.h"

// Estrutura de dados para Conta Bancária
typedef struct contabancaria {
    int numeroConta;
    Agencia *agencia;
    char cliente[50];
    char dataAbertura[11]; // Formato "dd/mm/aaaa"
    float saldo;
    char status[10];
    struct ContaBancaria *anterior;
    struct ContaBancaria *proximo;
} ContaBancaria;

ContaBancaria *criarContaBancaria(int numeroConta, Agencia *agencia, char cliente[], char dataAbertura[], float saldo, char status[]) {
    ContaBancaria *novaConta = (ContaBancaria *)malloc(sizeof(ContaBancaria));
    if (novaConta == NULL) {
        printf("Erro: Falha na alocação de memória para a Conta Bancária.\n");
        exit(1);
    }

    novaConta->numeroConta = numeroConta;
    novaConta->agencia = agencia;
    strcpy(novaConta->cliente, cliente);
    strcpy(novaConta->dataAbertura, dataAbertura);
    novaConta->saldo = saldo;
    strcpy(novaConta->status, status);
    novaConta->anterior = NULL;
    novaConta->proximo = NULL;

    return novaConta;
}


void lerDadosConta() {
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo 'dados.txt'.\n");
        exit(1);
    }

    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strncmp(linha, "Conta", 5) == 0) {
            // Encontrou uma linha de conta, ler e exibir os campos
            int numeroAgencia;
            char cliente[50];
            char dataAbertura[11];
            float saldo;
            char status[10];

            if (sscanf(linha, "Conta\t%d\t%s\t%s\t%f\t%s", &numeroAgencia, cliente, dataAbertura, &saldo, status) == 5) {
                printf("Número da Agência: %d\n", numeroAgencia);
                printf("Cliente: %s\n", cliente);
                printf("Data de Abertura: %s\n", dataAbertura);
                printf("Saldo: %.2f\n", saldo);
                printf("Status: %s\n", status);
                printf("\n");
            } else {
                printf("Erro: Formato de linha de conta inválido.\n");
            }
        }
    }

    fclose(arquivo);
}


