#include <stdio.h> 
  
// funcao para trocar os elementos
void troca(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
// particao da funcao
int particao(int arr[], int baixo, int alto) 
{ 
  
    // instanciar o pivo para ser o primeiro elemento
    int pivo = arr[baixo];
    int i = baixo; 
    int j = alto; 
  
    while (i < j) { 
  
        // condicao 1: achar o primeiro elemento maior que o pivo
        while (arr[i] <= pivo && i <= alto - 1) { 
            i++; 
        } 
  
        // condicao 2: achar o primeiro elemento menor que o pivo
        while (arr[j] > pivo && j >= baixo + 1) { 
            j--; 
        } 
        // caso o endereco seja menor, realizar a troca
        if (i < j) { 
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
    if (baixo < alto) { 
  
        int enderecoParticao = particao(arr, baixo, alto); 
  
   
        quickSort(arr, baixo, enderecoParticao- 1); 
        quickSort(arr, enderecoParticao + 1, alto); 
    } 
} 
  
int main() 
{ 
    int arr[] = {9,238,71283,23,23,23,23,23,23,23,23,3231,9823,10}; 
    int tamanho = sizeof(arr) / sizeof(arr[0]); 
  
    // mostrar o array original
    printf("Array original: "); 
    for (int i = 0; i < tamanho; i++) { 
        printf("%d ", arr[i]); 
    } 
  
    // chamando quickSort para ordenar o array original
    quickSort(arr, 0, tamanho - 1); 
  
    // mostrar os dados ordenados
    printf("\nArray ordenado: "); 
    for (int i = 0; i < tamanho; i++) { 
        printf("%d ", arr[i]); 
    } 
  
    return 0; 
}
