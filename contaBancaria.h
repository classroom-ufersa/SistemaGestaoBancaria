/*Bibliotecas utilizadas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agencia.h"

typedef struct contabancaria ContaBancaria;

/*Função para cadastra uma nova conta bancaria, alocando memoria*/
ContaBancaria *criarContaBancaria( Agencia *agencia, char cliente[], char dataAbertura[], float saldo, char status[], int numeroConta);

/*Função para remover conta do arquivo dados.txt*/
void removerContaPorNumero(int numeroConta);

/*Função para litar todas as contas cadastradas no arquivo dados.txt*/
void listarContasCadastradas();