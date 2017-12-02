// divisão e conquista!
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h> 
#include <sys/time.h> 


// struct para poder retornar mais de um valor na função
typedef struct Subvetor
{
	int inicio;
	int fim;
	int soma;
} subvetor;

// função para verificar se o subvetor maximo está no meio do vetor
subvetor max_cross(int* vet, int inicio, int meio, int fim);

// função para encontrar o subvetor
subvetor subvetor_maximo(int* vet, int inicio, int fim);

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

	struct timeval time1, time2;
    double elapsedTime;

	gettimeofday(&time1, NULL);
	// encontrar o subvetor maximo
	subvetor maxSubVetor = subvetor_maximo(vet, 0, n-1);

	gettimeofday(&time2, NULL);
	elapsedTime = (time2.tv_sec - time1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (time2.tv_usec - time1.tv_usec) / 1000.0;   // us to ms

	// imprimir resultados
	for (int i = 0; i < n; i++){
		printf("vet[%d]: %d\n", i, vet[i]);
	}
	printf("Soma maxima: %d \ninicio: %d \nfim: %d\n", maxSubVetor.soma, maxSubVetor.inicio, maxSubVetor.fim);
	printf("Tempo real: %lf ms\n", elapsedTime);
	
	return 0;	
}

subvetor max_cross(int* vet, int inicio, int meio, int fim){
	int e_soma = INT_MIN, d_soma = INT_MIN, soma;
	subvetor maxSubVetor;
	int e_max, d_max;

	soma = 0;
	for (int i = meio; i >= inicio; i--) // inicia no meio e vai até o inicio
	{
		soma += vet[i];
		if (e_soma < soma){ // encontra a maior soma do meio indo para o lado esquerdo
			e_soma = soma;
			e_max = i;
		}
	}
	soma = 0;
	for (int i = meio+1; i <= fim; i++) // inicia no meio e vai até o fim
	{
		soma += vet[i];
		if(soma > d_soma){ // encontra a maior soma do meio indo para o lado direito
			d_soma = soma;
			d_max = i;
		}
	}

	
	// cria o subvetor de retorno
	maxSubVetor.inicio = e_max;
	maxSubVetor.fim = d_max;
	maxSubVetor.soma = (e_soma + d_soma);
	// printf("Soma maxima: %d \ninicio: %d \nfim: %d\n", maxSubVetor.soma, maxSubVetor.inicio, maxSubVetor.fim);
	
	return maxSubVetor;
}

subvetor subvetor_maximo(int* vet, int inicio, int fim){
	subvetor maxSubVetor;
	subvetor e_maxSubVetor;
	subvetor m_maxSubVetor;
	subvetor d_maxSubVetor;
	
	// caso base
	if (inicio == fim){
		// cria o subvetor de retorno
		maxSubVetor.inicio = inicio;
		maxSubVetor.fim = fim;
		maxSubVetor.soma = vet[inicio];
		
		return maxSubVetor;
	}
	
	int meio = (inicio + fim)/2;
	printf("inicio = %d, fim = %d, meio=%d\n", inicio, fim, meio);
	e_maxSubVetor = subvetor_maximo(vet, inicio, meio); // testa se o subvetor está a esquerda
	d_maxSubVetor = subvetor_maximo(vet, meio+1, fim); // testa se o subvetor está a direita
	m_maxSubVetor = max_cross(vet, inicio, meio, fim); // testa se o subvetor está no meio

	if(e_maxSubVetor.soma >= d_maxSubVetor.soma && e_maxSubVetor.soma >= m_maxSubVetor.soma){ // testa se o maior subvetor é o da esquerda
		return e_maxSubVetor;
	} else if (d_maxSubVetor.soma >= e_maxSubVetor.soma && d_maxSubVetor.soma >= m_maxSubVetor.soma){ // testa se o maior subvetor é o da direita
		return d_maxSubVetor;
	} else { // se não.. retorna o subvetor do meio
		return m_maxSubVetor;
	}
}
