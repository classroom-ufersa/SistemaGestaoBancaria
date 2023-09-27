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
