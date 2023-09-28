#include "contaBancaria.c"
#include "agencia.c"

int main()
{
    

   Agencia *agencia = criarAgencia("Agencia1", 123, "Rua Principal", 100, 10, "10:00-18:00");

    ContaBancaria *conta1 = criarContaBancaria(agencia, "Pedro", "15/01/2022", 5000, "Ativa", 1001);

    // Listar todas as contas cadastradas
    printf("Lista de todas as contas cadastradas:\n");
    listarContasCadastradas();

    // Remover uma conta específica
    int numeroContaARemover = 2002;
    removerContaPorNumero(numeroContaARemover);

    // Listar novamente após a remoção
    printf("\nLista de contas após a remoção da conta %d:\n", numeroContaARemover);
    listarContasCadastradas();

    // Lembre-se de liberar a memória alocada para a Agência e Conta Bancária (isso pode ser feito em suas funções principais)
    free(agencia);
    free(conta1);

    return 0;
}

 