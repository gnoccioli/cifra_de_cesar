#include <cstdio>
#include <cctype>

void criptografarArquivo()
{
    int chave;
    printf("Digite a chave de criptografia: ");
    scanf("%d", &chave);

    FILE* arquivo = fopen("texto.txt", "r+");
    if (arquivo == nullptr) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base + chave) % 26) + base;
            fseek(arquivo, -1, SEEK_CUR);
/*após a leitura, o indicador de posição avança para o próximo caractere, mas queremos sobrescrever o caractere lido anteriormente.*/
            fputc(c, arquivo);
        }
    }

    fclose(arquivo);
    printf("Criptografia concluída.\n");
}

void descriptografarArquivo()
{
    int chave;
    printf("Digite a chave de descriptografia: ");
    scanf("%d", &chave);

    FILE* arquivo = fopen("texto.txt", "r+");
    if (arquivo == nullptr) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base - chave + 26) % 26) + base;
            fseek(arquivo, -1, SEEK_CUR);
            fputc(c, arquivo);
        }
    }

    fclose(arquivo);
    printf("Descriptografia concluída.\n");
}

int main()
{
    int opcao;

    do {
        printf("Selecione a opcao:\n");
        printf("1. Criptografar arquivo\n");
        printf("2. Descriptografar arquivo\n");
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criptografarArquivo();
                break;
            case 2:
                descriptografarArquivo();
                break;
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

