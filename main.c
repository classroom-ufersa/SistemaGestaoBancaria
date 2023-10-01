#include "contaBancaria.c"
#include "agencia.c"
#define TAMANHO_INICIAL 10

int main()
{
    char nomeAgencia[50];
    char cliente[100];
    char dataAbertura[11];
    float saldo;
    char status[11];
    int numeroConta;

    int tamanho_atual = TAMANHO_INICIAL; // Variável para rastrear o tamanho atual do array de contas

    // Aloca memória inicial para o array de ponteiros de contas
    ContaBancaria **conta = malloc(sizeof(ContaBancaria *) * TAMANHO_INICIAL);
    if (conta == NULL) // verifica se a alocação de memória foi bem sucedida ou não
    {
        exit(1); // // encerrar
    }
    int count_conta = 0;
    int op;
    char input[100]; // Buffer para entrada do usuário

    while (1)
    {
        printf("\n MENU DE OPÇÕES \n");
        printf("1 - ADICIONAR CONTA BANCÁRIA\n");
        printf("2 - REMOVER CONTA BANCÁRIA\n");
        printf("3 - LISTAR CONTAS CADASTRADAS\n");
        printf("4 - BUSCAR CONTA BANCÁRIA\n");
        printf("5 - EDITAR CONTA BANCÁRIA\n");
        printf("6 - CONSULTAR CONTAS ATIVAS EM UMA DADA AGÊNCIA\n");
        printf("7 - CONSULTAR QUANTITATIVO DE AGÊNCIAS\n");
        printf("8 - SAIR\n");

        printf("Escolha uma opção: ");
        scanf("%s", input);

        // converte a entrada para um número inteiro
        char *endptr;
        op = strtol(input, &endptr, 10);

        // Verifica se a conversão foi bem-sucedida e se o número está dentro do intervalo desejado
        if (*endptr != '\0' || op < 1 || op > 8)
        {
            printf("Opção inválida. Digite um número válido de 1 a 8.\n");
            continue; // Volta para o início do loop
        }

        switch (op)
        {
        case 1:
            // criar conta bancaria
            printf("Informe o nome da agencia: ");
            scanf(" %49[^\n]", nomeAgencia);
            printf("Informe o nome do cliente: ");
            scanf(" %99[^\n]", cliente);
            printf("Informe a data de abertura da conta (dd/mm/aaaa): ");
            scanf(" %10[^\n]", dataAbertura);
            printf("Informe o saldo da conta: ");
            scanf(" %f", &saldo);
            printf("Informe o status da conta (ativa, desativada, bloqueada): ");
            scanf(" %10[^\n]", status);
            printf("Informe o numero da conta: ");
            scanf(" %d", &numeroConta);

            if (count_conta >= tamanho_atual)
            {
                // Se o array está cheio, realoque memória para um novo array com tamanho maior
                tamanho_atual *= 2;
                conta = realloc(conta, sizeof(ContaBancaria *) * tamanho_atual);

                if (conta == NULL)
                {
                    exit(1); // Tratar erro de realocação de memória
                }
            }
            conta[count_conta] = criarContaBancaria( nomeAgencia, cliente, dataAbertura, saldo, status, numeroConta);
            adicionarContaEmOrdem(conta[count_conta]);
            count_conta;
            break;

        case 2:
            printf("Informe o numero da conta que voce deseja remover:\n ");
            int numConta;
            if (scanf("%d", &numConta) != 1)
            {
                printf("Entrada inválida. Digite um número válido.\n");
                while (getchar() != '\n')
                {
                    // Limpa o buffer de entrada para evitar loop infinito
                }
                continue; // Volta para o início do loop
            }

            removerContaPorNumero(numConta);
            break;
        case 3:
            printf("\n\tTODAS AS CONTAS BANCARIAS CADASTRADAS\n");
            listarContasCadastradas();
            break;
        case 4:
            printf("Informe o numero da conta que voce deseja buscar:\n ");
            if (scanf("%d", &numConta) != 1)
            {
                printf("Entrada inválida. Digite um número válido.\n");
                while (getchar() != '\n')
                {
                    // Limpa o buffer de entrada para evitar loop infinito
                }
                continue; // Volta para o início do loop
            }

            buscarContaPorNumero(numConta);
            break;
        case 5:
            printf("Informe o numero da conta que voce deseja editar:\n ");
            if (scanf("%d", &numConta) != 1)
            {
                printf("Entrada inválida. Digite um número válido.\n");
                while (getchar() != '\n')
                {
                    // Limpa o buffer de entrada para evitar loop infinito
                }
                continue; // Volta para o início do loop
            }
            editarDadosContaPorNumero(numConta);
            break;
        case 6:
            // Implemente a consulta de contas ativas em uma agência aqui
            break;
        case 7:
            printf("\n\tTODAS AS AGÊNCIAS CADASTRADAS\n");
            listarAgencias();
            break;
        case 8:
            printf("Saindo...\n");
            exit(0); // Termina o programa
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }
// Libera a memória alocada para cada conta individualmente antes de liberar o array de ponteiros de conta
    for (int i = 0; i < count_conta; i++)
    {
        libera_conta(conta[i]);
    }

    // Libera a memória alocada para o array de ponteiros de conta
    free(conta);
    return 0;
}