#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contaBancaria.h"

// Estrutura de dados para Conta Bancária
typedef struct contabancaria
{
    int numeroConta;
    Agencia *agencia;
    char nomeAgencia[20];
    char cliente[50];
    char dataAbertura[11]; // Formato "dd/mm/aaaa"
    float saldo;
    char status[10];
    struct ContaBancaria *anterior;
    struct ContaBancaria *proximo;
} ContaBancaria;

ContaBancaria *criarContaBancaria(Agencia *agencia, char cliente[], char dataAbertura[], float saldo, char status[], int numeroConta)
{
    ContaBancaria *novaConta = (ContaBancaria *)malloc(sizeof(ContaBancaria));
    if (novaConta == NULL)
    {
        printf("Memoria insuficiente!\n");
        exit(1);
    }

    novaConta->numeroConta = numeroConta;
    strcpy(novaConta->cliente, cliente);
    strcpy(novaConta->dataAbertura, dataAbertura);
    novaConta->saldo = saldo;
    strcpy(novaConta->status, status);
    novaConta->anterior = NULL;
    novaConta->proximo = NULL;

    return novaConta;
}

void listarContasCadastradas()
{
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'dados.txt'.\n");
        exit(1);
    }

    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        if (strncmp(linha, "Conta", 5) == 0)
        {
            // Encontra uma linha de conta, ler e exibir os campos
            char nomeAgencia[20];
            char cliente[50];
            char dataAbertura[11];
            float saldo;
            char status[10];
            int numeroConta;

            if (sscanf(linha, "Conta\t%s\t%s\t%s\t%f\t%s\t%d", nomeAgencia, cliente, dataAbertura, &saldo, status, &numeroConta) == 6)
            {
                printf("Nome da Agência: %s\n", nomeAgencia);
                printf("Cliente: %s\n", cliente);
                printf("Data de Abertura: %s\n", dataAbertura);
                printf("Saldo: %.2f\n", saldo);
                printf("Status: %s\n", status);
                printf("Número da Agência: %d\n", numeroConta);
                printf("\n");
            }
            else
            {
                printf("Erro: Formato de linha de conta inválido.\n");
            }
        }
    }

    fclose(arquivo);
}

void removerContaPorNumero(int numeroConta)
{
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'dados.txt'.\n");
        exit(1);
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("Erro: Não foi possível criar o arquivo temporário.\n");
        fclose(arquivo);
        exit(1);
    }

    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        // Verifica se a linha é uma linha de conta
        if (strncmp(linha, "Conta", 5) == 0)
        {
            int numConta;
            if (sscanf(linha, "Conta\t%*s\t%*s\t%*s\t%*f\t%*s\t%d", &numConta) == 1) //O caractere * em sscanf foi usado para indicar que o valor lido pelo especificador de formato correspondente deve ser ignorado. 
            {
                if (numConta != numeroConta)
                {
                    // Se o número da conta não coincide, escreva a linha no arquivo temporário
                    fputs(linha, temp);
                }
            }
            else
            {
                printf("Erro: Formato de linha de conta inválido.\n");
            }
        }
        else
        {
            // Se não for uma linha de conta, escreva a linha no arquivo temporário
            fputs(linha, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Renomeia o arquivo temporário para substituir o original
    remove("dados.txt");
    rename("temp.txt", "dados.txt");

    printf("Conta removida com sucesso.\n");
}
