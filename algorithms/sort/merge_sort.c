/*
Algoritmo de ordenação: Merge Sort
Complexidade do tempo: O(n log n)
Descrição: Algoritmo pertence à categoria de dividir e conquistar. 
Esses algoritmos operam dividindo grandes problemas em problemas menores e mais facilmente solucionáveis. 
A idéia do algoritmo é dividir o array ao meio repetidas vezes até que cada peça tenha apenas um item. 
Em seguida, esses itens são colocados juntos (merge) ordenadamente.
*/

#include <stdio.h>
#include "swap.h"

int mergeHalves(int * array, int leftStart, int rightEnd, int middle){

	int size = rightEnd - leftStart + 1;
	int left = leftStart;
	int right = middle + 1;
	int index = 0;

	int temp[size];
	

	while(left <= middle && right <= rightEnd){
		if(array[left] <= array[right]){
			temp[index] = array[left];
			left++;
		}else{
			temp[index] = array[right];
			right++;
		}
		index++;
	}

	while (left <= middle){
		temp[index] = array[left];
		left++;
		index++;
	}

	while (right <= rightEnd){
		temp[index] = array[right];
		right++;
		index++;
	}

	for (left = leftStart; left <= rightEnd; left++){
		array[left] = temp[left-leftStart];
	}

}

void mergeSort_core(int * array, int left, int right){
	if(left >= right){
		return;
	}
	int middle = (left+right)/2;
	mergeSort_core(array, left, middle);
	mergeSort_core(array, (middle+1), right);
	mergeHalves(array, left, right, middle);
}

void mergeSort(int * array, int size){
	mergeSort_core(array, 0, (size-1));
}

int main(int argc, char const *argv[])
{
	/* code */
	int array[10] = {5, 7, 10, 3, 2, 1, 16, 11, 6, 20};
	int size = sizeof(array)/sizeof(array[0]);
	mergeSort(array, size);
	for (int i = 0; i < size; ++i){
		printf("%d ", array[i]);
	}
	return 0;
}