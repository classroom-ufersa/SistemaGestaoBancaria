/*Bibliotecas utilizadas*/
#include "agencia.h"

typedef struct contabancaria ContaBancaria;

/*Função para cadastra uma nova conta bancaria, alocando memoria*/
ContaBancaria *criarContaBancaria(int numeroConta, Agencia *agencia, char cliente[], char dataAbertura[], float saldo, char status[]);

/*Função para ler todas as contas bancarias presentes no arquivo dados.txt*/
void lerDadosConta();
