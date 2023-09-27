#include "agencia.c"

int main(void){

    Contabancaria * nome1 = criar_conta("joao", "15/09/2023", 1506.65, "ativo", 12711 );
    printf(" %s\n", nome1->cliente);
    printf(" %s\n", nome1->data);
    printf(" %.2f\n", nome1->saldo);
    printf(" %s\n", nome1->status);
    printf(" %d\n", nome1->numero);

    Agenciabancaria * agencia = criar_agencia("Banco", 1134, "São Bento", "09:30 ate 15:00" );
    printf(" %s\n", agencia->nome);
    printf(" %d\n", agencia->codigo);
    printf(" %s\n", agencia->localizacao);
    printf(" %s\n", agencia->horario);

    agencia = cadastrar_cliente (nome1, agencia);
    printf(" %s\n", agencia->contas->conta->cliente);
   


   
    
 
    int op;


do {

    printf("\n MENU DE OPÇÕES \n");
    printf(" 1 - Criar agência bancaria");
    printf(" 2 - Adicionar conta");
    printf(" 3 - Remover conta");
    printf(" 4 - Listar contas cadastradas");
    printf(" 5 - Buscar conta");
    printf(" 6 - Editar conta");
    printf(" 7 - Consultar contas ativas em uma dada agência");
    printf(" 8 - Sair");

    if (scanf(" %d", &op) != 1) // verifica se o que foi digitado é um inteiro
    {
        printf(" Invalido. Tente novamente");
        
    }


    switch (op)
    {
        case 1:

        // criar agencia bancaria 

        Agenciabancaria * agencia = criar_agencia(nome, codigo, localizacao, horario);

        printf("Informe o nome da agência \n");
        scanf(" %[^\n]", agencia->nome);

        printf("Informe o código da agência \n");
        scanf (" %d", agencia->codigo);
        
        printf("Informe a localização da agencia \n");
        scanf(" %[^\n]", agencia->localizacao);

        printf("Informe o horário de funcionamento");
        scanf(" %[^\n]", agencia->horario);



        break;
/*
        case 2:
        // Cadastrar cliente

       Contabancaria * con = cadastrar_cliente(codigo, cliente, data, saldo, status, numero)

        printf("Informe o código da agencia: \n");
        scanf(" %d", con->codigo);

        printf("Informe o nome do cliente \n");
        scanf(" %[^\n]", con->cliente);

        printf("Informe a data de abertura da conta \n");
        scanf(" %[^\n]", con->data);

        printf("Informe o saldo da conta bancaria \n");
        scanf(" %.2f", con->saldo);

        printf("Informe qual o status da conta (Ativa, Desativada ou Bloqueaad) \n");
        scanf(" %[^\n]", con->status);

        printf("Digite o numero da conta");
        scanf(" %d", con->numero);



        
        break;

        case 3:
        //
        break;

        case 4:

        //Lista as contas cadastradas

        Contabancaria * lista = contacadastrada();

        break;

        case 5:
        // Buscar conta

         do
            {
                printf("Informe qual a conta que deseja buscar: \n");
                if (scanf(" %d", &numero) == 1)
                {
                    
                }
                else
                {
                    printf("Conta inválida. Digite novamente:\n");
                    // Limpar o buffer de entrada para evitar loop infinito
                    while (getchar() != '\n')
                        ;
                }
            } while (!numero);

            //Após verificar se o que foi digitado é valido é feito a busca
            Contabancaria *con = buscarconta(con, numero);
            if (con != NULL)
            {
                printf("\n Cliente encontrado! \n");
                printf("Cliente: %s\n", con->cliente);
                printf("Numero: %d\n", con->numero);
                printf("Data de abertura: %s\n", con->data);
                printf("Saldo: %.2f", con->saldo);
                printf("Status: %s", con->status);
                
            }
            else
            {
                printf("Cliente nao encontrado! \n");
            }

        break;

        case 6:
        //
        break;

        case 7:
        break;*/

        case 8:

        printf("Sair!! ");

        break;

    default: 
    printf ("Tente novamente, opcao fornecida está invalida! \n");


    }
}while(op !=8);





    return 0;
}