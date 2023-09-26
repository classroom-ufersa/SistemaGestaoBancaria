#include "contaBancaria.h"
#include "agencia.h"

struct contabancaria{

   char cliente[51];
   char data[12];
   float saldo;
   Agencia *agencia;
   char status[11];
   int numero;

};

Contabancaria *criar_conta(char *cliente, char* data, float saldo, char *status, int numero)
{
   Contabancaria *contabancaria = (Contabancaria *)malloc(sizeof(Contabancaria));
   if (contabancaria == NULL){

      printf("Variavel criar_conta nao foi alocada dinamicamente! \n");
      exit(1);
   }

strcpy(contabancaria->cliente, cliente);   
strcpy(contabancaria->data, data);
contabancaria->saldo = saldo;
strcpy(contabancaria->status, status);  
contabancaria->numero = numero;
contabancaria->agencia = NULL;
return contabancaria;
}


/*
void conta_salva(Contabancaria *contabancaria)
{

    
    FILE *fp = fopen("contaban.txt", "a"); // Abre arquivo "a" (abre um arquivo no modo de inclusão)
    if (fp == NULL)                    
    {
        printf("Erro ao abrir o arquivo"); 
        exit(1);                           
    }
        
    char *cliente = contabancaria->nome;
    char *data = contabancaria->data;
    float saldo = contabancaria->saldo;
    char *status = contabancaria->status;
    int numero = contabancaria->numero;
    contabancaria->doc = doc
    cliente[strcspn(cliente, "\n")] = '\0';
    status[strcspn(status, "\n")] = '\0';

    
    fprintf(fp, " %s\t%s\t%f\t%s\t%d\n", nome, codigo, localizacao, contas, horario contabancaria->doc);
    fclose(fp); 
}


// função libera contas vai liberar a memoria ocupada
void libera_conta(Contabancaria *contabancaria)
{
    
 free(contabancaria);
}
*/