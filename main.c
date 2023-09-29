#include "contaBancaria.c"
#include "agencia.c"


int main()
{

    Agencia *listaAgencias = NULL; // Inicializa a lista de agências como vazia

      Agencia *agencia = criarAgencia("brejo santo", 456, "Avenida Brasil", 200, 20, "10:00-17:00");
    
    // Chame a função para adicionar a agência em ordem
    adicionarAgenciaEmOrdem(&listaAgencias, agencia);
   

    return 0;
}


 