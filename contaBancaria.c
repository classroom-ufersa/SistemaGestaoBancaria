
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

    // Se a conta foi encontrada e removida, renomeie o arquivo temporário para substituir o original
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


// Função para buscar uma conta pelo número de identificação e imprimir seus dados
void buscarEImprimirContaPorNumero(int numeroConta)
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt'.\n");
        exit(1);
    }

    char linha[256];
    int contaEncontrada = 0; // Variável para indicar se a conta foi encontrada

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        
            int numConta;
            if (sscanf(linha, "%*s\t%*s\t%*s\t%*f\t%*s\t%d", &numConta) == 1)
            {
                if (numConta == numeroConta)
                {
                    // Encontrou a conta com o número desejado, extrair os campos e imprimir os dados
                    char nomeAgencia[20];
                    char cliente[50];
                    char dataAbertura[11];
                    float saldo;
                    char status[10];

                    sscanf(linha, "%s\t%s\t%s\t%f\t%s\t%d", nomeAgencia, cliente, dataAbertura, &saldo, status, &numConta);

                    printf("Nome da Agência: %s\n", nomeAgencia);
                    printf("Cliente: %s\n", cliente);
                    printf("Data de Abertura: %s\n", dataAbertura);
                    printf("Saldo: %.2f\n", saldo);
                    printf("Status: %s\n", status);
                    printf("Número da Agência: %d\n", numConta);
                    printf("\n");

                    contaEncontrada = 1; // Indica que a conta foi encontrada
                    break; // Como a conta foi encontrada, podemos sair do loop
                }
            }
            
        
    }

    fclose(arquivo);

    if (!contaEncontrada)
    {
        printf("Conta com o número %d não encontrada.\n", numeroConta);
    }
}

// Função para verificar e mostrar contas ativas em uma determinada agencia
void verificarContasAtivasPorAgencia(const char *nomeAgencia)
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt'.\n");
        exit(1);
    }

    char linha[256];

    printf("Contas com status 'Ativa' na agência '%s':\n", nomeAgencia);

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
    
            char agencia[20];
            char status[10];

            if (sscanf(linha, "%s\t%*s\t%*s\t%*f\t%s", agencia, status) == 2)
            {
                if (strcmp(agencia, nomeAgencia) == 0 && strcmp(status, "Ativa") == 0)
                {
                    // Se o nome da agência e o status forem correspondentes, é imprimido os detalhes da conta
                    printf("%s", linha);
                }
            }
            else
            {
                printf("Erro: Formato de linha de conta inválido.\n");
            }
        
    }

    fclose(arquivo);
}



/* // Função para adicionar uma conta na lista de contas em ordem alfabética
void adicionarContaEmOrdem(ContaBancaria **lista, ContaBancaria *novaConta)
{
    if (*lista == NULL)
    {
        // Se a lista estiver vazia, a nova conta se torna o primeiro elemento da lista
        *lista = novaConta;
    }
    else
    {
        // Caso contrário, encontre o ponto de inserção em ordem alfabética com base no nome do cliente
        ContaBancaria *atual = *lista;
        ContaBancaria *anterior = NULL;

        while (atual != NULL && strcmp(novaConta->cliente, atual->cliente) > 0)
        {
            anterior = atual;
            atual = atual->proximo;
        }

        // Insira a nova conta na posição correta
        if (anterior == NULL)
        {
            // Inserir no início da lista
            novaConta->proximo = *lista;
            *lista = novaConta;
        }
        else
        {
            // Inserir no meio ou no final da lista
            anterior->proximo = novaConta;
            novaConta->proximo = atual;
        }
    }
} */

