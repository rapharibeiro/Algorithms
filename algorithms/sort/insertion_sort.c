/*
Algoritmo de ordenação: Insertion Sort
Complexidade do tempo: O(n²)
Descrição: Algoritmo de ordenação simples que funciona da maneira como ordenamos cartas de jogar em nossas mãos. 
Ordenamos as duas primeiras cartas e depois colocamos a terceira carta na posição apropriada dentro das duas primeiras, 
e depois a quarta está posicionada dentro das três primeiras e assim por diante até que a mão inteira seja orndenada.
*/

#include <stdio.h>
#include "swap.h"

void insertionSort(int * array, int size){
	int j;
    for(int i = 1; i < size; i++){
        j = i;
        while(j > 0 && (array[j-1] > array[j])){
            swap(array, j, j-1);
            j--;
        }   
    }
}

int main(int argc, char const *argv[])
{
	/* code */
	int array[10] = {5, 7, 10, 3, 2, 1, 16, 11, 6, 20};
	int size = sizeof(array)/sizeof(array[0]);
	insertionSort(array, size);
	for (int i = 0; i < size; ++i){
		printf("%d ", array[i]);
	}
	return 0;
}