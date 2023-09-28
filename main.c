#include "agencia.c"

int main(void){
/*
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
   
*/

   
    
    Agenciabancaria ** agencias = (Agenciabancaria**)malloc(sizeof(Agenciabancaria*));
    int qntagencias = 0;
    int op;
    char nome[51], localizacao[51], horario[15];
    int numero;
    int i;
    qntcontas = 0;
    int j;

do {

    printf("\n MENU DE OPCOES \n");
    printf(" 1 - Criar agencia bancaria \n");
    printf(" 2 - Cadastrar conta \n");
    printf(" 3 - Remover conta \n");
    printf(" 4 - Listar contas cadastradas \n");
    printf(" 5 - Buscar conta \n");
    printf(" 6 - Editar conta \n");
    printf(" 7 - Consultar contas ativas em uma dada agencia \n");
    printf(" 8 - Sair \n");

    if (scanf(" %d", &op) != 1) // verifica se o que foi digitado é um inteiro
    {
        printf(" Invalido. Tente novamente");
        
    }


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
        agencias[qntagencias] = criar_agencia(nome, numero, localizacao, horario);
        qntagencias++;
        agencias = realloc(agencias, (qntagencias+1)*sizeof(Agenciabancaria));
        break;

        case 2:
        // Cadastrar cliente

        printf("Informe qual agencia deseja cadastrar o cliente");
        scanf (" %d", &numero);

        for(i=0; i<=qntagencias; i++){
            if(agencias[i]->codigo == numero){
                break;
            }
        }
        if( i> qntagencias){
            printf("Agencia nao existe");
        }else{
            agencias[i] = cadastrar_conta(agencias[i]);
        }
      
        
        break;
        
        case 3:
        // Listar contas cadastradas

        printf ("Informe o codigo da agencia a qual deseja listar \n");
        scanf(" %d", &numero);

        for (i = 0; i < qntagencias; i++){
            if (agencias[i]->codigo == numero){
                printf("Contas cadastradas na agencia %s:", agencias[i]->nome);

                for(j = 0; j < agencias[i]->qntcontas; j++) {
                    
                    printf("",agencias[i]->contas[j]->nome);
                                
                }
                break;
            }
        }
        if ( i == qntagencias){
            printf("Agencia nao localizada");
        }
        
        break;
/*
        case 4:

        //Remove conta cadastra
        
        for (i = 0; i < qntdagencias, i++){
            if (agencias[i]->codigo == numero){
                if (remove_conta_cadastrada(agencias[i], ))
            }
        }


        break;

        case 5:
        // Buscar conta

        
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