#include "contaBancaria.h"  // cabeçalho para acessar a definição de ContaBancaria


// Definição de um nó da lista duplamente encadeada
struct Lista {
    struct ContaBancaria *conta;
    struct Lista *prox;
    struct Lista *ant;
};


// Definição da estrutura da Agência Bancária
struct Agencia{
    char nome[51];
    int codigo;
    char localizacao[31];
    struct Lista *contas;
    char horario[15];
    int numClientes;
    };

// Função para criar uma agência bancária
struct Agencia *criar_agencia(char *nome, int codigo, char *localizacao, char *horario, int numClientes) {
    struct Agencia *agencia = (struct Agencia *)malloc(sizeof(struct Agencia));
    if (agencia == NULL) {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    strcpy(agencia->nome, nome);
    agencia->codigo = codigo;
    strcpy(agencia->localizacao, localizacao);
    strcpy(agencia->horario, horario);
    agencia->numClientes = numClientes;
    agencia->contas = NULL;

    return agencia;
}


