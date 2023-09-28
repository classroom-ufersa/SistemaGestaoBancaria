/*Bibliotecas utilizadas*/

#include "agencia.h"

typedef struct contabancaria ContaBancaria;

/*Função para cadastra uma nova conta bancaria, alocando memoria*/
ContaBancaria *criarContaBancaria( Agencia *agencia, char cliente[], char dataAbertura[], float saldo, char status[], int numeroConta);

/*Função para remover conta do arquivo dados.txt*/
void removerContaPorNumero(int numeroConta);

/*Função para litar todas as contas cadastradas no arquivo dados.txt*/
void listarContasCadastradas();

// Função para buscar uma conta pelo número de identificação e imprimir seus dados
void buscarEImprimirContaPorNumero(int numeroConta);

// Função para verificar e mostrar contas ativas em uma determinada agencia
void verificarContasAtivasPorAgencia(const char *nomeAgencia);

/* Função para adionar uma conta na lista de contas em ordem alfabética
void adicionarContaEmOrdem(ContaBancaria **lista, ContaBancaria *novaConta);*/