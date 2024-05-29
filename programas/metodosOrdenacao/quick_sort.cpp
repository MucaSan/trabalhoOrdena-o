#include <stdio.h>
#include <fstream>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
#include "lib.h"

using namespace std;
namespace fs = std::filesystem;

// funcao para trocar os elementos
void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void mostrarDados(int arr[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// particao da funcao
int particao(int arr[], int baixo, int alto)
{

    // instanciar o pivo para ser o primeiro elemento
    int pivo = arr[baixo];
    int i = baixo;
    int j = alto;

    while (i < j)
    {

        // condicao 1: achar o primeiro elemento maior que o pivo
        while (arr[i] <= pivo && i <= alto - 1)
        {
            i++;
        }

        // condicao 2: achar o primeiro elemento menor que o pivo
        while (arr[j] > pivo && j >= baixo + 1)
        {
            j--;
        }
        // caso o endereco seja menor, realizar a troca
        if (i < j)
        {
            troca(&arr[i], &arr[j]);
        }
    }
    // no final, realiza a troca dos dois enderecos
    troca(&arr[baixo], &arr[j]);
    return j;
}

// funcao do quickSort
void quickSort(int arr[], int baixo, int alto)
{
    if (baixo < alto)
    {

        int enderecoParticao = particao(arr, baixo, alto);

        quickSort(arr, baixo, enderecoParticao - 1);
        quickSort(arr, enderecoParticao + 1, alto);
    }
}

int main()
{
    // declarando, respecitvamente, a linha a ser lida e o contador de arquivos
    string linha_;
    int k = 0;
    // limpando o arquivo txt do bubble_sort por execucao
    std::fstream file("quick_sort.txt", std::ios::out | std::ios::trunc);
    ofstream arquivoEscrita_("quick_sort.txt", std::ios::app);
    if (arquivoEscrita_.is_open())
    {
        arquivoEscrita_ << "caminho,temp_execucao,qtde \n";
    }
    while (k < 490)
    {
        printf("Inserindo o arquivo N^%d \n ", k + 1);
        int contadorArr = 0;
        int tamanho = 0;
        // abrindo o arquivo TXT
        // preparando a leitura do arquivo com os dados
        ifstream arquivoLeitura_(filePaths[k]);
        // preparando a escrita do arquivo para os dados finais
        // ofstream arquivoEscrita_("bubble_sort.txt", std::ios::app);
        //     arquivoEscrita_.close();
        // verifica se o arquivo estiver aberto, realiza a leitura da quantidade de linhas
        if (arquivoLeitura_.is_open())
        {
            while (getline(arquivoLeitura_, linha_))
            {
                contadorArr++;
                tamanho++;
            }
            // declara o tamanho do array apos apuracao da quantidade de linhas do arquivo
            int arr[contadorArr + 1];
            // de
            int interadorArr = 0;
            while (getline(arquivoLeitura_, linha_))
            {
                arr[interadorArr] = stoi(linha_);
                interadorArr++;
            }
            auto comeco = std::chrono::high_resolution_clock::now();
            quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
            auto final = std::chrono::high_resolution_clock::now();
            auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(final - comeco);
            mostrarDados(arr, sizeof(arr) / sizeof(arr[0]));
            cout << tamanho - 1 << "\n";
            if (arquivoEscrita_.is_open())
            {
                arquivoEscrita_ << filePaths[k] << "," << duracao.count() << "ms," << tamanho - 1 << "\n";
            }
            arquivoLeitura_.close();
        }
        k++;
    }
    arquivoEscrita_.close();
    return 0;
}
