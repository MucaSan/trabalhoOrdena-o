

#include <stdio.h> 
  
// funcao para trocar os elementos
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
// particao da funcao
int partition(int arr[], int baixo, int alto) 
{ 
  
    // instanciar o pivo para ser o primeiro elemento
    int pivo = arr[baixo];
    int i = baixo; 
    int j = alto; 
  
    while (i < j) { 
  
        // condition 1: find the first element greater than 
        // the pivot (from starting) 
        while (arr[i] <= pivo && i <= alto - 1) { 
            i++; 
        } 
  
        // condition 2: find the first element smaller than 
        // the pivot (from last) 
        while (arr[j] > pivo && j >= baixo + 1) { 
            j--; 
        } 
        if (i < j) { 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[baixo], &arr[j]); 
    return j; 
} 
  
// funcao do quickSort
void quickSort(int arr[], int baixo, int alto) 
{ 
    if (baixo < alto) { 
  
        int partitionIndex = partition(arr, baixo, alto); 
  
   
        quickSort(arr, baixo, partitionIndex - 1); 
        quickSort(arr, partitionIndex + 1, alto); 
    } 
} 
  
int main() 
{ 
    int arr[] = { 19, 17, 15, 12, 16, 18, 4, 11, 13 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // printing the original array 
    printf("Original array: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
  
    // calling quickSort() to sort the given array 
    quickSort(arr, 0, n - 1); 
  
    // printing the sorted array 
    printf("\nSorted array: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
  
    return 0; 
}
