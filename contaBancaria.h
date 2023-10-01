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

// Função para consultar e listar todas as contas ativas em uma agência com base no nome da agência
void ConsultarContasAtivasPorAgencia(char nomeAgencia[]);

// Função para ordenar o arquivo 'contas.txt' em ordem alfabética
void ordenarArquivoEmOrdemAlfabetica();

// Função para editar os dados de uma conta com base no número da conta
void editarDadosContaPorNumero(int numeroConta);

