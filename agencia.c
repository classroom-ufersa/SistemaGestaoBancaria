#include "contaBancaria.h"
#include "agencia.h"

struct agenciabancaria{

char nome[51];
int codigo;
char localizacao [31];
Contas *contas;
char horario[15];

};

Agenciabancaria *criar_agencia(char *nome, int codigo, char* localizacao, int contas, int horario) {
    
      Agenciabancaria *criar_agencia = (Agenciabancaria*)malloc(sizeof(Agenciabancaria));
    if(criar_agencia == NULL) {

        printf("Variavel criar_agencia nao foi alocada dinamicamente! \n");
        exit(1);
    }
    strcpy(agenciabancaria->nome, nome);   
    agenciabancaria->codigo = codigo;
    strcpy(agenciabancaria->localizacao, localizacao);  
    agenciabancaria->contas = contas;
    agenciabancaria->horario = horario;

    return agenciabancaria;
}


void agencia_salva(Agenciabancaria *agenciabancaria)
{

    
    FILE *fp = fopen("saida.txt", "a"); // Abre arquivo "a" (abre um arquivo no modo de inclusão)
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

    
    fprintf(fp, " %s\t%d\t%s\t%d\t%d\n", nome, codigo, localizacao, contas, horario agenciabancaria->documento);
    fclose(fp); 
}

// função libera agencias vai liberar a memoria ocupada
void libera_agencia(Agenciabancaria *agenciabancaria)
{
    
    free(agenciabancaria);
}