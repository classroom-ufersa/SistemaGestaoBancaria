
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
    char status[11];
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
    int totalContas = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        char nomeAgencia[50];
        char cliente[100];
        char dataAbertura[11];
        float saldo;
        char status[11];
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
            totalContas++;
        }
        else
        {
            printf("Erro: Formato de linha de conta inválido.\n");
        }
    }
    printf("Total de Contas Bancarias Cadastradas: %d\n", totalContas);
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
                char status[11];
                int numeroConta;

                (sscanf(linha, "%49[^\t]\t%99[^\t]\t%s\t%f\t%s\t%d", nomeAgencia, cliente, dataAbertura, &saldo, status, &numeroConta) == 6);

                printf("\nCONTA ENCONTRADA:\n");
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
        char status[11];
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

// Função para ordenar o arquivo 'contas.txt' em ordem alfabética
void ordenarArquivoEmOrdemAlfabetica()
{
    FILE *arquivo = fopen("contas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt' para leitura.\n");
        exit(1);
    }

    // Ler todas as linhas do arquivo e armazená-las em um vetor de strings dinâmico
    char **linhas = NULL;
    char linha[256];
    int numLinhas = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        char *copiaLinha = strdup(linha); // Copiar a linha para o vetor dinâmico
        if (copiaLinha == NULL)
        {
            printf("Erro: Falha na alocação de memória.\n");
            exit(1);
        }

        linhas = realloc(linhas, (numLinhas + 1) * sizeof(char *));
        if (linhas == NULL)
        {
            printf("Erro: Falha na alocação de memória.\n");
            exit(1);
        }

        linhas[numLinhas] = copiaLinha;
        numLinhas++;
    }

    fclose(arquivo);

    // Ordenar o vetor de linhas em ordem alfabética diretamente
    for (int i = 0; i < numLinhas - 1; i++)
    {
        for (int j = i + 1; j < numLinhas; j++)
        {
            if (strcasecmp(linhas[i], linhas[j]) > 0)
            {
                // Trocar as linhas de posição se estiverem fora de ordem
                char *temp = linhas[i];
                linhas[i] = linhas[j];
                linhas[j] = temp;
            }
        }
    }

    // Reabrir o arquivo para escrita
    arquivo = fopen("contas.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro: Não foi possível abrir o arquivo 'contas.txt' para escrita.\n");
        exit(1);
    }

    // Escrever as linhas ordenadas de volta no arquivo
    for (int i = 0; i < numLinhas; i++)
    {
        fputs(linhas[i], arquivo);
        free(linhas[i]); // Liberar a memória alocada para cada linha
    }

    free(linhas); // Liberar o vetor de linhas
    fclose(arquivo);
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

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        char nomeAgencia[50];
        char cliente[100];
        char dataAbertura[11];
        float saldo;
        char status[11];
        int numConta;

        if (sscanf(linha, "%49[^\t]\t%99[^\t]\t%s\t%f\t%s\t%d", nomeAgencia, cliente, dataAbertura, &saldo, status, &numConta) == 6)
        {
            if (numeroConta == numConta)
            {
                contaEncontrada = 1;
                printf("DADOS DA CONTA QUE SERÁ EDITADA:\n");
                printf("Nome da Agência: %s\n", nomeAgencia);
                printf("Cliente: %s\n", cliente);
                printf("Data de Abertura: %s\n", dataAbertura);
                printf("Saldo: %.2f\n", saldo);
                printf("Status: %s\n", status);
                printf("Número da Conta: %d\n", numConta);
                printf("\n");

                // Menu de edição
                int op;
                int nomeValido = 0; // Variável para verificar se o nome do cliente fornecido é válido
                bool entradaValida = false; // Variável para verificar se a data de abertura fornecida é válida
                int statusValido = 0; // Variável para verificar se o status fornecido é válido
                int saldoValido = 0;  // Variável para verificar se o saldo fornecido é válido
                
                do // Loop externo para o menu de edição
                {
                    printf("\nESCOLHA UMA OPÇÃO:\n");
                    printf("1. EDITAR NOME DA AGÊNCIA\n");
                    printf("2. EDITAR NOME DO CLIENTE\n");
                    printf("3. EDITAR DATA DE ABERTURA\n");
                    printf("4. EDITAR SALDO\n");
                    printf("5. EDITAR STATUS\n");
                    printf("6. SAIR\n");

                    printf("Opção: ");
                    scanf("%d", &op);

                    if (op < 1 || op > 6)
                    {
                        printf("Opção inválida. Digite um número válido de 1 a 6.\n");
                        continue; // Volta para o início do loop
                    }

                    switch (op)
                    {
                    case 1:
                        printf("Novo Nome da Agência: ");
                        scanf(" %[^\n]", nomeAgencia);
                        break;
                    case 2:
                       // Verifica se o nome do cliente fornecido é válido
            do
            {
                printf("Informe o nome do cliente: ");
                scanf(" %99[^\n]", cliente);
                getchar(); // Limpar o buffer

                nomeValido = 1;
                for (int i = 0; cliente[i] != '\0'; i++)
                {
                    if (!isalpha(cliente[i]) && !isspace(cliente[i]))
                    {
                        nomeValido = 0;
                        break;
                    }
                }

                if (!nomeValido)
                {
                    printf("O nome digitado contém caracteres inválidos.\n");
                }
            } while (!nomeValido);

                        break;
                    case 3:
                        // Verifica se a data de abertura fornecida é válida
                        do
                        {
                            printf("Informe a data de abertura da conta (dd/mm/aaaa): ");
                            scanf(" %11[^\n]", dataAbertura);

                            // Verifica se a entrada tem 10 caracteres, incluindo duas barras
                            if (strlen(dataAbertura) == 10)
                            {
                                // Verifica se os caracteres nas posições 2 e 5 são barras
                                if (dataAbertura[2] == '/' && dataAbertura[5] == '/')
                                {
                                    // Verifica se os caracteres restantes são dígitos numéricos
                                    bool isNumeric = true;
                                    for (int i = 0; i < 10; i++)
                                    {
                                        if (i != 2 && i != 5 && !isdigit(dataAbertura[i]))
                                        {
                                            isNumeric = false;
                                            break;
                                        }
                                    }
                                    if (isNumeric)
                                    {
                                        entradaValida = true;
                                    }
                                }
                            }

                            if (!entradaValida)
                            {
                                printf("Formato de data inválido. Por favor, tente novamente.\n");
                            }
                        } while (!entradaValida);

                        break;
                    case 4:
                        // Verifica se o saldo da conta fornecido é válido
                        do
                        {
                            printf("Informe o saldo da conta: ");
                            if (scanf(" %f", &saldo) == 1)
                            {
                                saldoValido = 1;
                            }
                            else
                            {
                                printf("Entrada inválida. Digite novamente:\n");
                                // Limpar o buffer de entrada para evitar loop infinito
                                while (getchar() != '\n')
                                    ;
                            }
                        } while (!saldoValido);
                        break;
                    case 5:
                        // Verifica se o status da conta fornecido é válido
                        do
                        {
                            printf("Informe o status da conta (ativa, desativada, bloqueada): ");
                            scanf(" %10[^\n]", status);
                            getchar(); // Limpar o buffer

                            statusValido = 1;
                            for (int i = 0; status[i] != '\0'; i++)
                            {
                                if (!isalpha(status[i]) && !isspace(status[i]))
                                {
                                    statusValido = 0;
                                    break;
                                }
                            }

                            if (!statusValido)
                            {
                                printf("O status digitado contém caracteres inválidos.\n");
                            }
                        } while (!statusValido);
                        break;
                    case 6:
                        break; // Sair
                    }

                    // Exibe os dados atualizados
                    printf("\nDADOS DA CONTA ATUALIZADOS:\n");
                    printf("Nome da Agência: %s\n", nomeAgencia);
                    printf("Cliente: %s\n", cliente);
                    printf("Data de Abertura: %s\n", dataAbertura);
                    printf("Saldo: %.2f\n", saldo);
                    printf("Status: %s\n", status);
                    printf("Número da Conta: %d\n", numConta);
                    printf("\n");

                } while (op != 6); // Sai do loop externo quando a opção 6 for selecionada

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

    // Remove o arquivo original e renomeia o arquivo temporário
    remove("contas.txt");
    rename("temp.txt", "contas.txt");

    // Se a conta não foi encontrada, mostra a mensagem apropriada
    if (!contaEncontrada)
    {
        printf("Conta com número %d não encontrada.\n", numeroConta);
    }
    ordenarArquivoEmOrdemAlfabetica();
}

// Função libera conta vai liberar a memoria ocupada
void libera_conta(ContaBancaria *novaConta)
{
    free(novaConta);
}
