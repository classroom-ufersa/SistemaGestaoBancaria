/*Bibliotecas utilizadas*/


typedef struct agenciabancaria Agenciabancaria;


//Função para cadastra uma nova agencia bancaria, alocando memoria

Agenciabancaria *criar_agencia(char *nome, int codigo, char* localizacao, char* horario);
/*
//Função para salva arquivos

void agencia_salva(Agenciabancaria *agenciabancaria);


// função libera agencias vai liberar a memoria ocupada
void libera_agencia(Agenciabancaria ** age ,FILE * fp);

*/