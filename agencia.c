#include "agencia.h"


Agencia *criarAgencia(char nome[], int codigo, char localizacao[], int numClientes, int numContas, char horario[]) {
    Agencia *novaAgencia = (Agencia *)malloc(sizeof(Agencia)); 
    if (novaAgencia == NULL) {
        printf("Erro: Falha na alocação de memória para a Agência.\n");
        exit(1);
    }

    strcpy(novaAgencia->nome, nome);
    novaAgencia->codigo = codigo;
    strcpy(novaAgencia->localizacao, localizacao);
    novaAgencia->numClientes = numClientes;
    novaAgencia->numContas = numContas;
    strcpy(novaAgencia->horario, horario);
    novaAgencia->anterior = NULL;
    novaAgencia->proximo = NULL;

    return novaAgencia;
}

void adicionarAgenciaEmOrdem( Agencia *novaAgencia) {
    // Abre o arquivo "agencias.txt" em modo de leitura e escrita
    FILE *arquivo = fopen("agencias.txt", "r+");
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo 'agencias.txt' para leitura e escrita.\n");
        exit(1);
    }

    // Abre um arquivo temporário para escrever as agências em ordem
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro: Não foi possível criar o arquivo temporário.\n");
        fclose(arquivo);
        exit(1);
    }

    char linha[256];
    int encontrou = 0; // Variável para verificar se a agência já foi adicionada
    int inserido = 0;  // Variável para verificar se a agência foi inserida no arquivo temporário

    // Copia o cabeçalho para o arquivo temporário
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        fputs(linha, temp);
    }

    // Loop para encontrar a posição correta para inserir a nova agência
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // ler e compara o nome
        char nomeAgencia[20];
        sscanf(linha, "%s", nomeAgencia);

        if (strcasecmp(novaAgencia->nome, nomeAgencia) < 0 && !inserido) {
            // Inseri a nova agência antes desta linha
            fprintf(temp, "%s\t%d\t%s\t%d\t%d\t%s\n", novaAgencia->nome, novaAgencia->codigo, novaAgencia->localizacao, novaAgencia->numClientes, novaAgencia->numContas, novaAgencia->horario);
            inserido = 1;
        }
       
        fputs(linha, temp); // Copia a linha para o arquivo temporário
    }

    // Se a agência ainda não foi inserida no arquivo temporário, insire no final
    if (!inserido) {
        fprintf(temp, "%s\t%d\t%s\t%d\t%d\t%s\n", novaAgencia->nome, novaAgencia->codigo, novaAgencia->localizacao, novaAgencia->numClientes, novaAgencia->numContas, novaAgencia->horario);
    }

    // Fecha ambos os arquivos
    fclose(arquivo);
    fclose(temp);

    // Substitui o arquivo original pelo temporário
    remove("agencias.txt");
    rename("temp.txt", "agencias.txt");
}

// Função para listar todas as agências cadastradas no arquivo "agencias.txt"
void listarAgencias() {
    FILE *arquivo = fopen("agencias.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo 'agencias.txt'.\n");
        exit(1);
    }

    char linha[256];
    int totalAgencias = 0;

    // Ler e imprimir todas as agências
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[50];
        int codigo;
        char localizacao[100];
        int numClientes;
        int numContas;
        char horario[20]; 
        
        if (sscanf(linha, "%49[^\t]\t%d\t%99[^\t]\t%d\t%d\t%19[^\t]", nome, &codigo, localizacao, &numClientes, &numContas, horario) == 6) {
            printf("Nome da Agência: %s\n", nome);
            printf("Código: %d\n", codigo);
            printf("Localização: %s\n", localizacao);
            printf("Número de Clientes: %d\n", numClientes);
            printf("Número de Contas: %d\n", numContas);
            printf("Horário: %s\n", horario);
            printf("\n");
            totalAgencias++;
        }
        else {
            printf("Erro: Formato de linha de agência inválido.\n");
        }
    }

    fclose(arquivo);

    printf("Total de Agências: %d\n", totalAgencias);
}

// Função para buscar uma determinda agencia, se encontrar a agencia retorna 0, se não retorna 1.
int buscarAgenciaPorNome(const char nome[]) {
    FILE *arquivo = fopen("agencias.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo 'agencias.txt' para leitura.\n");
        exit(1);
    }

    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nomeAgencia[50];

        if (sscanf(linha, "%49[^\t]", nomeAgencia) == 1) {
            if (strcasecmp(nomeAgencia, nome) == 0) {
                fclose(arquivo);
                return 0; // Agência encontrada
            }
        } else {
            printf("Erro: Formato de linha de agência inválido.\n");
        }
    }

    fclose(arquivo);
    return 1; // Agência não encontrada
}




