/*Bibliotecas utilizadas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct contabancaria Contabancaria;

typedef struct lista Lista;

// funcao para remove da lista
Lista *lista_remove(Lista *k, int numero);

// funcao para criar conta bancaria
Contabancaria *criar_conta(char *cliente, char *data, float saldo, char *status, int numero);

//funcao para liberar conta bancaria
void libera_conta(Contabancaria *contabancaria);

//funcao para bsucar conta bancaria
Contabancaria *buscar_conta(Lista *contas, int numero);

// funcao para editar conta bancaria
void editar_conta(Contabancaria *conta);


// funcao para limpar buffer
void limpa_buffer(void);


// funcao para ler opcao 
char le_opcao(int menorValor, int maiorValor);

// funcao para listar contas ativas
void listar_contas_ativas(Lista *contas, int ativas);

// Função para verificar se a entrada contém apenas dígitos (números)
bool entradaContemApenasDigitos(const char *entrada);

//Funcao para liberar contas
void liberar_lista_contas(Lista *lista);