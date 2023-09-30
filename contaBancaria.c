
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

// Função para adicionar uma nova conta em ordem alfabética
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
    int inserido = 0; // Variável para verificar se a nova conta foi inserida no arquivo temporário

    // Formata a nova conta em uma string
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

        // Copia a linha existente para o arquivo temporário
        fputs(linha, temp);
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
        if (sscanf(linha, "%*49[^\t]\t%*99[^\t]\t%*s\t%*f\t%*s\t%d", &numConta) == 1)
        {
            if (numConta != numeroConta)
            {
                // Se o número da conta não coincide, escreve a linha no arquivo temporário
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
        char nomeAgencia[50];
        char cliente[100];
        char dataAbertura[11];
        float saldo;
        char status[10];
        int numeroConta;

        if (sscanf(linha, "%49[^\t]\t%99[^\t]\t%s\t%f\t%s\t%d", nomeAgencia, cliente, dataAbertura, &saldo, status, &numeroConta) == 6)
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

// Função para buscar uma conta por número e imprimir seus dados
void buscarContaPorNumero(int numeroConta)
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt' para leitura.\n");
        exit(1);
    }

    char linha[256];
    int contaEncontrada = 0; // Variável para verificar se a conta foi encontrada

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        int numConta;
        if (sscanf(linha, "%*49[^\t]\t%*99[^\t]\t%*s\t%*f\t%*s\t%d", &numConta) == 1)
        {
            if (numConta == numeroConta)
            {
                char nomeAgencia[50];
                char cliente[100];
                char dataAbertura[11];
                float saldo;
                char status[10];
                int numeroConta;

                (sscanf(linha, "%49[^\t]\t%99[^\t]\t%s\t%f\t%s\t%d", nomeAgencia, cliente, dataAbertura, &saldo, status, &numeroConta) == 6);

                printf("Conta encontrada:\n");
                printf("Nome da Agência: %s\n", nomeAgencia);
                printf("Cliente: %s\n", cliente);
                printf("Data de Abertura: %s\n", dataAbertura);
                printf("Saldo: %.2f\n", saldo);
                printf("Status: %s\n", status);
                printf("Número da Conta: %d\n", numConta);

                contaEncontrada = 1; // Marca que a conta foi encontrada
                break;               // Não é necessário continuar procurando
            }
        }
        else
        {
            printf("Erro: Formato de linha de conta inválido.\n");
        }
    }

    fclose(arquivo);

    if (!contaEncontrada)
    {
        printf("Conta com número %d não encontrada.\n", numeroConta);
    }
}

// Função para consultar e listar todas as contas ativas em uma agência com base no nome da agência
void ConsultarContasAtivasPorAgencia(char nomeAgencia[])
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt' para leitura.\n");
        exit(1);
    }

    char linha[256];
    int encontradas = 0; // Variável para verificar se foram encontradas contas ativas na agência

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        char nomeAgenciaConta[50];
        char status[10];
        char cliente[100];
        char dataAbertura[11];
        float saldo;
        int numeroConta;

        if (sscanf(linha, "%49[^\t]\t%99[^\t]\t%s\t%f\t%s\t%d", nomeAgenciaConta, cliente, dataAbertura, &saldo, status, &numeroConta) == 6)
        {
            if (strcasecmp(nomeAgencia, nomeAgenciaConta) == 0 && strcasecmp(status, "Ativa") == 0)
            {
                // A conta pertence à agência e está ativa
                printf("Conta ativa na agência %s:\n", nomeAgencia);
                printf("Nome da Agência: %s\n", nomeAgenciaConta);
                printf("Cliente: %s\n", cliente);
                printf("Data de Abertura: %s\n", dataAbertura);
                printf("Saldo: %.2f\n", saldo);
                printf("Status: %s\n", status);
                printf("Número da Conta: %d\n", numeroConta);
                printf("\n");
                encontradas++;
            }
        }
        else
        {
            printf("Erro: Formato de linha de conta inválido.\n");
        }
    }

    fclose(arquivo);

    if (encontradas == 0)
    {
        printf("Nenhuma conta ativa encontrada na agência %s.\n", nomeAgencia);
    }
}

