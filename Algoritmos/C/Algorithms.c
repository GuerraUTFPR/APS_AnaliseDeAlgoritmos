#include <stdio.h>

int enumerate(int n, int array[]){

	int max = 0;
	int aux = 0;

	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++){

			// Sum for sub-array array[i:j]
			aux = 0;
			for(int k = i; k <= j; k++)
				aux += array[k];

			// Updating max value
			if(aux > max) max = aux;
		}

	return max;
}

int better_enumerate(int n, int array[]){

	int max = 0;
	int aux = 0;

	for(int i = 0; i < n; i++){
		aux = 0;
		for(int j = i; j < n; j++){

			aux += array[j];

			// Updating max value
			if(aux > max) max = aux;
		}
	}

	return max;
}

int max_xffix(int n, int array[], int pre){

	int max = 0;
	int aux = 0;

	for(int i = 0; i < n; i++){

		if(pre)
			aux += array[i];
		else
			aux += array[n-i-1];

		// Updating max value
		if(aux > max) max = aux;
	}

	return max;
}

int divide_and_conquer(int n, int array[]){

	if(n == 1)
		return array[0];

	int max = 0;
	int aux = 0;
	int h = (float)n/2;

	// First half
	aux = divide_and_conquer(h,array);
	if(aux > max) max = aux;

	// Second half
	aux = divide_and_conquer(n-h,array+h);
	if(aux > max) max = aux;

	// Middle
	aux = max_xffix(h,array,0) + max_xffix(n-h,array+h,1);
	if(aux > max) max = aux;

	return max;
}

int linear(int n, int array[]){

	int max_suffix		= 0;
	int max_subarray	= 0;
	int aux = 0;

	for(int i = 0; i < n; i++){

		// Max suffix i
		aux = max_suffix + array[i];
		if(aux > 0)
			max_suffix = aux;
		else
			max_suffix = 0;

		// Max sub-array i
		if(max_suffix > max_subarray)
			max_subarray = max_suffix;

	}

	return max_subarray;
}
int main(){
	
	return 0;
}
