// Segunda implementação do algoritmo do subvetor maximo
// Versão iterativa melhorada!

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h> 
#include <sys/time.h> 

int main( int argc, char *argv[ ] ){
	if (argc != 3)
	{
		printf("Uso: ./algoritmo tam_vet file\n");
		return 0;
	}

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	int n = atoi(argv[1]); // tamanho do vetor
	fp = fopen(argv[2], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	int vet[n];

	while ((read = getline(&line, &len, fp)) != -1)
	{
		vet[i] = atoi(line);
		i++;
	}
	
	int soma, maxSoma = INT_MIN, inicio, fim;
    
    clock_t tempoInicial, tempoFinal;
   	double tempoGasto;
   	tempoInicial = clock();
	// encontrar o subvetor maximo
	for (int i = 0; i < n; i++){ // valor inicial
		soma = 0;
		for (int j = i; j < n; j++){ // vai de i até n
			soma += vet[j];
			if (soma > maxSoma){ // testa todas as somas de i até n e encontra a maior
				maxSoma = soma;
				inicio = i;
				fim = j;
			}
		}
	}
    tempoFinal = clock();

   	tempoGasto = ((tempoFinal-tempoInicial)/CLOCKS_PER_SEC);
	
	// imprimir resultados
	for (int i = 0; i < n; i++){
		printf("vet[%d]: %d\n", i, vet[i]);
	}
	printf("Soma maxima: %d \ninicio: %d \nfim: %d\n", maxSoma, inicio, fim);
   	printf("Tempo em segundos: %f\n", tempoGasto);


	return 0;	
}
