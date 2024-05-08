#include <stdio.h>
#include <stdexcept>

using namespace std;
// instanciando prototipos das funcoes, para serem visiveis para a funcao main

bool bubbleSort(int * lista);
int tamanhoArray(int * lista);
bool exibirLista(int * lista);
// funcao que executa o teste de uma dada quantidade alimentada na funcao main;
int main (void){
    // variavel array de teste;
    int listaTeste[5] = {8,9,231,67,12};
    // variavel de tamanho da lista, que reporta o tratamento e entra na verificao;
    int tamanhoLista = tamanhoArray(listaTeste);
    // variaveis booleanas, para auxiliar no tratamento dos erros do fluxo da funcao prototipo teste
    bool verificarBubbleSort, verificarExibirLista = true;
    // tratamento de  excecao, tendo em vista a verificao logica de uma lista vazi e erro de processamento;
    try
    {   
        verificarBubbleSort  = bubbleSort(listaTeste);
        verificarExibirLista = exibirLista(listaTeste);
        // verifica se a lista esta vazia;
        if (tamanhoLista == -1)
            throw -1;
        // verifica erro de processamento/lista vazia
        if (verificarBubbleSort == false)
            throw false;
        // verifica erro de processamento/lista vazia
        if (verificarExibirLista == false)
            throw false;
    } // tratamento das excecoes, com returns diferentes para saber cada causa de erro;
    catch(int erroListaVazia)
    {
        printf("Lista vazia! \n");
        return 1;
    }
    catch (bool erroProcessamento){
        if (verificarBubbleSort == false){
            printf("Erro de processamento do teste do BubbleSort! \n");
            return 2;
        } else{
            printf("Erro de processamento, pois a lista esta vazia para exibir! \n");
            return 3;
        }
    }
    return 0;
}

// função prototipo teste, para verificacao logica dos testes
bool bubbleSort(int * lista){
    // verifica se a lista esta vazia
    if (lista == NULL)
        return false;
    int const tamanho = tamanhoArray(lista);
    // adicionando o contador das variaveis locais do método de ordenação, com padrão i e j, para o padrão 2D dimensional
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            // verifica a relacao logica entre os elementos da lista, caso maior, entra na condicao if
                if (lista[i] > lista[j]){
                    // instanciando variavel temporaria como meio intermediador de troca dos ponteiros do array
                    int temp = lista[i];
                    lista[i] = lista[j];
                    lista[j] = temp;
                }
        }
    }
    return true;
}

// lista o tamanho do array inputado no teste
int tamanhoArray(int * lista){
    // declaracao do iterador do programa;
    int i = 0;
    // tratamento de erros, como sub-erro da funcao main
    try
    {   //verifica se a lista esta vazia
        if (lista == NULL) 
            throw -1;
        // realiza o loop, enquanto o ponteiro que estiver apontando esta diferente de nulo
        while (lista != NULL){
            lista+=1;
        }
        printf("O array contem %d elemento(s) \n", i);
        return i;
    } //tratamento da excecao, como -1, ja que foge do tamanho verdadeiro da lista
    catch(int listaVazia)
    {
        printf("Lista vazia, erro de teste! \n");
        return -1;
    }     
}

bool exibirLista(int * lista){
    // declaracao do iterador do programa;
    int i = 0;
    try
    {
        //verifica se a lista esta vazia
        if (lista == NULL) 
            throw -1;
        // realiza o loop, enquanto o ponteiro que estiver apontando esta diferente de nulo
        while (lista != NULL){
            printf(" %d º elemento - %d \n", i+1 , lista[i]);
            i++;
        }
    } //tratamento da excecao, como false, ja que foge do tamanho verdadeiro da lista
    catch(int listaVazia)
    {
        printf("Lista vazia, erro de teste! \n");
        return false;
    }  
    return true;
}



