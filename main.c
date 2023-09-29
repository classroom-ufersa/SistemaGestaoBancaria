#include "contaBancaria.c"
#include "agencia.c"


int main()
{

    // Agencia *listaAgencias = NULL; // Inicializa a lista de agências como vazia
      ContaBancaria * conta = criarContaBancaria( "Brejo Santo", "Diego", "29/09/2023", 300, "Ativa", 2008);
      adicionarContaEmOrdem(conta);

      
   

    return 0;
}


 