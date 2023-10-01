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
        for(int i; i<qntagencias; i++)
        {
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
            printf("\n");
        }
        }
        }
    Agenciabancaria *remover_conta(Agenciabancaria *agencia, int numero){
        
        if(agencia->contas == NULL)
        {
            return agencia;
        }
        agencia->contas = lista_remove(agencia->contas, numero);
        return agencia;
    }

    
    void liberar_agencias(Agenciabancaria *agencia){
        if (agencia == NULL)
        return;

        liberar_Lista_contas(agencia->contas);
        free(agencia);
    }

    void liberar_agencias (Agenciabancaria **agencias, int qnt){
        for (int i =0; i<qnt; i++){
            liberar_agencias(agencias[i]);
        }
        free(agencias);
    }

    void salva_arquivo(Agenciabancaria **agencias, int qntdagencias){
        FILE *arquivo = fopen("dados.txt", "w");
        if (arquivo == NULL){
            printf("Erro ao abrir o arquivo para escrira \n");
        }
        for (int i = 0; i < qntdagencias; i++)
        {
            Agenciabancaria *agencia = agencia[i];
            fprintf(arquivo, "Agencia %d\tNome:%s\tCodigo:%d\tLocalizacao:%s\tHorario:%s\n", i+1, agencia ->nome, agencia->codigo, agencia->localizacao, agencia->horario);
            Lista *contas = agencia->contas;
            while(contas != NULL){
                Contabancaria *conta = contas->conta;
                fprintf(arquivo, "Cliente:%s\tData:%s\tSaldo:%.2f\tStatus:%s\tNumero:%d\n", conta->cliente, conta->data, cliente->saldo, cliente->status, cliente->numero);
                contas = contas->prox;
            }
        }
        fclose(arquivo);
    }
/*
    Agenciabancaria **ler_arquivo(Agenciabancaria **agencias, int qtnd){
        FILE *arquivo;
        int i = 0;
        char linhas[];
        char *token;
        Contabancaria aux;

        arquivo = fopen("dados.txt", "r");
        if (arquivo == NULL){
            printf("");
            exit(1);
        }while (fgets(linhas,sizeof(linha),arquivo)!=NULL){
            char *test = strstr(linha, "agencia");
            if (test !=NULL)
            {
                if( i >= *qntd){
                    agencias = realloc(agencias, (*qntd + 1)* sizeof(Agenciabancaria *));
                    if(agencias ==NULL){
                        printf("Erro ao alocar memoria \n");
                        exit(1);
                    }
                    (*qtnd)++;
                }
            }
            token = strtok(linha, ":");
            token = strtok(NULL "\t");
            strcpy(agencias[i]->nome, token);
            token = strtok(NULL, ":");
            token = strtok(NULL, "\t");
            agencias[i]->codigo = atoi(token);
            token = strtok (NULL, ":");
            token = strtok(NULL, "\t");
            strcpy(agencias[i]->localizacao, token);
            token = strtok(NULL, ":");
            token = strtok(NULL, "\n");
            strcpy(agencias[i]->horario, token);
            i++;
        }else{
            
        }
    }

    */