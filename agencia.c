#include "contaBancaria.c"

struct agenciabancaria{

char nome[51];
int codigo;
char localizacao [31];
Lista *contas;
char horario[15];

};


struct lista{

Contabancaria *conta;
Lista *prox;

};

Agenciabancaria *criar_agencia(char *nome, int codigo, char* localizacao, char* horario) {

    
    Agenciabancaria *criar_agencia = (Agenciabancaria*)malloc(sizeof(Agenciabancaria));
    if(criar_agencia == NULL) {

        printf("Variavel criar_agencia nao foi alocada dinamicamente! \n");
        exit(1);
    }
    strcpy(criar_agencia->nome, nome);   
    criar_agencia->codigo = codigo;
    strcpy(criar_agencia->localizacao, localizacao);  
    strcpy(criar_agencia->horario, horario);
    criar_agencia->contas = NULL;

    return criar_agencia;
}

Lista * lista_insere_ordena(Lista *k, Contabancaria *conta){
    Lista *novo;
    Lista *ant = NULL;
    Lista *p = k;
    while (p != NULL && strcmp(p->conta->cliente, conta->cliente )< 0)
    {
        ant = p;
        p = p->prox;
        
    }
    novo = (Lista *)malloc(sizeof(Lista));
    novo->conta = conta;
    if (ant == NULL)
    {
        novo ->prox = k;
        k = novo;


    }else
    {
        novo->prox = ant-> prox;
        ant->prox = novo;

    }
    return k;
}

Agenciabancaria *cadastrar_cliente (Contabancaria *contabancaria, Agenciabancaria *agenciabancaria){
    
    agenciabancaria->contas = lista_insere_ordena(agenciabancaria->contas,contabancaria);

    return agenciabancaria;
    
    }

    Agenciabancaria *cadastrar_conta(Agenciabancaria* agencia){
        
        char cliente[51], data[12], status[11];
        int numero;
        float saldo;
        printf("Informe o nome do cliente \n");
        scanf(" %[^\n]", cliente);
        printf("Informe data de abertura \n");
        scanf(" %[^\n]", data);
        printf("Informe o status da conta (ativa, desativada, bloqueada) \n");
        scanf(" %[^\n]", status);
        printf("Informe o numero da conta que esta sendo cadastrado \n");
        scanf(" %d", &numero);
        printf(" Qual o saldo do cliente \n");
        scanf (" %f", saldo);

        Contabancaria* aux = criar_conta(cliente, data, saldo, status, numero);

        agencia = cadastrar_cliente(aux, agencia);
        return agencia;
    }

        void listar_agencias(Agenciabancaria **agencias, int qntagencias){
        printf("Listar agencias e contas ");
        for(int i; i<qntagencias, i++);
        Agenciabancaria * agencia = agencia[i];
        printf(" %s(nome), %d(codigo), %s(localizacao), %s(horario)", agencia[i]->nome, agencia[i]->codigo, agencia[i]->localizacao, agencia[i]->horario);
        Lista *contas = agencia->contas;
        if (contas == NULL){
            printf("Nao ha contas cadastrada nessa agencia");
        }else{
            printf (" Contas cadastrada nessa agencia");
            while(contas != NULL){
                Contabancaria *conta = contas->conta;
                printf("cliente: %s, numero: %d , saldo %.2f, status %s", agencia[i]->cliente, agencia[i]->numero, agencia[i]->saldo, agencia[i]->status);
                contas = contas->prox;
            }
        }
        }


    void remove_conta(Agenciabancaria **agencia, int qntcontas){
        pritf("Listar ");
        for(int i; i<qntcontas, i++){
            Agenciabancaria *agencia = agencia[i];
            printf("clientes: %s, numero: %d, saldo: %.2f, status %s", agencia[i]->cliente, agencia[i]->numero, agencia[i]->saldo, agencia[i]->status);
            Lista *contas = agencias->contas;
            if (contas == NULL){
                printf("");
            }else{
                printf("");
                while( contas != NULL ) {
                Contabancaria *conta = contas->conta;
                printf("Cliente: %s, numero: %d, saldo: %.2f, status %s", agencia[i]->cliente, agencia[i]->numero, agencia[i]->saldo, aggencia[i]->status);
                conta = contas->prox;
                }
            }
        }
    }
/* funcao para o caso 5
    void localizar_conta(Agenciabancaria **agencias, int qntagencias, int numero){
        int i, j, conta_localizada = 0;

        for (i = 0; i < qntagencias; i++){
            for(j = 0; j < agencias[i]->qntcontas; j++){
                if (agencias[i]->contas[j]->numero == numero){
                    printf("Conta localizada na agencia: %s", agencias[i]->nome);
                    printf("Numero da conta: %d", agencias[i]->contas[j]->numero);
                    printf("Cliente: %s\n", agencias[i]->contas[j]-:cliente);
                    printf("Saldo: %.2f", agencias[i]->contas[j]->saldo);
                    conta_localizada = 1;
                    

                }
            }
            if(conta_localizada){
                //
            }
        }if(!conta_localizada){
            printf("Conta nao localizada");
            
        }
    }

*/
/*
        
void agencia_salva(Agenciabancaria *agenciabancaria)
{

    
    FILE *fp = fopen("agenciaban.txt", "a"); // Abre arquivo "a" (abre um arquivo no modo de inclusão)
    if (fp == NULL)                    
    {
        printf("Erro ao abrir o arquivo"); 
        exit(1);                           
    }
        
    char *nome = agenciabancaria->nome;
    int codigo = agenciabancaria->codigo;
    char *localizacao = agenciabancaria->localizacao;
    int contas = agenciabancaria->contas;
    int horario = agenciabancaria->horario;
    agenciabancaria->documento = documento
    nome[strcspn(nome, "\n")] = '\0';
    localizacao[strcspn(localizacao, "\n")] = '\0';

    
    fprintf(fp, " %s\t%d\t%s\t%s\n", nome, codigo, localizacao, horario, agenciabancaria->documento);
    fclose(fp); 
}
*/
// função libera agencias vai liberar a memoria ocupada
void libera_agencia(Agenciabancaria *agenciabancaria)
{
    
    free(agenciabancaria);
}

