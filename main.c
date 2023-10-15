#include "agencia.c"

int main()
{
    printf("\nBem vindo ao nosso Programa!\n");
    printf("O presente sistema tem como função auxiliar no gerenciamento de uma rede de bancos, manipulando agências bancarias e contas bancárias.\n");
    printf("AUTORES:\nDiego Nascimento de Oliveira\nPaulo Henrique Medeiros da Silva\n\n");

    // Variáveis para auxiliar na execução da main
    int qntcontas = 0; // Variável para armazenar a quantidade de contas
    int qntagencias = 0; // Variável para armazenar a quantidade de agencias 
    char opcao;// Armazena a opção verificada 
    Agenciabancaria **agencias = NULL;
    agencias = ler_arquivo(agencias, &qntagencias); // carregar dados salvos em um arquivo

    // Variváveis utilizadas na criação de um agência
    char nome[51], localizacao[51], horario[12]; // arrays para agencia
    int numero, i;

    // Variaveis utilizadas nas veririficações
    int agenciaEncontrada = 0;  // Variável para verificar se o numero da agencia fornecido é válido
    int contaEncontrada = 0;    // Variável para verificar se o numero da conta fornecido é válido
    int nomeValido = 0;     // Variável para verificar se o nome da agência fornecido é válido
    int localizacaoValida = 0;  // Variável para verificar se a localização da agência fornecida é válida
    bool horarioValido = false; // Variável para verificar se o horario de funcionamento fornecida é válido
    bool numValido = false; // Variável para verificar se o numero do codigo da agencia fornecido é válido
    char input[50]; // Armazena número como string
    int numAgencia; //  Variável para armazenar o valor do codigo de uma agência 

    do
    {
        printf("\n MENU DE OPÇÕES \n");
        printf("1 - ADICIONAR AGÊNCIA BANCÁRIA\n");
        printf("2 - ADICIONAR CONTA BANCÁRIA\n");
        printf("3 - REMOVER CONTA BANCÁRIA\n");
        printf("4 - LISTAR CONTAS CADASTRADAS\n");
        printf("5 - BUSCAR CONTA BANCÁRIA\n");
        printf("6 - EDITAR CONTA BANCÁRIA\n");
        printf("7 - CONSULTAR CONTAS ATIVAS EM UMA DADA AGÊNCIA\n");
        printf("8 - CONSULTAR QUANTITATIVO DE AGÊNCIAS\n");
        printf("9 - SAIR\n");
        opcao = le_opcao('1', '9');

        switch (opcao)
        {
        case '1':
            // criar agencia bancaria
            // Verifica se o nome da agência fornecido é válido
            do
            {
                printf("Informe o nome da agencia: ");
                scanf(" %[^\n]", nome);
                getchar(); // Limpar o buffer

                nomeValido = 1;
                for (int i = 0; nome[i] != '\0'; i++)
                {
                    if (!isalpha(nome[i]) && !isspace(nome[i]))
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

            // Verifica se o numero do codigo da agencia fornecido é válido
            do
            {
                printf("Informe o codigo da agencia: ");
                if (scanf(" %49s", input) != 1)
                {
                    printf("Entrada inválida. Tente novamente.\n");
                    while (getchar() != '\n')
                    {
                        // Limpa o buffer de entrada para evitar loop infinito
                    }
                }
                else if (!entradaContemApenasDigitos(input))
                {
                    printf("Entrada inválida. Apenas números são permitidos. Tente novamente.\n");
                }
                else
                {
                    sscanf(input, "%d", &numero);
                    numValido = true;
                }
            } while (!numValido);

            // Verifica se a localização da agência fornecida é válida
            do
            {
                printf("Informe a localização da agência: ");
                scanf(" %[^\n]", localizacao);
                getchar(); // Limpar o buffer

                localizacaoValida = 1;
                for (int i = 0; localizacao[i] != '\0'; i++)
                {
                    if (!isalpha(localizacao[i]) && !isspace(localizacao[i]))
                    {
                        localizacaoValida = 0;
                        break;
                    }
                }

                if (!localizacaoValida)
                {
                    printf("A localização digitada contém caracteres inválidos.\n");
                }
            } while (!localizacaoValida);

            // Verifica se o horário de funcionamento da agência fornecido é válido
            while (!horarioValido)
            {
                printf("Informe o horário de funcionamento da agência (entrada saída, no formato HH:MM HH:MM): ");
                scanf(" %12[^\n]", horario); // Limitar a leitura a 12 caracteres, deixando espaço para o caractere nulo

                int entradaHoras, entradaMinutos, saidaHoras, saidaMinutos;

                // Verificar se a entrada tem o formato correto HH:MM HH:MM
                if (sscanf(horario, "%d:%d %d:%d", &entradaHoras, &entradaMinutos, &saidaHoras, &saidaMinutos) == 4)
                {
                    // Verificar se as horas e minutos estão em faixas válidas
                    if (entradaHoras >= 0 && entradaHoras <= 23 && entradaMinutos >= 0 && entradaMinutos <= 59 &&
                        saidaHoras >= 0 && saidaHoras <= 23 && saidaMinutos >= 0 && saidaMinutos <= 59)
                    {
                        horarioValido = true;
                    }
                    else
                    {
                        printf("Horário inválido. Certifique-se de que as horas estejam entre 0 e 23 e os minutos entre 0 e 59.\n");
                    }
                }
                else
                {
                    printf("Formato inválido. Use o formato HH:MM HH:MM.\n");
                }

                // Limpar o buffer de entrada
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ;
            }

            agencias = realloc(agencias, (qntagencias + 1) * sizeof(Agenciabancaria));
            agencias[qntagencias] = criar_agencia(nome, numero, localizacao, horario);
            qntagencias++;
            salva_arquivo(agencias, qntagencias);
            break;

        case '2':
            while (!agenciaEncontrada)
            {
                printf("Informe o código da agência onde deseja cadastrar o cliente: ");
                if (scanf("%d", &numero) != 1)
                {
                    printf("Entrada inválida. Tente novamente.\n");
                    while (getchar() != '\n')
                    {
                        // Limpa o buffer de entrada para evitar loop infinito
                    }
                    continue; // Tente novamente
                }

                for (i = 0; i < qntagencias; i++)
                {
                    if (agencias[i]->codigo == numero)
                    {
                        agenciaEncontrada = 1;
                        break;
                    }
                }

                if (!agenciaEncontrada)
                {
                    printf("Agencia não existe. Tente novamente.\n");
                }
            }

            agencias[i] = cadastrar_conta(agencias[i]);
            salva_arquivo(agencias, qntagencias);
            break;

        case '3':
            // remover conta
            do
            {
                printf("Informe o código da agência em que deseja remover a conta:\n");
                if (scanf(" %49s", input) != 1)
                {
                    printf("Entrada inválida. Digite um número válido.\n");
                    while (getchar() != '\n')
                    {
                        // Limpa o buffer de entrada para evitar loop infinito
                    }
                    continue; // Tente novamente
                }

                char *endptr;
                numAgencia = strtol(input, &endptr, 10);

                if (*endptr != '\0')
                {
                    printf("Entrada inválida. Digite um número válido.\n");
                    continue; // Tente novamente
                }

                for (i = 0; i < qntagencias; i++)
                {
                    if (agencias[i]->codigo == numAgencia)
                    {
                        agenciaEncontrada = 1;
                        break;
                    }
                }

                if (!agenciaEncontrada)
                {
                    printf("Agência não localizada.\n");
                    break; // Sai do loop e retorna ao menu principal
                    
                   
                }

                do
                {
                    printf("Informe o número da conta que deseja remover da agência %d:\n", numAgencia);

                    if (scanf(" %49s", input) != 1)
                    {
                        printf("Entrada inválida. Digite um número válido.\n");
                        while (getchar() != '\n')
                        {
                            // Limpa o buffer de entrada para evitar loop infinito
                        }
                        continue; // Tente novamente
                    }

                    numero = strtol(input, &endptr, 10);

                    if (*endptr != '\0')
                    {
                        printf("Entrada inválida. Digite um número válido.\n");
                        continue; // Tente novamente
                    }

                    for (i = 0; i < qntagencias; i++)
                    {
                        if (agencias[i]->codigo == numAgencia)
                        {
                            Contabancaria *conta = buscar_conta(agencias[i]->contas, numero);
                            if (conta != NULL)
                            {
                                contaEncontrada = 1;
                                break;
                            }
                        }
                    }

                    if (!contaEncontrada)
                    {
                        printf("Conta não localizada na agência %d.\n", numAgencia);
                            break; // Sai do loop
                    }
                    
                    else
                    {
                        agencias[i] = remove_conta(agencias[i], numero);
                        salva_arquivo(agencias, qntagencias);
                        printf("Conta removida!\n");
                    }
                } while (!contaEncontrada);
            } while (!agenciaEncontrada);
            break;

        case '4':
            // listar agencias
            listar_agencias(agencias, qntagencias);
            break;

        case '5':
            do
            {
                printf("Informe o código da agência em que deseja buscar a conta:\n");

                if (scanf(" %49s", input) != 1)
                {
                    printf("Entrada inválida. Digite um número válido.\n");
                    while (getchar() != '\n')
                    {
                        // Limpa o buffer de entrada para evitar loop infinito
                    }
                    continue; // Tente novamente
                }

                char *endptr;
                numAgencia = strtol(input, &endptr, 10);

                if (*endptr != '\0')
                {
                    printf("Entrada inválida. Digite um número válido.\n");
                    continue; // Tente novamente
                }

                for (i = 0; i < qntagencias; i++)
                {
                    if (agencias[i]->codigo == numAgencia)
                    {
                        agenciaEncontrada = 1;
                        break;
                    }
                }

                if (!agenciaEncontrada)
                {
                    printf("Agência não localizada.\n");

                    break; // Sai do loop e retorna ao menu principal
                }

                do
                {
                    printf("Informe o número da conta que deseja buscar na agência %d:\n", numAgencia);

                    if (scanf(" %49s", input) != 1)
                    {
                        printf("Entrada inválida. Digite um número válido.\n");
                        while (getchar() != '\n')
                        {
                            // Limpa o buffer de entrada para evitar loop infinito
                        }
                        continue; // Tente novamente
                    }

                    numero = strtol(input, &endptr, 10);

                    if (*endptr != '\0')
                    {
                        printf("Entrada inválida. Digite um número válido.\n");
                        continue; // Tente novamente
                    }

                    for (i = 0; i < qntagencias; i++)
                    {
                        if (agencias[i]->codigo == numAgencia)
                        {
                            Contabancaria *contaencontrada = buscar_conta(agencias[i]->contas, numero);
                            if (contaencontrada != NULL)
                            {
                                printf(" \nInformações da conta: \n");
                                printf("Nome do cliente: %s\n", contaencontrada->cliente);
                                printf("Data de abertura: %s\n", contaencontrada->data);
                                printf("Número da conta: %d\n", contaencontrada->numero);
                                printf("Saldo: %.2f\n", contaencontrada->saldo);
                                printf("Status: %s\n", contaencontrada->status);
                                contaEncontrada = 1;
                                break;
                            }
                        }
                    }

                    if (!contaEncontrada)
                    {
                        printf("Conta não localizada na agência %d.\n", numAgencia);
                        break; // Sai do loop de busca de conta e retorna ao menu principal
                    }
                } while (!contaEncontrada);
            } while (!agenciaEncontrada);
            break;

        case '6':
            do
            {

                printf("Informe o código da agência em que deseja fazer alguma modificação:\n");
                if (scanf(" %49s", input) != 1)
                {
                    printf("Entrada inválida. Digite um número válido.\n");
                    while (getchar() != '\n')
                    {
                        // Limpa o buffer de entrada para evitar loop infinito
                    }
                    continue; // Tente novamente
                }

                char *endptr;
                numAgencia = strtol(input, &endptr, 10);

                if (*endptr != '\0')
                {
                    printf("Entrada inválida. Digite um número válido.\n");
                    continue; // Tente novamente
                }

                for (i = 0; i < qntagencias; i++)
                {
                    if (agencias[i]->codigo == numAgencia)
                    {
                        agenciaEncontrada = 1;
                        break;
                    }
                }

                if (!agenciaEncontrada)
                {
                    printf("Agência não localizada.\n");

                    break; // Sai do loop e retorna ao menu principal
                }

                do
                {
                    printf("Informe o número da conta que deseja modificar na agência %d:\n", numAgencia);
                    if (scanf(" %49s", input) != 1)
                    {
                        printf("Entrada inválida. Digite um número válido.\n");
                        while (getchar() != '\n')
                        {
                            // Limpa o buffer de entrada para evitar loop infinito
                        }
                        continue; // Tente novamente
                    }

                    numero = strtol(input, &endptr, 10);

                    if (*endptr != '\0')
                    {
                        printf("Entrada inválida. Digite um número válido.\n");
                        continue; // Tente novamente
                    }

                    Contabancaria *contaeditar = buscar_conta(agencias[i]->contas, numero);
                    if (contaeditar != NULL)
                    {
                        printf("\nInformacoes da conta antes da edicao:\n");
                        printf("Cliente: %s\n", contaeditar->cliente);
                        printf("Numero: %d\n", contaeditar->numero);
                        printf("Saldo: %.2f\n", contaeditar->saldo);
                        printf("Status: %s\n", contaeditar->status);

                        editar_conta(contaeditar);

                        printf("\nInformacoes da conta depois da edicao:\n");
                        printf("Cliente: %s\n", contaeditar->cliente);
                        printf("Numero: %d\n", contaeditar->numero);
                        printf("Saldo: %.2f\n", contaeditar->saldo);
                        printf("Status: %s\n", contaeditar->status);

                        salva_arquivo(agencias, qntagencias);
                        contaEncontrada = 1; // Conta encontrada e editada
                        break;
                    }
                    if (!contaEncontrada)
                    {
                        printf("Conta não localizada na agência %d.\n", numAgencia);
                        break; // Sai do loop de busca de conta e retorna ao menu principal
                    }

                } while (!contaEncontrada);
            } while (!agenciaEncontrada);
            break;

        case '7':
            // consultar contas ativas
            do
            {

                printf("Informe o codigo da agencia da qual deseja consultar as contas ativas \n");
                if (scanf(" %49s", input) != 1)
                {
                    printf("Entrada inválida. Digite um número válido.\n");
                    while (getchar() != '\n')
                    {
                        // Limpa o buffer de entrada para evitar loop infinito
                    }
                    continue; // Tente novamente
                }

                char *endptr;
                numAgencia = strtol(input, &endptr, 10);

                if (*endptr != '\0')
                {
                    printf("Entrada inválida. Digite um número válido.\n");
                    continue; // Tente novamente
                }

                for (i = 0; i < qntagencias; i++)
                {
                    if (agencias[i]->codigo == numAgencia)
                    {
                        listar_contas_ativas(agencias[i]->contas, numAgencia);
                        agenciaEncontrada = 1;
                        break;
                    }
                }

                if (!agenciaEncontrada)
                {
                    printf("Agência não localizada.\n");

                    break; // Sai do loop e retorna ao menu principal
                }
            } while (!agenciaEncontrada);
            break;
        case '8':
            // informa a quantidade de agencias que está cadastrada
            printf("Quantidade de agências cadastradas: %d\n", qntagencias);
            break;

        case '9':

            printf("Programa finalizado com sucesso! Obrigado por usar nosso programa.\n");
            break;

        default:
            printf("Tente novamente, opcao fornecida está invalida! \n");
        }
    } while (opcao != '9');

    liberar_agencias(agencias, qntagencias); // funcao para liberar a memoria alocada para agencias bancarias
    return 0;
}