
#ifndef AGENCIA_H
#define AGENCIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Permite o uso dos tipos booleanos 
#include <ctype.h> // permite utilizar funções para testar caracteres


typedef struct agencia {
    char nome[50];
    int codigo;
    char localizacao[100];
    int numClientes;
    int numContas;
    char horario[12];
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

// Função para buscar uma determinda agencia, se encontrar a agencia retorna 0, se não retorna 1.
int buscarAgenciaPorNome(const char nome[]);

// Função para incrementar sempre que uma nova conta é criada em uma determinada agencia.
void incrementarContas(const char nomeAgencia[]);

// Função libera agencia vai liberar a memoria ocupada
void libera_agencia(Agencia *novaAgencia);



#endif /* AGENCIA_H */

