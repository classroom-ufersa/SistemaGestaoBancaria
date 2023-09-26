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


// função libera contas vai liberar a memoria ocupada
void libera_conta(Contabancaria *contabancaria)
{
    
 free(contabancaria);
}
*/