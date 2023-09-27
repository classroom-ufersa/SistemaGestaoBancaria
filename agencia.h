#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct agencia Agencia;

/* Função para cadastrar uma nova agencia bancaria, alocando memoria */
Agencia *criarAgencia(char nome[], int codigo, char localizacao[], int numClientes, int numContas, char horario[]);

