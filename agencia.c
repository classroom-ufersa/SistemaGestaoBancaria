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

