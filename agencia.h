#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contaBancaria.h"  // para acessar a definição de ContaBancaria

typedef struct Agencia Agencia;
typedef struct Lista Lista;

/* Função para cadastrar uma nova agencia bancaria, alocando memoria */
Agencia *criar_agencia(char *nome, int codigo, char *localizacao, char *horario, int numClientes);

