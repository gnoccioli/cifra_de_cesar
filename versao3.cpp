#include <cstdio>
#include <cctype>
#include <cstring>

void criptografarTexto(char* texto, int chave)
{
    printf("\nTexto:\n%s\n", texto);

    int i = 0;
    while (texto[i] != '\0') {
        texto[i] = (texto[i] + chave);
        i++;
    }
}

void descriptografarTexto(char* texto, int chave)
{
    printf("\nTexto:\n%s\n", texto);

    int i = 0;
    while (texto[i] != '\0') {
        texto[i] = (texto[i] - chave);
        i++;
    }
}


char* lerArquivo(const char* nomeArquivo)
{
    FILE* arquivo_ori;
    char texto_ori[1000], linha[1000];

    arquivo_ori = fopen(nomeArquivo, "r");

    if (arquivo_ori == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return nullptr;
    }

    strcpy(texto_ori, "");
    while (fgets(linha, 1000, arquivo_ori) != NULL) {
    strcat(texto_ori, linha);
}

fclose(arquivo_ori);

char* conteudo = new char[strlen(texto_ori) + 1];
    strcpy(conteudo, texto_ori);

    return conteudo;
}

void gravarArquivo(const char* nomeArquivo, const char* conteudo)
{
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
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

