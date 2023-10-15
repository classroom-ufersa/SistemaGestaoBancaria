 # Sistema de gestão bancária
## Introdução 
Um Sistema de Gestão Bancária é uma ferramenta fundamental que permite o cadastro, fornece e lista os clientes em uma agência bancária. No projeto desenvolvido foi utilizado os conceitos vistos e crompreendidos em sala de aula. Podem ser citados como exemplo: ponteiros, alocação dinâmica, tipos estruturados, manipulação de arquivos, Tipos Abstratos de Dados (TADs), estruturas de dados e  entre outros temas abordados na disciplina Algoritmos e Estruturas de Dados I.

## Desenvolvedores
- [Diego Nascimento de Oliveira](https://github.com/diegonascimento2023)
- [Paulo Henrique Medeiros da Silva](https://github.com/Oluaphenrique)
  
## Problematica
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
