#include "contaBancaria.c"
#include "agencia.c"

int main()
{

    ContaBancaria * conta1 = criarContaBancaria("Brejo Santo", "Antonio Silva", "30/09/2023", 300, "ativa", 2009);
    adicionarContaEmOrdem(conta1);
    

    return 0;
}
