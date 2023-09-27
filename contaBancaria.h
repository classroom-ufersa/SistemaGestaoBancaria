/*Bibliotecas utilizadas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agencia.h"

typedef struct contabancaria ContaBancaria;

/*Função para cadastra uma nova conta bancaria, alocando memoria*/
ContaBancaria *criarContaBancaria( Agencia *agencia, char cliente[], char dataAbertura[], float saldo, char status[], int numeroConta);

/*Função para ler todas as contas bancarias presentes no arquivo dados.txt*/
void lerDadosConta();
