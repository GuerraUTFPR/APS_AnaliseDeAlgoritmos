
import java.util.ArrayList;

/*
Este código tem por objetivo gerar arrays padrão para o teste do algoritmo do subvetor máximo
Disciplina de Análise de Algoritmos
Alunos:
    Elivelton Fernando de Oliveira
    Matheus Sapia Guerra
    Vitor Yudi Shinohara
    Rafael Menezes
Prof. Dr. Rodrigo Campiolo
 */
public class Enumeration {

    public void main(String[] args) {

    }

    public int EnumerationCalc(int[] A) {

        int max_subarray = 0;
        int soma = 0;
        int inicio_indice = 0;
        int fim_indice = 0;

        for (int i = 0; i < A.length; i++) {

            inicio_indice = i;

            for (int j = i; j < A.length; j++) {
                soma += A[j];
                if (soma > max_subarray) {
                    max_subarray = soma;
                    fim_indice = j;
                }

            }
            soma = 0;
        }

        return max_subarray;
        
    }
}
