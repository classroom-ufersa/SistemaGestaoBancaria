#include "contaBancaria.h"
#include "agencia.h"

struct contabancaria
{

   char cliente[51];
   char data[12];
   float saldo;
   Agenciabancaria *agencia;
   char status[11];
   int numero;
};
struct lista
{

   Contabancaria *conta;
   Lista *prox;
};

Contabancaria *criar_conta(char *cliente, char *data, float saldo, char *status, int numero)
{
   Contabancaria *contabancaria = (Contabancaria *)malloc(sizeof(Contabancaria));
   if (contabancaria == NULL)
   {

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

Lista *lista_remove(Lista *k, int numero)
{
   Lista *ant = NULL;
   Lista *p = k;
   while (p != NULL && p->conta->numero != numero)
   {
      ant = p;
      p = p->prox;
   }
   if (p == NULL)
   {
      return k;
   }
   if (ant == NULL)
   {
      k = k->prox;
   }
   else
   {
      ant->prox = p->prox;
   }
   free(p->conta);
   free(p);
   return k;
}

Contabancaria *buscar_conta(Lista *contas, int numero)
{
   while (contas != NULL)
   {
      if (contas->conta->numero == numero)
      {
         return contas->conta;
      }
      contas = contas->prox;
   }
   return NULL;
}

void listar_contas_ativas(Lista *contas, int ativas)
{
   while (contas != NULL)
   {
      Contabancaria *conta = contas->conta;
      if ((ativas && strcmp(conta->status, "ativa") == 0) || (!ativas && strcmp(conta->status, "ativa") != 0))
      {
         printf("Cliente: %s \n", conta->cliente);
         printf("Numero da conta: %d \n", conta->numero);
         printf("Saldo: %.2f\n", conta->saldo);
         printf("Status: %s\n", conta->status);
         printf("\n");
      }
      contas = contas->prox;
   }
}

void limpa_buffer(void)
{
   int valorlido;
   do
   {
      valorlido = getchar();
   } while ((valorlido != '\n') && (valorlido != EOF));
}

void liberar_lista_contas(Lista *lista)
{
   while (lista != NULL)
   {
      Lista *temp = lista;
      lista = lista->prox;
      free(temp->conta);
      free(temp);
   }
}

char le_opcao(int menorvalor, int maiorvalor)
{
   int op;
   char entrada[51];
   while (1)
   {
      printf("Opção: ");
      scanf(" %[^\n]", entrada);
      op = entrada[0];
      if (op >= menorvalor && op <= maiorvalor && strlen(entrada) == 1)
      {
         limpa_buffer();
         break;
      }
      else
      {
         printf("Opção inválida!\nDigite uma opção entre %c e %c.\n", menorvalor, maiorvalor);
         ;
         limpa_buffer();
      }
   }
   return op;
}

void editar_conta(Contabancaria *conta)
{
   if (conta == NULL)
   {
      printf("Conta não localizada na agencia.\n");
      return;
   }
   int nomeValido = 0;   // Variável para verificar se o nome do cliente fornecido é válido
   int saldoValido = 0;  // Variável para verificar se o saldo fornecido é válido
   int statusValido = 0; // Variável para verificar se o status fornecido é válido
   char opcao;
   printf("\nESCOLHA UMA OPÇÃO:\n");
   printf("1 - NOME DO CLIENTE\n");
   printf("2 - SALDO\n");
   printf("3 - STATUS\n");
   printf("4 - SAIR\n ");
   opcao = le_opcao('1', '4');
   switch (opcao)
   {
   case '1':

      do
      {
         printf("Informe o novo nome: \n");
         scanf(" %[^\n]", conta->cliente);
         getchar(); // Limpa o buffer

         nomeValido = 1;
         for (int i = 0; conta->cliente[i] != '\0'; i++)
         {
            if (!isalpha(conta->cliente[i]) && !isspace(conta->cliente[i]))
            {
               nomeValido = 0;
               break;
            }
         }

         if (!nomeValido)
         {
            printf("O nome digitado contém caracteres inválidos.\n");
         }
      } while (!nomeValido);
      break;

   case '2':
      do
      {
         printf("Informe o novo saldo do cliente: \n");
         if (scanf(" %f", &conta->saldo) == 1)
         {
            saldoValido = 1;
         }
         else
         {
            printf("Entrada inválida. Digite novamente:\n");
            // Limpar o buffer de entrada para evitar loop infinito
            while (getchar() != '\n')
               ;
         }
      } while (!saldoValido);
      break;
   case '3':
      scanf(" %[^\n]", conta->status);
      do
      {
         printf("Informe o novo status da conta (Ativa, Desativada, Bloqueada): \n");
         scanf(" %[^\n]", conta->status);
         getchar(); // Limpar o buffer

         statusValido = 1;
         for (int i = 0; conta->status[i] != '\0'; i++)
         {
            if (!isalpha(conta->status[i]) && !isspace(conta->status[i]))
            {
               statusValido = 0;
               break;
            }
         }

         if (!statusValido)
         {
            printf("O status digitado contém caracteres inválidos.\n");
         }
      } while (!statusValido);
      break;
   case '4':
      printf("Cancelar: \n");
      break;
   default:
      printf("Opcao inválida!\n");
      break;
   }
}

// Função para verificar se a entrada contém apenas dígitos (números)
bool entradaContemApenasDigitos(const char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (!isdigit(entrada[i])) {
            return false;
        }
    }
    return true;
}
