#include <cstdio>
#include <cctype>

void criptografarTexto(char* texto, int chave)
{
    int i = 0;
    while (texto[i] != '\0') {
        if (isalpha(texto[i])) {
            char base = isupper(texto[i]) ? 'A' : 'a';
            texto[i] = ((texto[i] - base + chave) % 26) + base;
        }
        i++;
    }
}

void descriptografarTexto(char* texto, int chave)
{
    int i = 0;
    while (texto[i] != '\0') {
        if (isalpha(texto[i])) {
            char base = isupper(texto[i]) ? 'A' : 'a';
            texto[i] = ((texto[i] - base - chave + 26) % 26) + base;
        }
        i++;
    }
}

char* lerArquivo(const char* nomeArquivo)
{
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == nullptr) {
        printf("Erro ao abrir o arquivo.\n");
        return nullptr;
    }

    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    char* conteudo = new char[tamanhoArquivo + 1];

    int i = 0;
    int c;
    while ((c = fgetc(arquivo)) != EOF) {
        conteudo[i++] = c;
    }
    conteudo[i] = '\0';

    fclose(arquivo);

    return conteudo;
}

void gravarArquivo(const char* nomeArquivo, const char* conteudo)
{
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == nullptr) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%s", conteudo);

    fclose(arquivo);
}

int main()
{
    int opcao;
    char* texto;

    do {
        printf("Selecione a opcao:\n");
        printf("1. Criptografar texto\n");
        printf("2. Descriptografar texto\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int chave;
                printf("Digite a chave de criptografia: ");
                scanf("%d", &chave);

                texto = lerArquivo("texto.txt");
                if (texto != nullptr) {
                    criptografarTexto(texto, chave);
                    printf("\nTexto criptografado:\n%s\n", texto);
                    gravarArquivo("texto.txt", texto);
                    delete[] texto;
                }
                break;
            }
            case 2: {
                int chave;
                printf("Digite a chave de descriptografia: ");
                scanf("%d", &chave);

                texto = lerArquivo("texto.txt");
                if (texto != nullptr) {
                    descriptografarTexto(texto, chave);
                    printf("\nTexto descriptografado:\n%s\n", texto);
                    gravarArquivo("texto.txt", texto);
                    delete[] texto;
                }
                break;
            }
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}

