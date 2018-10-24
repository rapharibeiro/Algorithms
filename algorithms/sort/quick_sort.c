/*
Algoritmo de ordenação: Quick Sort
Complexidade do tempo: O(n log n)
Descrição: Algoritmo da categoria dividir e conquistar.
Ele opera quebrando grandes problemas em problemas menores e mais fáceis de resolver.
A ideia do algoritmo é a seguinte: um elemento dinâmico é selecionado. 
As versões do QuickSort diferem na maneira de escolher o pivô. 
Primeiro, último, mediano ou até mesmo um elemento selecionado aleatoriamente é um candidato a ser escolhido como pivô.

A parte principal do processo de ordenadação é o particionamento. 
Uma vez que o pivô é escolhido, o array é particionado em duas metades - 
uma metade contendo todos os elementos menores que o pivô e a outra metade contendo os elementos maiores que o pivô. 
Os iguais podem permanecer em ambos os lados. 
Em seguida, o mesmo processo ocorre para as metades restantes da matriz recursivamente, resultando eventualmente em uma matriz ordenada.
*/

#include <stdio.h>
#include "swap.h"

int partition(int * array, int left, int right, int pivo){
	while(left <= right){
		while(array[left] < pivo){
			left++;
		}
		while(array[right] > pivo){
			right--;
		}
		if(left <= right){
			swap(array, left, right);
			left++;
			right--;
		}
	}
	return left;
}

void quickSort_core(int * array, int left, int right){
	if(left >= right){
		return;
	}
	int pos = (left+right)/2;
	int pivo = array[pos];
	int index = partition(array, left, right, pivo);
	quickSort_core(array, left, (index -1));
	quickSort_core(array, index, right);
}

void quickSort(int * array, int size){
	quickSort_core(array, 0, (size-1));
}

int main(int argc, char const *argv[])
{
	/* code */
	int array[10] = {5, 7, 10, 3, 2, 1, 16, 11, 6, 20};
	int size = sizeof(array)/sizeof(array[0]);
	quickSort(array, size);
	for (int i = 0; i < size; ++i){
		printf("%d ", array[i]);
	}
	return 0;
}