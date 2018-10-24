//Função para trocar de posição os valores enviados.
void swap(int * array, int i, int j){
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}