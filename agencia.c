#include "agencia.h"


Agencia *criarAgencia(char nome[], int codigo, char localizacao[], int numClientes, int numContas, char horario[]) {
    Agencia *novaAgencia = (Agencia *)malloc(sizeof(Agencia)); // Correção aqui
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

void adicionarAgenciaEmOrdem(Agencia **lista, Agencia *novaAgencia) {
    // Abra o arquivo "dados.txt" em modo de leitura e escrita
    FILE *arquivo = fopen("dados.txt", "r+");
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo 'dados.txt' para leitura e escrita.\n");
        exit(1);
    }

    // Abra um arquivo temporário para escrever as agências em ordem
    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro: Não foi possível criar o arquivo temporário.\n");
        fclose(arquivo);
        exit(1);
    }

    char linha[256];
    int encontrou = 0; // Variável para verificar se a agência já foi adicionada
    int inserido = 0;  // Variável para verificar se a agência foi inserida no arquivo temporário

    // Copiar o cabeçalho para o arquivo temporário
    if (fgets(linha, sizeof(linha), arquivo) != NULL) {
        fputs(linha, temp);
    }

    // Loop para encontrar a posição correta para inserir a nova agência
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strncmp(linha, "Agencia", 7) == 0) {
            // Encontrou uma linha de agência, ler e comparar o nome
            char nomeAgencia[20];
            sscanf(linha, "Agencia\t%s", nomeAgencia);

            if (strcmp(novaAgencia->nome, nomeAgencia) < 0 && !inserido) {
                // Inserir a nova agência antes desta linha
                fprintf(temp, "Agencia\t%s\t%d\t%s\t%d\t%s\t%s\n", novaAgencia->nome, novaAgencia->codigo, novaAgencia->localizacao, novaAgencia->numClientes, novaAgencia->numContas, novaAgencia->horario);
                inserido = 1;
            }
        }
        fputs(linha, temp); // Copiar a linha para o arquivo temporário
    }

    // Se a agência ainda não foi inserida no arquivo temporário, insira no final
    if (!inserido) {
        fprintf(temp, "Agencia\t%s\t%d\t%s\t%d\t%s\t%s\n", novaAgencia->nome, novaAgencia->codigo, novaAgencia->localizacao, novaAgencia->numClientes, novaAgencia->numContas, novaAgencia->horario);
    }

    // Feche ambos os arquivos
    fclose(arquivo);
    fclose(temp);

    // Substitua o arquivo original pelo temporário
    remove("dados.txt");
    rename("temp.txt", "dados.txt");
}






