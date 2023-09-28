
#ifndef AGENCIA_H
#define AGENCIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agencia {
    char nome[50];
    int codigo;
    char localizacao[100];
    int numClientes;
    int numContas;
    char horario[20];
    struct agencia *anterior;
    struct agencia *proximo;
} Agencia;

// Protótipos das funções
Agencia *criarAgencia(char nome[], int codigo, char localizacao[], int numClientes, int numContas, char horario[]);
void adicionarAgenciaEmOrdem(Agencia **lista, Agencia *novaAgencia);

#endif /* AGENCIA_H */

