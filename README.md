# Sistema de gestão bancária
 
## Sumário
1. [Introdução](https://github.com/classroom-ufersa/Sistema_de_Gestao_Bancaria#introdu%C3%A7%C3%A3o)
2. [Desenvolvedores](https://github.com/classroom-ufersa/Sistema_de_Gestao_Bancaria#desenvolvedores)
3. [Problematica](https://github.com/classroom-ufersa/Sistema_de_Gestao_Bancaria#problematica)
4. [Descrição](https://github.com/classroom-ufersa/Sistema_de_Gestao_Bancaria#descri%C3%A7%C3%A3o)
5. [Funções utilizadas no programa](https://github.com/classroom-ufersa/Sistema_de_Gestao_Bancaria#fun%C3%A7%C3%B5es-utilizadas-no-programa)
- 5.1 [Funções contidas em agencia.h](https://github.com/classroom-ufersa/Sistema_de_Gestao_Bancaria#fun%C3%A7%C3%B5es-contidas-em-agenciah)
- 5.2 [Funções contidas em contaBancaria.h](https://github.com/classroom-ufersa/Sistema_de_Gestao_Bancaria#fun%C3%A7%C3%B5es-contidas-em-contabancariah)
6. [Explicação de uma das funções utilizadas no programa](https://github.com/classroom-ufersa/Sistema_de_Gestao_Bancaria#explica%C3%A7%C3%A3o-de-uma-das-fun%C3%A7%C3%B5es-utilizadas-no-programa)
  
   
## Introdução 
Um Sistema de Gestão Bancária é uma ferramenta fundamental que permite o cadastro, fornece e lista os clientes em uma agência bancária. No projeto desenvolvido foi utilizado os conceitos vistos e crompreendidos em sala de aula. Podem ser citados como exemplo: ponteiros, alocação dinâmica, tipos estruturados, manipulação de arquivos, Tipos Abstratos de Dados (TADs), estruturas de dados e  entre outros temas abordados na disciplina Algoritmos e Estruturas de Dados I.

## Desenvolvedores
- [Diego Nascimento de Oliveira](https://github.com/diegonascimento2023)
- [Paulo Henrique Medeiros da Silva](https://github.com/Oluaphenrique)
  
## Problemática
A problemática deste projeto consiste em desenvolver um sistema de gestão bancária em linguagem C para uma rede de agências bancárias. O objetivo principal é permitir a manipulação de contas bancárias e agências, com a capacidade de realizar operações como adicionar, remover, listar, buscar, editar contas, consultar contas ativas em uma agência e saber quantas agências existem.

## Descrição
O sistema de gestão bancária conta com cinco "TAD's" e um arquivo ".txt". O projeto possui dois arquivos cabeçalho (agencia.h e contaBancaria.h), dois arquivos de implementação (agencia.c e contaBancaria.c), um arquivo principal (main.c) e um arquivo de texto (dados.txt).

## Funções utilizadas no programa
- ### Funções contidas em agencia.h
```c

// Função para criar agência bancaria
Agenciabancaria *criar_agencia(char *nome, int codigo, char *localizacao, char *horario);

// Função para listar em ordem
Lista *lista_insere_ordena(Lista *k, Contabancaria *conta);

// Função para cadastrar cliente
Agenciabancaria *cadastrar_cliente(Contabancaria *contabancaria, Agenciabancaria *agenciabancaria);

// Função cadastrar conta em uma determinada agência 
Agenciabancaria *cadastrar_conta(Agenciabancaria *agencia);

// Função para listar agências
void listar_agencias(Agenciabancaria **agencias, int qtdagencias);

// Função para salvar dados no arquivo arquivo
void salvar_arquivo(Agenciabancaria **agencias, int qtdagencias);

// Função para ler dados no arquivo arquivo
Agenciabancaria **ler_arquivo(Agenciabancaria **agencias, int *qnta);

// Função para remover conta
Agenciabancaria *remove_conta(Agenciabancaria *agencia, int numero);

// Função para liberar memoria 
void liberar_agencia(Agenciabancaria *agencia);

// Função para liberar memoria
void liberar_agencias(Agenciabancaria **agencias, int qnta);

```

- ###  Funções contidas em contaBancaria.h
```c
// Função para remover conta da lista
Lista *lista_remove(Lista *k, int numero);

// Função para criar  uma conta bancaria
Contabancaria *criar_conta(char *cliente, char *data, float saldo, char *status, int numero);

//Função para liberar conta bancaria
void libera_conta(Contabancaria *contabancaria);

//Função para buscar conta bancaria
Contabancaria *buscar_conta(Lista *contas, int numero);

// Função para editar conta bancaria
void editar_conta(Contabancaria *conta);

// Função para limpar buffer
void limpa_buffer(void);

// Função para ler opção 
char le_opcao(int menorValor, int maiorValor);

// Função para listar contas ativas
void listar_contas_ativas(Lista *contas, int ativas);

// Função para verificar se a entrada contém apenas dígitos (números)
bool entradaContemApenasDigitos(const char *entrada);

// Função para liberar contas
void liberar_lista_contas(Lista *lista);
```
## Explicação de uma das funções utilizadas no programa
```c
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
```
  A função acima foi retirada da TAD contaBancaria.c ela tem como objetivo procurar e retornar uma conta bancária com base em seu número em uma lista encadeada de contas, como visto na terceira unidade da disciplina. Abaixo está a explicação da função linha por linha:
  - __Contabancaria *buscar_conta(Lista *contas, int numero):__ Esta é a declaração da função buscar_conta. Ela aceita dois argumentos: ```contas```, que é um ponteiro para o início de uma lista encadeada de contas bancárias, e ```numero```, que é o número da conta que está sendo procurado.
  - __while (contas != NULL):__ Inicia um loop while que continuará enquanto o ponteiro ```contas``` não for nulo. Isso significa que o loop irá percorrer a lista encadeada até que todas as contas tenham sido verificadas.

  - __if (contas->conta->numero == numero):__ Dentro do loop, a função verifica se o número da conta da estrutura de dados apontada por ```contas``` é igual ao número passado como argumento para a função. Isso compara o número da conta atual com o número que estamos procurando.

  - __return contas->conta;:__ Se a condição no if for ```verdadeira```, ou seja, se a conta com o número desejado for encontrada, a função retorna um ponteiro para essa conta. Isso significa que a função retorna a conta encontrada.

  - __contas = contas->prox;:__ Se a conta atual não corresponder ao número desejado, a função avança para a próxima conta na lista encadeada, movendo o ponteiro contas para a ```próxima``` estrutura de dados na lista.

  - __return NULL;:__ Se o loop for concluído e nenhuma conta corresponder ao número desejado, a função ```retorna NULL```. Isso indica que a conta não foi encontrada na lista.
    
Em resumo, a função __buscar_conta__ percorre uma lista encadeada de contas bancárias, verificando se o número da conta coincide com o número fornecido como argumento. Se uma correspondência for encontrada, a função retorna um ponteiro para a conta correspondente. Caso contrário, se o número não for encontrado em nenhuma das contas da lista, a função retorna ```NULL``` para indicar que a conta não existe na lista.
