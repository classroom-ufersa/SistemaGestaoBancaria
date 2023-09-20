#include "contaBancaria.h"

typedef struct contabancaria{

   char cliente[51];
   int data;
   float saldo;
   char status[11];
   int numero;

}Contabancaria;

Contabancaria *criar_conta(char *cliente, int data, float saldo, char *status, int numero)
{
   Contabancaria *contabancaria = (Contabancaria *)malloc(sizeof(Contabancaria));
   if (contabancaria == NULL){

      printf("Variavel criar_conta nao foi alocada dinamicamente! \n");
      exit(1);
   }

strcpy(contabancaria->cliente, cliente);   
contabancaria->data = data;
contabancaria->saldo = saldo;
strcpy(contabancaria->status, status);  
contabancaria->numero = numero;

return contabancaria;
}

void conta_salva(Contabancaria *contabancaria)
{

    
    FILE *fp = fopen("saida.txt", "a"); // Abre arquivo "a" (abre um arquivo no modo de inclusão)
    if (fp == NULL)                    
    {
        printf("Erro ao abrir o arquivo"); 
        exit(1);                           
    }
        
    char *cliente = contabancaria->nome;
    int data = contabancaria->data;
    float saldo = contabancaria->saldo;
    char *status = contabancaria->status;
    int numero = contabancaria->numero;
    contabancaria->doc = doc
    cliente[strcspn(cliente, "\n")] = '\0';
    status[strcspn(status, "\n")] = '\0';

    
    fprintf(fp, " %s\t%d\t%f\t%s\t%d\n", nome, codigo, localizacao, contas, horario contabancaria->doc);
    fclose(fp); 
}


// função libera contas vai liberar a memoria ocupada
void libera_conta(Contabancaria *contabancaria)
{
    
 free(contabancaria);
}
