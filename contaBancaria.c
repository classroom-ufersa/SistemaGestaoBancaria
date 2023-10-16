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
      if ((ativas && comparaContas(conta->status, "ativa") == 0) || (!ativas && comparaContas(conta->status, "ativa") != 0))
      {
         printf("Cliente: %s \n", conta->cliente);
         printf("Número da conta: %d \n", conta->numero);
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
      printf("Conta não localizada na agência.\n");
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
      while (1)
      {
         printf("Informe o saldo da conta: ");
         char input[20];
         if (fgets(input, sizeof(input), stdin))
         {
            int valido = 1;
            char *endptr;

            // Converte a entrada para um número de ponto flutuante
            conta->saldo = strtof(input, &endptr);

            if (endptr == input)
            {
               valido = 0;
            }
            else
            {
               // Verifica se há caracteres não numéricos após o número
               for (int i = 0; input[i] != '\0'; i++)
               {
                  if (!isdigit(input[i]) && input[i] != '.' && input[i] != '\n')
                  {
                     valido = 0;
                     break;
                  }
               }
            }

            if (valido)
            {
               saldoValido = 1;
               break; // Sai do loop se o saldo for válido
            }
            else
            {
               printf("Entrada inválida. Digite novamente (somente números):\n");
            }
         }
      }
      break;

   case '3':
      do
      {
         printf("Informe o novo status da conta (Ativa, Desativada, Bloqueada): \n");
         scanf(" %[^\n]", conta->status);
         getchar(); // Limpar o buffer

         statusValido = (comparaContas(conta->status, "ativa") == 0 ||
                         comparaContas(conta->status, "desativada") == 0 ||
                         comparaContas(conta->status, "bloqueada") == 0);

         if (!statusValido)
         {
            printf("O status digitado é inválido. Digite Ativa, Desativada ou Bloqueada.\n");
         }
      } while (!statusValido);
      break;

   case '4':
      printf("Cancelado! \n");
      break;
   default:
      printf("Opcao inválida!\n");
      break;
   }
}

// Função para verificar se a entrada contém apenas dígitos (números)
bool entradaContemApenasDigitos(const char *entrada)
{
   for (int i = 0; entrada[i] != '\0'; i++)
   {
      if (!isdigit(entrada[i]))
      {
         return false;
      }
   }
   return true;
}