// Função para editar os dados de uma conta com base no número da conta
void editarDadosContaPorNumero(int numeroConta)
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt' para leitura.\n");
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
    char nomeAgencia[50];
    char cliente[100];
    char dataAbertura[11];
    float saldo;
    char status[10];
    int numConta;

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        if (sscanf(linha, "%49[^\t]\t%99[^\t]\t%s\t%f\t%s\t%d", nomeAgencia, cliente, dataAbertura, &saldo, status, &numConta) == 6)
        {
            if (numeroConta == numConta)
            {
                contaEncontrada = 1;
                printf("DADOS DA CONTA QUE SERA EDITADA:\n");
                printf("Nome da Agência: %s\n", nomeAgencia);
                printf("Cliente: %s\n", cliente);
                printf("Data de Abertura: %s\n", dataAbertura);
                printf("Saldo: %.2f\n", saldo);
                printf("Status: %s\n", status);
                printf("Número da Conta: %d\n", numConta);
                printf("\n");

                // Menu de edição
                int op;
                do
                {
                    printf("\nop UMA OPÇÃO:\n");
                    printf("1. EDITAR NOME DA AGÊNCIA\n");
                    printf("2. EDITAR CLIENTE\n");
                    printf("3. EDITAR DATA DE ABERTURA\n");
                    printf("4. EDITAR SALDO\n");
                    printf("5. EDITAR STATUS\n");
                    printf("6. SAIR\n");

                    printf("Opção: ");
                    if (scanf("%d", &op) != 1)
                    {
                        printf("Entrada inválida. Digite um número.\n");
                        while (getchar() != '\n')
                        {
                            // Limpa o buffer de entrada para evitar loop infinito
                        }
                        continue; // Volta para o início do loop
                    }
                    getchar(); // Limpa o caractere de nova linha do buffer de entrada

                    switch (op)
                    {
                    case 1:
                        printf("Novo Nome da Agência: ");
                        scanf("%49[^\n]", nomeAgencia);
                        getchar(); // Limpa o buffer do teclado
                        break;
                    case 2:
                        printf("Novo nome do Cliente: ");
                        scanf("%99[^\n]", cliente);
                        getchar(); // Limpa o buffer do teclado
                        break;
                    case 3:
                        printf("Nova Data de Abertura (dd/mm/aaaa): ");
                        scanf("%10[^\n]", dataAbertura);
                        getchar(); // Limpa o buffer do teclado
                        break;
                    case 4:
                        printf("Novo Saldo: ");
                        scanf("%f", &saldo);
                        getchar(); // Limpa o buffer do teclado
                        break;
                    case 5:
                        printf("Novo Status: ");
                        scanf("%9[^\n]", status);
                        getchar(); // Limpa o buffer do teclado
                        break;
                    case 6:
                        break; // Sai do loop
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                        break;
                    }
                } while (op != 6);

                // Exibi os dados atualizados
                printf("\nDADOS DA CONTA ATUALIZADOS:\n");
                printf("Nome da Agência: %s\n", nomeAgencia);
                printf("Cliente: %s\n", cliente);
                printf("Data de Abertura: %s\n", dataAbertura);
                printf("Saldo: %.2f\n", saldo);
                printf("Status: %s\n", status);
                printf("Número da Conta: %d\n", numConta);
                printf("\n");

                // Atualiza a linha com os novos dados, incluindo o número da conta
                fprintf(temp, "%s\t%s\t%s\t%.2f\t%s\t%d\n", nomeAgencia, cliente, dataAbertura, saldo, status, numConta);
            }
            else
            {
                // Se a conta não corresponder ao número da conta, copie a linha original
                fputs(linha, temp);
            }
        }
        else
        {
            printf("Erro: Formato de linha de conta inválido.\n");
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Se a conta foi encontrada e editada, o arquivo temporário é renomeado para substituir o original
    if (contaEncontrada)
    {
        remove("contas.txt");
        rename("temp.txt", "contas.txt");
        printf("Dados da conta atualizados com sucesso.\n");
    }
    else
    {
        printf("Conta com número %d não encontrada.\n", numeroConta);
        remove("temp.txt"); // Remove o arquivo temporário
    }
}
