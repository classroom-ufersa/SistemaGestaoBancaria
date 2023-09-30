#include "contaBancaria.c"
#include "agencia.c"

int main()
{   
    const char *nomeAgenciaBusca = "Barbalha"; // Substitua pelo nome da agência que deseja buscar
    int resultado = buscarAgenciaPorNome(nomeAgenciaBusca);

    if (resultado == 0) {
        printf("Agência encontrada.\n");
    } else {
        printf("Agência não encontrada.\n");
    }
   /* char nome[51], localizacao[51], horario[15];
    int numero;
    int i;
    int op;
    do
    {
        printf("\n MENU DE OPCOES \n");
        printf("1 - ADICIONAR CONTA BANCÁRIA\n");
        printf("2 - REMOVER CONTA BANCÁRIA\n");
        printf("3 - LISTAR CONTAS CADASTRADAS\n");
        printf("4 - BUSCAR CONTA\n");
        printf("5 - EDITAR CONTA\n");
        printf("6 - CONSULTAR CONTAS ATIVAS EM UMA DADA AGÊNCIA\n");
        printf("7 - CONSULTAR QUANTITATIVO DE AGÊNCIAS");
        printf("8 - SAIR\n");

        printf("Escolha uma opção: ");
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
        // criar agencia bancaria 
        printf("Informe o nome da agencia: ");
        scanf(" %[^\n]", nome);
        printf("Informe o codigo da agencia: ");
        scanf(" %d", &numero);
        printf("Informe a localização da agencia: ");
        scanf(" %[^\n]", localizacao);
        printf("Informe o horario de funcionamento da agencia: ");
        scanf(" %[^\n]", horario);
            // Implemente a criação de agência aqui
            break;
        case 2:
            // Implemente o cadastro de conta aqui
            break;
        case 3:
            // Implemente a remoção de conta aqui
            break;
        case 4:
            // Implemente a listagem de contas cadastradas aqui
            break;
        case 5:
            // Implemente a busca de conta aqui
            break;
        case 6:
            // Implemente a edição de conta aqui
            break;
        case 7:
            // Implemente a consulta de contas ativas em uma agência aqui
            break;
        case 8:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (op != 8);*/

    return 0;
}
