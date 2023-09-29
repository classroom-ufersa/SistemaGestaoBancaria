
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

ContaBancaria *criarContaBancaria(char nomeAgencia[], char cliente[], char dataAbertura[], float saldo, char status[], int numeroConta)
{
    ContaBancaria *novaConta = (ContaBancaria *)malloc(sizeof(ContaBancaria));
    if (novaConta == NULL)
    {
        printf("Memoria insuficiente!\n");
        exit(1);
    }

    novaConta->numeroConta = numeroConta;
    strcpy(novaConta->cliente, cliente);
    strcpy(novaConta->nomeAgencia, nomeAgencia);
    strcpy(novaConta->dataAbertura, dataAbertura);
    novaConta->saldo = saldo;
    strcpy(novaConta->status, status);
    novaConta->anterior = NULL;
    novaConta->proximo = NULL;

    return novaConta;
}

// Função para buscar uma conta pelo número de identificação e imprimir seus dados
void adicionarContaEmOrdem(ContaBancaria *novaConta)
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt' para leitura.\n");
        exit(1);
    }

    // Abre o arquivo temporário para escrever as contas em ordem
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("Erro: Não foi possível criar o arquivo temporário.\n");
        fclose(arquivo);
        exit(1);
    }

    char linha[256];
    int inserido = 0;  // Variável para verificar se a nova conta foi inserida no arquivo temporário

    // Formate a nova conta em uma string
    char novaContaString[256];
    sprintf(novaContaString, "%s\t%s\t%s\t%.2f\t%s\t%d\n", novaConta->nomeAgencia, novaConta->cliente, novaConta->dataAbertura, novaConta->saldo, novaConta->status, novaConta->numeroConta);

    // Loop para encontrar a posição correta para inserir a nova conta
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        // Compara a linha inteira (todos os campos) de forma insensível a maiúsculas e minúsculas
        if (strcasecmp(linha, novaContaString) > 0 && !inserido)
        {
            // Insere a nova conta antes desta linha
            fprintf(temp, "%s", novaContaString);
            inserido = 1;
        }

        fputs(linha, temp); // Copia a linha para o arquivo temporário
    }

    // Se a nova conta ainda não foi inserida no arquivo temporário, insira no final
    if (!inserido)
    {
        fprintf(temp, "%s", novaContaString);
    }

    fclose(arquivo);
    fclose(temp);

    // Substitui o arquivo original pelo temporário
    remove("contas.txt");
    rename("temp.txt", "contas.txt");
}

// Função para remover uma conta pelo número de identificação 
void removerContaPorNumero(int numeroConta)
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt'.\n");
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
    int contaEncontrada = 0; // Variável de sinalização

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        int numConta;
        if (sscanf(linha, "%*s\t%*s\t%*s\t%*f\t%*s\t%d", &numConta) == 1)
        {
            if (numConta != numeroConta)
            {
                // Se o número da conta não coincide, escreva a linha no arquivo temporário
                fputs(linha, temp);
            }
            else
            {
                contaEncontrada = 1; // Marca que a conta foi encontrada
            }
        }
        else
        {
            printf("Erro: Formato de linha de conta inválido.\n");
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Se a conta foi encontrada e removida, o arquivo temporário é renomeado para substituir o original
    if (contaEncontrada)
    {
        remove("contas.txt");
        rename("temp.txt", "contas.txt");
        printf("Conta removida com sucesso.\n");
    }
    else
    {
        printf("Conta não encontrada.\n");
        remove("temp.txt"); // Remove o arquivo temporário
    }
}

/*Função para listar todas as contas cadastradas no arquivo contas.txt*/
void listarContasCadastradas()
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt'.\n");
        exit(1);
    }

    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
            char nomeAgencia[20];
            char cliente[50];
            char dataAbertura[11];
            float saldo;
            char status[10];
            int numeroConta;

            if (sscanf(linha, "%s\t%s\t%s\t%f\t%s\t%d", nomeAgencia, cliente, dataAbertura, &saldo, status, &numeroConta) == 6)
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

    fclose(arquivo);
}





