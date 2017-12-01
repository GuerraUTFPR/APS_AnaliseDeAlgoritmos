#include <stdio.h>


int Enumeration(int A[]){
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

int divAndCon(int a[], int lo, int hi){
	//int* somaArray = malloc((hi - lo) * sizeof(int)); //for storing winning array, 
	
	int meio;
	
	
	int maxEsq=0;
	int maxDir=0;

	//max's found crossing middle iteratively
	int bothMax=0;
	int bothMaxLeft=0;
	int bothMaxRight=0;

	//counters
	int i, soma;

	//base case, only 1 element in array
	//TODO: ensure no issue w/ no elements
	if (lo==hi) { //lo and hi are the same element
		return a[hi]; //soma is this element alone
	}

	//divide  array into two halves
	meio = (lo + hi)/2;

	//maximum of 

		//maximum soma on left
		//recursive call

	
	maxEsq = divAndCon(a, lo, meio);

		//max soma on right
		//recursive call
	
	maxDir = divAndCon(a, meio+1, hi);

		//max soma from meio
			//find max going left

	bothMaxLeft = 0;
	soma = 0;
	for (i = meio-1; i >=0; i-- ){
		soma += a[i];
		if (soma > bothMaxLeft)
			bothMaxLeft = soma;
	}
	
			//find max going right
	bothMaxRight = 0;
	soma = 0;
	for (i = meio; i < hi; i++ ){
		soma += a[i];
		if (soma > bothMaxRight)
			bothMaxRight = soma;
	}
			//combine
	bothMax = bothMaxRight + bothMaxLeft;

	return fmax(bothMax, fmax(maxEsq, maxDir));
}

int main(){
	
	return 0;
}
