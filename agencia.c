#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados para Agência
typedef struct agencia {
    char nome[50];
    int codigo;
    char localizacao[100];
    int numClientes;
    int numContas;
    char horario[20];
    struct Agencia *anterior;
    struct Agencia *proximo;
} Agencia;

Agencia *criarAgencia(char nome[], int codigo, char localizacao[], int numClientes, int numContas, char horario[]) {
    Agencia *novaAgencia = (Agencia *)malloc(sizeof(Agencia));
    if (novaAgencia == NULL) {
        printf("Erro: Falha na alocação de memória para a Agência.\n");
        exit(1);
    }

    strcpy(novaAgencia->nome, nome);
    novaAgencia->codigo = codigo;
    strcpy(novaAgencia->localizacao, localizacao);
    novaAgencia->numClientes = numClientes;
    novaAgencia->numContas = numContas;
    strcpy(novaAgencia->horario, horario);
    novaAgencia->anterior = NULL;
    novaAgencia->proximo = NULL;

    return novaAgencia;
}

