// Versão iterativa!
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h> 
#include <sys/time.h> 
#include <math.h>	
#include <string.h>

void max_sub1(int vetor[], int n){
	int vet[n];
	for(int i = 0; i < n; i++){
		vet[i] = vetor[i];
	}
	int soma, maxSoma = INT_MIN, inicio, fim;
	struct timeval time1, time2;
    double elapsedTime;
	gettimeofday(&time1, NULL);
	// encontrar o subvetor maximo
	for (int i = 0; i < n; i++) // valor inicial
	{
		for (int j = i; j < n; j++) // valor final
		{
			soma = 0;
			for (int k = i; k <= j; k++) // soma todos os valores entre i e j
			{
				soma += vet[k];
			}
			if (soma > maxSoma) // testa se está é a maior soma
			{
				maxSoma = soma;
				inicio = i;
				fim = j;
			}
		}
	}

	gettimeofday(&time2, NULL);
	elapsedTime = (time2.tv_sec - time1.tv_sec) * 1000.0;	// sec to ms
	elapsedTime += (time2.tv_usec - time1.tv_usec) / 1000.0; // us to ms

	printf("Enumeration:\n");
	printf("Tempo: %lf ms\n", elapsedTime);
	printf("MaxSubArray: %d \n", maxSoma);
}


void max_sub2(int vetor[], int n){
	int vet[n];
	for(int i = 0; i < n; i++){
		vet[i] = vetor[i];
	}
	int soma, maxSoma = INT_MIN, inicio, fim;
	struct timeval time1, time2;
    double elapsedTime;
	gettimeofday(&time1, NULL);
	// encontrar o subvetor maximo
	for (int i = 0; i < n; i++) // valor inicial
	{
		soma = 0;
		for (int j = i; j < n; j++) // vai de i até n
		{
			soma += vet[j];
			if (soma > maxSoma){ // testa todas as somas de i até n e encontra a maior
				maxSoma = soma;
				inicio = i;
				fim = j;
			}
		}
	}
	gettimeofday(&time2, NULL);
	elapsedTime = (time2.tv_sec - time1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (time2.tv_usec - time1.tv_usec) / 1000.0;   // us to ms

	printf("Better Enumeration:\n");
	printf("Tempo: %lf ms\n", elapsedTime);	
	printf("MaxSubArray: %d \n", maxSoma);
}

typedef struct Subvetor{
	int inicio;
	int fim;
	int soma;
} subvetor;

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
	// printf("MaxSubArray: %d \ninicio: %d \nfim: %d\n", maxSubVetor.soma, maxSubVetor.inicio, maxSubVetor.fim);
	
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

void max_sub3(int vetor[], int n){
	int vet[n];
	for(int i = 0; i < n; i++){
		vet[i] = vetor[i];
	}
	struct timeval time1, time2;
    double elapsedTime;

	gettimeofday(&time1, NULL);
	// encontrar o subvetor maximo
	subvetor maxSubVetor = subvetor_maximo(vet, 0, n-1);

	gettimeofday(&time2, NULL);
	elapsedTime = (time2.tv_sec - time1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (time2.tv_usec - time1.tv_usec) / 1000.0;   // us to ms


	printf("Div n Conquer: \n");
	printf("Tempo: %lf ms\n", elapsedTime);
	printf("MaxSubArray: %d \n", maxSubVetor.soma);
}

void max_sub4(int vetor[], int n){
	int vet[n];
	for(int i = 0; i < n; i++){
		vet[i] = vetor[i];
	}
	int soma_inicio = 0, inicio = 0, fim = 0, soma, maxSoma;
	// inicia as somas
	soma = vet[0];
	maxSoma = vet[0];
	struct timeval time1, time2;
    double elapsedTime;
	gettimeofday(&time1, NULL);
	// encontrar o subvetor maximo
	for(int i = 1; i < n; i++){ // inicia em 1 pois as somas já iniciam com a posição 0
		soma += vet[i];
		if(vet[i] > soma){ // testa se o vet[i] é maior que a soma.. se for.. a soma não é a maior soma.. 
			soma = vet[i]; // a maior soma então começa neste valor maior
			soma_inicio = i;
		}
		if(soma > maxSoma){ // testa se a soma é a maior soma
			maxSoma = soma;
			inicio = soma_inicio; // o inicio do subvetor é o inicio da maior soma
			fim = i; // o fim é a ultima posição.. no caso.. a posição atual
		}
	}
	gettimeofday(&time2, NULL);
	elapsedTime = (time2.tv_sec - time1.tv_sec) * 1000.0;      // sec to ms
    elapsedTime += (time2.tv_usec - time1.tv_usec) / 1000.0;   // us to ms

	printf("Dynamic:\n");
	printf("Tempo: %lf ms\n", elapsedTime);
	printf("MaxSubArray: %d \n", maxSoma);
}

char itoc(int i) {
     switch (i) {
            case 0: return '0';
            case 1: return '1';
            case 2: return '2';
            case 3: return '3';
            case 4: return '4';
            case 5: return '5';
            case 6: return '6';
            case 7: return '7';
            case 8: return '8';
            case 9: return '9';
     }
}

void itoa(int i, char s[]) {
    int m10 = 1;
    int qt = 0;
    int n;
    
    while (((int)(i/m10))>0)
        m10 *= 10;

    m10 /= 10;
    
    while (m10>0) {
        n = (int)(i/m10) - ((int)(i/(m10*10))*10);
        s[qt] = itoc(n);
        m10 /= 10;
        qt++;
    }
    s[qt] = '\0';
}



int main(int argc, char *argv[])
{



	for (int j = 2; j < 16; j++)
	{
		FILE *fp;
		char *line = NULL;
		size_t len = 0;
		ssize_t read;
		int i = 0;

		int n = pow(2,j);

		char arquivo[5];
		itoa(n,arquivo);

		fp = fopen(strcat(arquivo,".txt"), "r");
		if (fp == NULL){
			printf("Erro\n");
			exit(EXIT_FAILURE);
		}

		int vet[n];

		while ((read = getline(&line, &len, fp)) != -1)
		{
			vet[i] = atoi(line);
			i++;
		}

		printf("------------------------\nn = %d\n\n",n);


		max_sub1(vet,n);
		printf("\n");
		max_sub2(vet,n);
		printf("\n");
		max_sub3(vet,n);
		printf("\n");
		max_sub4(vet,n);
		printf("\n");
	 
		
	}

	return 0;
}
