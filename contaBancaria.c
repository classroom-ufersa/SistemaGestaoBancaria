#include "contaBancaria.h"
#include "agencia.h"

struct contabancaria{

   char cliente[51];
   char data[12];
   float saldo;
   Agenciabancaria *agencia;
   char status[11];
   int numero;

};
struct lista{

Contabancaria *conta;
Lista *prox;

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

Lista *lista_remove(Lista *k, int numero){
   Lista *ant = NULL;
   Lista *p = k;
   while (p != NULL && p->conta->numero != numero){
      ant = p;
      p = p->prox;

   }if(p ==NULL){
      return k;
   }if(ant == NULL){
      k = k->prox;
   }else{
      ant->prox = p->prox;
   }
   free(p->conta);
   free(p);
   return k;
}

Contabancaria *buscar_conta(Lista *contas, int numero){
   while(contas != NULL){
      if(contas->conta->numero == numero){
         return contas->conta;
      }
      contas = contas->prox;
   }
   return NULL;
}

void listar_contas_ativas (Lista *contas, int ativas){
   while (contas != NULL){
      Contabancaria *conta = contas->conta;
      if((ativas && strcmp(conta->status, "ativa") == 0) || (!ativas && strcmp(conta->status, "ativa") !=0)){
         printf("Cliente: %s \n", conta->cliente);
         printf("Numero da conta: %d \n", conta->numero);
         printf("Saldo: %.2f\n", conta->saldo);
         printf("Status: %s\n", conta->status);
         printf("\n");
      }
      contas = contas->prox;
   }
}

void limpa_buffer(void){
   int valorlido;
   do{
      valorlido = getchar();
   }while((valorlido != '\n') && (valorlido != EOF));
}

void liberar_lista_contas(Lista *lista){
   while(lista !=NULL){
      Lista *temp = lista;
      lista = lista->prox;
      free(temp->conta);
      free(temp);
   }
}

char le_opcao (int menorvalor, int maiorvalor){
   int op;
   char entrada[51];
   while(1){
      printf("Digite sua opcao: ");
      scanf(" %[^\n]", entrada);
      op = entrada[0];
      if (op >=menorvalor && op <= maiorvalor && strlen(entrada) ==1)
      {
         limpa_buffer();
         break;

      }
      else{
         printf("Opcao invalida. \n tente dentre essas opcoes %c e %c", menorvalor, maiorvalor);;
         limpa_buffer();
      }
   }
   return op;
}

void editar_conta(Contabancaria *conta){
   if (conta == NULL){
      printf("Conta nao localizada na agencia \n");
      return;
   }
   char opcao;
   printf("Conta localizada. Informe a opcao que deseja fazer alteracao\n");
   printf("1 - Nome do cliente: \n");
   printf("2 - Saldo: \n");
   printf("3 - Status: \n");
   printf("4 - Sair \n ");
   printf("Informe sua opcao de escolha: \n");
   opcao = le_opcao('1', '4');
   switch (opcao)
   {
   case '1':
      printf("Informe o novo nome: \n");
      scanf(" %[^\n]", conta->cliente);;
      break;
   case '2':
   printf("Informe o novo saldo do cliente: \n");
   scanf(" %f", &conta->saldo);
   break;
   case '3':
      printf("Informe o novo status da conta (ativo, desativado, bloqueado): \n");
      scanf(" %[\n]", conta->status);
      break;
   case '4':
   printf("Cancelar: \n");
   break;
   default:
   printf("Opcao invalida \n");
      break;
   }
}