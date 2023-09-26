#include "contaBancaria.h"
#include "agencia.h"

struct contabancaria{

   Agencia *agencia;
   char cliente[51];
   char dataAbertura[12];
   float saldo;
   char status[11];
   int numero;

};

Contabancaria *criar_conta(char *cliente, char* dataAbertura, float saldo, char *status, int numero)
{
   Contabancaria *contabancaria = (Contabancaria *)malloc(sizeof(Contabancaria));
   if (contabancaria == NULL){

      printf("Variavel criar_conta nao foi alocada dinamicamente! \n");
      exit(1);
   }

strcpy(contabancaria->cliente, cliente);   
strcpy(contabancaria->dataAbertura, dataAbertura);
contabancaria->saldo = saldo;
strcpy(contabancaria->status, status);  
contabancaria->numero = numero;
contabancaria->agencia = NULL;
return contabancaria;
}


/*


// função libera contas vai liberar a memoria ocupada
void libera_conta(Contabancaria *contabancaria)
{
    
 free(contabancaria);
}
*/