#include "contaBancaria.c"
#include "agencia.c"


int main()
{

    Agencia *listaAgencias = NULL; // Inicializa a lista de agências como vazia

      Agencia *agencia = criarAgencia("Recife", 123, "Rua Principal", 100, 10, "10:00-18:00");
    
    // Chame a função para adicionar a agência em ordem
    adicionarAgenciaEmOrdem(&listaAgencias, agencia);
    /* Agencia *agencia = criarAgencia("Agencia1", 123, "Rua Principal", 100, 10, "10:00-18:00");

    // Crie uma lista de contas vazia
    ContaBancaria *listaContas = NULL;

    // Crie algumas contas e insira-as em ordem alfabética
    inserirContaEmOrdem(&listaContas, criarContaBancaria(agencia, "Pedro", "15/01/2022", 5000, "Ativa", 1001));
    inserirContaEmOrdem(&listaContas, criarContaBancaria(agencia, "Alice", "10/02/2022", 3000, "Ativa", 1002));
    inserirContaEmOrdem(&listaContas, criarContaBancaria(agencia, "Carlos", "05/03/2022", 7000, "Ativa", 1003));
    inserirContaEmOrdem(&listaContas, criarContaBancaria(agencia, "Bruna", "20/02/2022", 4000, "Desativada", 1004));
    inserirContaEmOrdem(&listaContas, criarContaBancaria(agencia, "Diego", "20/02/2022", 600, "Desativada", 1005));
    */

    // Listar todas as contas cadastradas
    printf("Lista de todas as contas cadastradas:\n");
    listarContasCadastradas();
 
    // Remover uma conta específica
    int numeroContaARemover = 1002;
    removerContaPorNumero(numeroContaARemover);

    // Listar novamente após a remoção
    printf("\nLista de contas após a remoção da conta %d:\n", numeroContaARemover);
    listarContasCadastradas();
    
    // Buscar e imprimir uma conta pelo número
    int numeroContaABuscar = 2002;
    printf("\nBuscando e imprimindo conta com o número %d:\n", numeroContaABuscar);
    buscarEImprimirContaPorNumero(numeroContaABuscar);

    // Verificar contas ativas em uma agência específica
    const char *nomeAgenciaParaVerificar = "Fortaleza";
    printf("\nVerificando contas ativas na agência '%s':\n", nomeAgenciaParaVerificar);
    verificarContasAtivasPorAgencia(nomeAgenciaParaVerificar);

    return 0;
}


 