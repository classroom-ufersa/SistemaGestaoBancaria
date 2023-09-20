/*Bibliotecas utilizadas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct contabancaria Contabancaria;

/*Função para cadastra uma nova conta bancaria, alocando memoria*/
Contabancaria *criar_conta(char *cliente, int data, float saldo, char *status, int numero)

/*Função para salva arquivos*/
void conta_salva(Contabancaria *contabancaria)


// função libera conta vai liberar a memoria ocupada
void libera_conta(Contabancaria ** con ,FILE * fp);