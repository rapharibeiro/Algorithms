/*
Algoritmo de ordenação: Bubble Sort
Complexidade do tempo: O(n²)
Descrição: Algoritmo que é usado para ordernar uma lista de elementos. 
O algoritmo compara dois elementos adjacentes e, em seguida, os troca se eles não estiverem em ordem. 
O processo é repetido até que não seja necessária mais troca.
*/

#include <stdio.h>
#include "swap.h"

//Função para ordenar
void bubbleSort(int * array, int size){
	int isSorted = 0;
	while(!isSorted){
		isSorted = 1;
		int lastUnsorted = (size - 1);
		for (int i = 0; i < lastUnsorted; ++i){
			if(array[i] > array[i + 1]){
				swap(array, i, i + 1);
				isSorted = 0;
			}
		}
		lastUnsorted--;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int array[10] = {5, 7, 10, 3, 2, 1, 16, 11, 6, 20};
	int size = sizeof(array)/sizeof(array[0]);
	bubbleSort(array, size);
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	return 0;
}