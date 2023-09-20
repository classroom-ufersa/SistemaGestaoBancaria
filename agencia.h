/*Bibliotecas utilizadas*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct agenciabancaria Agenciabancaria;


/*Função para cadastra uma nova agencia bancaria, alocando memoria*/

Agenciabancaria *criar_agencia(char *nome, int codigo, char* localizacao, int contas, int horario)

/*Função para salva arquivos*/

void agencia_salva(Agenciabancaria *agenciabancaria)



// função libera agencias vai liberar a memoria ocupada
void libera_agencia(Agenciabancaria *agenciabancaria)
{
    
    free(agenciabancaria);
}