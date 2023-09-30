
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
/*Função para cadastra uma nova agencia, alocando memoria*/
Agencia *criarAgencia(char nome[], int codigo, char localizacao[], int numClientes, int numContas, char horario[]);

// Função para adicionar uma nova agencia em ordem alfabética
void adicionarAgenciaEmOrdem( Agencia *novaAgencia);

// Função para listar todas as agências cadastradas no arquivo "agencias.txt"
void listarAgencias();

#endif /* AGENCIA_H */

