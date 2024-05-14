#include <stdio.h>
#include<iostream>
#include <array>
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
    int arr[] = { 12, 11, 13, 5, 6, 7 }; 
    int tamanho = sizeof(arr) / sizeof(arr[0]); 
  
    printf("O array original e: \n"); 
    mostrarDados(arr, tamanho); 
  
    mergeSort(arr, 0, tamanho - 1); 
  
    printf("\nO array ordenado e: \n"); 
    mostrarDados(arr, tamanho); 
    return 0; 
}