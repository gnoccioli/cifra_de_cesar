#include <iostream>
#include <fstream>
using namespace std;

// Função para criptografar o texto usando a cifra de César
string criptografarTexto(string texto, int chave) {
    string textoCriptografado = "";
    for (char& c : texto) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = ((c - base + chave) % 26) + base;
        }
        textoCriptografado += c;
    }
    return textoCriptografado;
}

// Função para descriptografar o texto usando a cifra de César
string descriptografarTexto(string texto, int chave) {
    return criptografarTexto(texto, 26 - chave); // Usando a mesma função de criptografia com a chave complementar
}

// Função para ler o conteúdo do arquivo de texto
string lerArquivoTexto(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    string conteudo;

    if (arquivo.is_open()) {
        char c;
        while (arquivo.get(c))
            conteudo += c;
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }

    return conteudo;
}

// Função para escrever o conteúdo no arquivo de texto
void escreverArquivoTexto(string nomeArquivo, string conteudo) {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        arquivo << conteudo;
        arquivo.close();
        cout << "Arquivo salvo com sucesso." << endl;
    } else {
        cout << "Erro ao abrir o arquivo." << endl;
    }
}

int main() {
    int opcao;
    string nomeArquivo = "texto.txt";

    do {
        cout << "=== MENU ===" << endl;
        cout << "1. Criptografar texto" << endl;
        cout << "2. Descriptografar texto" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int chave;
                cout << "Digite a chave de criptografia: ";
                cin >> chave;

                string texto = lerArquivoTexto(nomeArquivo);
                string textoCriptografado = criptografarTexto(texto, chave);
                escreverArquivoTexto(nomeArquivo, textoCriptografado);
                break;
            }
            case 2: {
                int chave;
                cout << "Digite a chave de descriptografia: ";
                cin >> chave;

                string texto = lerArquivoTexto(nomeArquivo);
                string textoDescriptografado = descriptografarTexto(texto, chave);
                escreverArquivoTexto(nomeArquivo, textoDescriptografado);
                break;
            }
            case 3:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 3);

    return 0;
}


