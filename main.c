#include "contaBancaria.c"
#include "agencia.c"

int main()
{

    // Agencia *listaAgencias = NULL; // Inicializa a lista de agências como vazia
    ContaBancaria *conta1 = criarContaBancaria("Brejo Santo", "Diego", "29/09/2023", 300, "Ativa", 2007);
    adicionarContaEmOrdem(conta1);
    ContaBancaria *conta2 = criarContaBancaria("Acopiara", "Diego Nascimento", "29/09/2023", 300, "Ativa", 2006);
    adicionarContaEmOrdem(conta2);
    ContaBancaria *conta3 = criarContaBancaria("Crato", "Diego Nascimento de Oliveira", "29/09/2023", 300, "Ativa", 2008);
    adicionarContaEmOrdem(conta3);
    listarContasCadastradas();

    return 0;
}
