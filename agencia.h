/*Bibliotecas utilizadas*/


typedef struct agenciabancaria Agenciabancaria;

typedef struct lista Lista;

//Função para cadastra uma nova agencia bancaria, alocando memoria
Agenciabancaria *criar_agencia(char *nome, int codigo, char* localizacao, char* horario);

// funçao para ordenar contas
Lista * lista_insere_ordena(Lista *k, Contabancaria *conta);

// funcao para cadastrar cliente em agencia 
Agenciabancaria *cadastrar_cliente (Contabancaria *contabancaria, Agenciabancaria *agenciabancaria);

// funcao para cadastrar conta bancaria
Agenciabancaria *cadastrar_conta(Agenciabancaria* agencia);

// funcao para listar agencias cadastradas
void listar_agencias(Agenciabancaria **agencias, int qntagencias);


// funcao para remove conta cadastrada
Agenciabancaria *remover_conta(Agenciabancaria *agencia, int numero);

//Função para salva arquivos
void agencia_salva(Agenciabancaria *agenciabancaria);


// funcao para liberar memoria
void liberar_agencias(Agenciabancaria *agencia);

// funcao para liberar a memoria 
void liberar_agencias (Agenciabancaria **agencias, int qnt);

//Função para salvar arquivos
void salva_arquivo(Agenciabancaria **agencias, int qntdagencias);

// Função para ler arquivos salvo
Agenciabancaria **ler_arquivo(Agenciabancaria **agencias, int qtnd);
