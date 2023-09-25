/*Bibliotecas utilizadas*/


typedef struct agenciabancaria Agenciabancaria;

typedef struct lista Lista;


/*Função para cadastra uma nova agencia bancaria, alocando memoria*/

//Função para cadastra uma nova agencia bancaria, alocando memoria
Agenciabancaria *criar_agencia(char *nome, int codigo, char* localizacao, char* horario);

// funçao para ordenar contas
Lista * lista_insere_ordena(Lista *k, Contabancaria *conta);
// funcao para cadastrar cliente em agencia 

Agenciabancaria *cadastrar_cliente (Contabancaria *contabancaria, Agenciabancaria *agenciabancaria);
/*
//Função para salva arquivos

void agencia_salva(Agenciabancaria *agenciabancaria);


// função libera agencias vai liberar a memoria ocupada
void libera_agencia(Agenciabancaria ** age ,FILE * fp);

*/