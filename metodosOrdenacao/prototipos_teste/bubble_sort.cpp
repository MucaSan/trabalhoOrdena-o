#include <stdio.h>
void troca(int* arr, int i, int j)
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
    int arr[] = {7,8,912213,1,78,20,29,30,21};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, tamanho);
    printf("Sorted array: ");
    mostrarDados(arr, tamanho);
    return 0;
}



