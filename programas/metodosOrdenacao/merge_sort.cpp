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

// funcao que instancia a juncao de duas separacoes do metodo do merge
void merge(int arr[], int e, int m, int d)
{
    // declaracao das variaveis de enderecamento respectivamente para particoes da direita, esquerda e do array subsecao gerada.
    int i, j, k;
    // tamanho da variavel do lado esquerda
    int tamanhoEsquerda = m - e + 1;
    // tamanho da variavel do lado direito
    int tamanhoDireita = d - m;
    // instanciacao das variaveis em arrays
    int L[tamanhoEsquerda], R[tamanhoDireita];

    // alimentando os dados com os enderecamentos preestabelecidos
    for (i = 0; i < tamanhoEsquerda; i++)
    {
        L[i] = arr[e + i];
    }
    for (j = 0; j < tamanhoDireita; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    // zerar os enderecos, e instanciar k para comecar no comeco da subsecao do array.
    i = 0;
    j = 0;
    k = e;
    // verificar, enquanto um endereco ou o outro não for do tamanho da sua secao, continuar no loop
    while (i < tamanhoEsquerda && j < tamanhoDireita)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // verificar, e mudar caso haja elementos restantes.
    while (i < tamanhoEsquerda)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    // verificar, e mudar caso haja elementos restantes.
    while (j < tamanhoDireita)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// chamar recursivamente si proprio
void mergeSort(int arr[], int e, int d)
{
    if (e < d)
    {
        int m = e + (d - e) / 2;

        mergeSort(arr, e, m);
        mergeSort(arr, m + 1, d);

        merge(arr, e, m, d);
    }
}
// mostrar toda a base de dados
void mostrarDados(int arr[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    // declarando, respecitvamente, a linha a ser lida e o contador de arquivos
    string linha_;
    int k = 0;

    // limpando o arquivo txt do bubble_sort por execucao
    std::fstream file("merge_sort.txt", std::ios::out | std::ios::trunc);
    ofstream arquivoEscrita_("merge_sort.txt", std::ios::app);

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
            mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
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