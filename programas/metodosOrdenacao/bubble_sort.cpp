#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <filesystem>
#include <chrono>
#include "lib.h"



void troca(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// A funcao que implementa o bubble sort
void bubbleSort(int arr[], int n)
{
    // implementa os enderecos de bidimensionais para apuracao do codigo
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Ultimos elementos i ja estao em ordem
        for (j = 0; j < n - i - 1; j++)
            // somente realiza a troca caso seja maior, o proximo valor a ser testado
            if (arr[j] > arr[j + 1])
                troca(arr, j, j + 1);
}

// Function to print an array
void mostrarDados(int arr[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// funcao teste
int main()
{

    // declarando, respecitvamente, a linha a ser lida e o contador de arquivos
    std::string linha_;
    int k = 0;
    // limpando o arquivo txt do bubble_sort por execucao
    std::fstream file("bubble_sort.txt", std::ios::out | std::ios::trunc);
    std::ofstream arquivoEscrita_("bubble_sort.txt", std::ios::app);
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
        std::ifstream arquivoLeitura_(filePaths[k]);
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
            bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
            auto final = std::chrono::high_resolution_clock::now();
            auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(final - comeco);
            mostrarDados(arr, sizeof(arr) / sizeof(arr[0]));
            std::cout << tamanho - 1 << "\n";
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
