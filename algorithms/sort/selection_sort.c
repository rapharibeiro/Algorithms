/*
Algoritmo de ordenação: Selection Sort
Complexidade do tempo: O(n²)
Descrição: Algoritmo de ordenação simples que encontra o menor elemento na matriz e troca-o com o elemento na primeira posição, 
depois encontra o segundo menor elemento e o troca com o elemento na segunda posição, e assim continua até a matriz inteira esteja ordenada.
*/

#include <stdio.h>
#include "swap.h"

void selectionSort(int * array, int size){
	int min;
    for(int i = 0; i < size-1; i++){
        min = i;
        for(size_t j = i+1; j < size; j++){       
            if(array[j] < array[min]){      
                min = j;
            }
        }   
        swap(array, min, i);
    }
}

int main(int argc, char const *argv[])
{
	/* code */
	int array[10] = {5, 7, 10, 3, 2, 1, 16, 11, 6, 20};
	int size = sizeof(array)/sizeof(array[0]);
	selectionSort(array, size);
	for (int i = 0; i < size; ++i){
		printf("%d ", array[i]);
	}
	return 0;
}