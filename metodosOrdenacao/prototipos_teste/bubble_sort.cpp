#include <stdio.h>
#include <fstream.h>
#include <string>
#include <fstream>

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
    const int MAX_SIZE = 100; // Maximum size of the array
    int numbers[MAX_SIZE];    // Declare an array to store numbers
    int count = 0;             // Counter for the number of elements read

    // Specify the relative path to the file
    string filePath = "../folder_before_current/numbers.txt";

    // Open the TXT file
    ifstream inputFile(filePath);
    if (!inputFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // Read numbers from the file until the end is reached or the array is full
    while (count < MAX_SIZE && inputFile >> numbers[count]) {
        count++;
    }

    // Close the file
    inputFile.close();

    // Output the numbers read from the file
    cout << "Numbers read from the file:" << endl;
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    int arr[] = {7,8,912213,1,78,20,29,30,21};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, tamanho);
    printf("Sorted array: ");
    mostrarDados(arr, tamanho);
    return 0;
}



