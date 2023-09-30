#include "contaBancaria.c"
#include "agencia.c"

int main()
{

    char nomeAgencia[50];
    char cliente[100];
    char dataAbertura[11];
    float saldo;
    char status[10];
    int numConta;

    int op;
    char input[100]; // Buffer para entrada do usuário

    while (1)
    {
        printf("\n MENU DE OPÇÕES \n");
        printf("1 - ADICIONAR CONTA BANCÁRIA\n");
        printf("2 - REMOVER CONTA BANCÁRIA\n");
        printf("3 - LISTAR CONTAS CADASTRADAS\n");
        printf("4 - BUSCAR CONTA\n");
        printf("5 - EDITAR CONTA\n");
        printf("6 - CONSULTAR CONTAS ATIVAS EM UMA DADA AGÊNCIA\n");
        printf("7 - CONSULTAR QUANTITATIVO DE AGÊNCIAS\n");
        printf("8 - SAIR\n");

        printf("Escolha uma opção: ");
        scanf("%s", input);

       // Tente converter a entrada para um número inteiro
        char *endptr;
        op = strtol(input, &endptr, 10);

        // Verifique se a conversão foi bem-sucedida e se o número está dentro do intervalo desejado
        if (*endptr != '\0' || op < 1 || op > 8) {
            printf("Opção inválida. Digite um número válido de 1 a 8.\n");
            continue; // Volta para o início do loop
        }

        switch (op)
        {
        case 1:
            /*// criar agencia bancaria
        printf("Informe o nome da agencia: ");
        scanf("%49[^\n]", nomeAgencia);
        int resultado = buscarAgenciaPorNome(nomeAgencia);
        if (resultado == 0)
        {
            printf("Agência encontrada.\n");
        }
        else
        {
            printf("Agência não encontrada.\n");
        }
        printf("Informe o nome do cliente: ");
        scanf("%99[^\n]", &cliente);
        printf("Informe a data de abertura da conta (dd/mm/aaaa): ");
        scanf("%10[^\n]", dataAbertura);
        printf("Informe o saldo da conta: ");
        scanf(" %f", saldo);
        printf("Informe o status da conta (ativa, desativada, bloqueada): ");
        scanf("%9[^\n]", status);
        printf("Informe o numero da conta: ");
        scanf(" %d", &numConta);*/
            break;
        case 2:
            // Implemente a remoção de conta aqui
            break;
        case 3:
            printf("\n\tTODAS AS CONTAS BANCARIAS CADASTRADAS\n");
            listarContasCadastradas();
            break;
        case 4:
            printf("Informe o numero da conta que voce deseja buscar:\n ");
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

            buscarContaPorNumero(numConta);
            break;
        case 5:
            // Implemente a edição de conta aqui
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

    return 0;
}