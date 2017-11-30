#include <stdio.h>

int main(){
	
	return 0;
}

int Enumeration(int *A){
	int tam = sizeof(A) / sizeof(A[0]);
	int max_subarray = 0;
	int soma = 0;
	int index_inicio, index_fim;

	for (int i = 0; i < tam; ++i){
		soma = 0;
		index_inicio = i;

		for (int j = i; j < tam; j++){
		
			soma += A[j];
		
			if (soma > max_subarray){
					max_subarray = soma;
					index_fim = j;
				}	
		}

	return max_subarray;
	
	}

}