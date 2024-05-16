#include <stdio.h>
#include <fstream>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <chrono>
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
    //instanciacao das variaveis em arrays
    int L[tamanhoEsquerda], R[tamanhoDireita]; 
  
    // alimentando os dados com os enderecamentos preestabelecidos
    for (i = 0; i < tamanhoEsquerda; i++){
         L[i] = arr[e + i]; 
    }
    for (j = 0; j < tamanhoDireita; j++) {
         R[j] = arr[m + 1 + j]; 
    }
    //zerar os enderecos, e instanciar k para comecar no comeco da subsecao do array.
    i = 0; 
    j = 0;
    k = e; 
    // verificar, enquanto um endereco ou o outro não for do tamanho da sua secao, continuar no loop
    while (i < tamanhoEsquerda && j < tamanhoDireita) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    // verificar, e mudar caso haja elementos restantes.
    while (i < tamanhoEsquerda) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    // verificar, e mudar caso haja elementos restantes.
    while (j < tamanhoDireita) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
// chamar recursivamente si proprio
void mergeSort(int arr[], int e, int d) 
{ 
    if (e < d) { 
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
      // especificando o caminho do path
    string filePaths[490]={
        "../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup1.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Crescente/dtcresc50dup7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup1.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Convexo-CresceDescresce/dtconvx50dup4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup1.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Aleatorio/dtaleat50dup3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup1.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Concavo-DecresceCresce/dtconcv50dup2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup1.txt",				
"../../dadosExternos/colecaoDados/dados/50/Com Duplicidade/Descrescente/dtdecre50dup0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni1.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Crescente/dtcresc50uni4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni1.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50uni0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni1.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Aleatorio/dtaleat50uni4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni1.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50uni6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni4.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni2.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni7.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni0.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni6.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni8.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni5.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni3.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni9.txt",				
"../../dadosExternos/colecaoDados/dados/50/Sem Duplicidade/Descrescente/dtdecre50uni1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup9.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Crescente/dtcresc100dup4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup9.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Convexo-CresceDescresce/dtconvx100dup7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup9.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Aleatorio/dtaleat100dup7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Concavo-DecresceCresce/dtconcv100dup9.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup9.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Com Duplicidade/Descrescente/dtdecre100dup2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni9.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Crescente/dtcresc100uni4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni9.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Convexo-CresceDescresce/dtconvx100uni1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Aleatorio/dtaleat100uni9.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni9.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Concavo-DecresceCresce/dtconcv100uni1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni0.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni7.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni3.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni1.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni5.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni8.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni2.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni6.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni4.txt",				
"../../dadosExternos/colecaoDados/dados/100/Sem Duplicidade/Descrescente/dtdecre100uni9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup8.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Crescente/dtcresc10dup7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup8.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Convexo-CresceDescresce/dtconvx10dup4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Aleatorio/dtaleat10dup8.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Concavo-DecresceCresce/dtconcv10dup8.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup8.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Com Duplicidade/Descrescente/dtdecre10dup5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni8.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Crescente/dtcresc10uni0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni8.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Convexo-CresceDescresce/dtconvx10uni7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Aleatorio/dtaleat10uni8.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni8.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Concavo-DecresceCresce/dtconcv10uni1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni0.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni6.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni3.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni5.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni2.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni1.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni4.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni7.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni9.txt",				
"../../dadosExternos/colecaoDados/dados/10/Sem Duplicidade/Descrescente/dtdecre10uni8.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni2.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni8.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni1.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni6.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni4.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni7.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni5.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni9.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni0.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Crescente/dtcresc50kuni3.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni2.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni7.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni4.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni8.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni0.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni6.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni3.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni9.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni1.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Convexo-CresceDescresce/dtconvx50kuni5.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni4.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni5.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni7.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni1.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni0.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni9.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni3.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni2.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni6.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Concavo-DecresceCresce/dtconcv50kuni8.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni3.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni6.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni4.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni7.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni5.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni0.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni9.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni1.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni8.txt",				
"../../dadosExternos/colecaoDados/dados/50k/Sem Duplicidade/Descrescente/dtdecre50kuni2.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup1.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup7.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup2.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup8.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup3.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup0.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup9.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup6.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup4.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Crescente/dtcresc5kdup5.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup2.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup3.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup5.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup4.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup9.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup7.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup8.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup6.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup1.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Convexo-CresceDescresce/dtconvx5kdup0.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup9.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup5.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup4.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup3.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup6.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup7.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup1.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup0.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup2.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Aleatorio/dtaleat5kdup8.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup5.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup1.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup8.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup3.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup0.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup9.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup6.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup4.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup2.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Concavo-DecresceCresce/dtconcv5kdup7.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup0.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup2.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup9.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup1.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup7.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup8.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup6.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup3.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup5.txt",				
"../../dadosExternos/colecaoDados/dados/5k/Com Duplicidade/Descrescente/dtdecre5kdup4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup2.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Crescente/dtcresc500dup5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup2.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Convexo-CresceDescresce/dtconvx500dup3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup2.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Aleatorio/dtaleat500dup5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup2.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Concavo-DecresceCresce/dtconcv500dup9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup2.txt",				
"../../dadosExternos/colecaoDados/dados/500/Com Duplicidade/Descrescente/dtdecre500dup3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni2.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Crescente/dtcresc500uni8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni2.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Convexo-CresceDescresce/dtconvx500uni9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni2.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Aleatorio/dtaleat500uni7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni2.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Concavo-DecresceCresce/dtconcv500uni5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni6.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni0.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni1.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni4.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni8.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni5.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni9.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni3.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni7.txt",				
"../../dadosExternos/colecaoDados/dados/500/Sem Duplicidade/Descrescente/dtdecre500uni2.txt"				
    };
    // declarando, respecitvamente, a linha a ser lida e o contador de arquivos
    string linha_;
    int k = 0;
    //limpando o arquivo txt do bubble_sort por execucao
    std::fstream file("merge_sort.txt", std::ios::out | std::ios::trunc);
    ofstream arquivoEscrita_("merge_sort.txt", std::ios::app);
    if (arquivoEscrita_.is_open()){
        arquivoEscrita_    <<   "caminho,temp_execucao,qtde \n";
    }
    while(k < 490){
        printf("Inserindo o arquivo N^%d \n ", k+1);
        int contadorArr = 0;
        int tamanho = 0;
        // abrindo o arquivo TXT
        // preparando a leitura do arquivo com os dados
        ifstream arquivoLeitura_(filePaths[k]);
        // preparando a escrita do arquivo para os dados finais
        // ofstream arquivoEscrita_("bubble_sort.txt", std::ios::app);
        //     arquivoEscrita_.close();
        // verifica se o arquivo estiver aberto, realiza a leitura da quantidade de linhas
        if(arquivoLeitura_.is_open()){
            while(getline(arquivoLeitura_, linha_)){
                contadorArr++;
                tamanho++;
            }
            // declara o tamanho do array apos apuracao da quantidade de linhas do arquivo
            int arr[contadorArr+1];
            // de
            int interadorArr = 0;
             while(getline(arquivoLeitura_, linha_)){
                arr[interadorArr] = stoi(linha_);
                interadorArr++;
            }
            auto comeco = std::chrono::high_resolution_clock::now();
            mergeSort(arr, 0,sizeof(arr)/sizeof(arr[0]));
            auto final = std::chrono::high_resolution_clock::now();
            auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(final - comeco);
            mostrarDados(arr, sizeof(arr)/sizeof(arr[0]));
            cout << tamanho-1 << "\n";
            if(arquivoEscrita_.is_open()){
                 arquivoEscrita_ << filePaths[k] << "," << duracao.count() << "ms," << tamanho-1<<"\n";
            }
            arquivoLeitura_.close();
        }
        k++;
    }
    arquivoEscrita_.close();
    return 0;
}