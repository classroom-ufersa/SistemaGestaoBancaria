/*Bibliotecas utilizadas*/

#include "agencia.h"

typedef struct contabancaria ContaBancaria;

/*Função para cadastra uma nova conta bancaria, alocando memoria*/
ContaBancaria *criarContaBancaria(char nomeAgencia[], char cliente[], char dataAbertura[], float saldo, char status[], int numeroConta);

// Função para adicionar uma nova conta em ordem alfabética
void adicionarContaEmOrdem(ContaBancaria *novaConta);

/*Função para remover conta pelo numero de identificão */
void removerContaPorNumero(int numeroConta);

/*Função para listar todas as contas cadastradas no arquivo contas.txt*/
void listarContasCadastradas();

// Função para buscar uma conta pelo número de identificação e imprimir seus dados
void buscarContaPorNumero(int numeroConta);

// Função para verificar e mostrar contas ativas em uma determinada agencia
void verificarContasAtivasPorAgencia(const char *nomeAgencia);

