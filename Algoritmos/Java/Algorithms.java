
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.Locale;
import java.util.StringTokenizer;

/*
Este codigo tem por objetivo gerar arrays padrao para o teste do algoritmo do subvetor maximo
Disciplina de Analise de Algoritmos
Alunos:
    Elivelton Fernando de Oliveira
    Matheus Sapia Guerra
    Vitor Yudi Shinohara
    Rafael Menezes
Prof. Dr. Rodrigo Campiolo
 */
public class Algorithms {

    public Algorithms() {

        int ordem = 1;

        FileWriter arq = null;
        try {
            arq = new FileWriter("Saida_Java.txt", true);
        } catch (IOException ex) {
            System.out.println("Erro ao abrir arquivo!");
        }
        PrintWriter gravarArq = new PrintWriter(arq);

        int saida = 0;
        long inicio;
        long fim;
        long tempo;
        while ((ordem++) <= 15) {
            System.out.println("------------------------\n");
            System.out.println("n = " + Math.pow(2, ordem) + "\n\n");
            gravarArq.printf("------------------------\n");
            gravarArq.printf("n = " + Math.pow(2, ordem) + "\n\n");
            

            //----------------------------------------------
            inicio = Calendar.getInstance().getTimeInMillis();

            saida = Enumeration(lerArquivo((int) Math.pow(2, ordem)));

            fim = Calendar.getInstance().getTimeInMillis();

            tempo = fim - inicio;

            printar(gravarArq, "Enumeration", tempo, saida);

            //----------------------------------------------
            inicio = Calendar.getInstance().getTimeInMillis();

            saida = BetterEnumeration(lerArquivo((int) Math.pow(2, ordem)));

            fim = Calendar.getInstance().getTimeInMillis();

            tempo = fim - inicio;

            printar(gravarArq, "BetterEnumeration", tempo, saida);

            //----------------------------------------------
            inicio = Calendar.getInstance().getTimeInMillis();

            saida = divideAndConquer(ordem, lerArquivo((int) Math.pow(2, ordem)));

            fim = Calendar.getInstance().getTimeInMillis();

            tempo = fim - inicio;

            printar(gravarArq, "Div and Conquer", tempo, saida);
//----------------------------------------------

            inicio = Calendar.getInstance().getTimeInMillis();

            saida = linear(ordem, lerArquivo((int) Math.pow(2, ordem)));

            fim = Calendar.getInstance().getTimeInMillis();

            tempo = fim - inicio;

            printar(gravarArq, "Dynamic", tempo, saida);
        }

        try {
            arq.close();
        } catch (IOException ex) {
            System.out.println("Erro ao fechar arquivo!");
        }

    }

    public Integer Enumeration(List<Integer> A) {

        int max = 0;
        int N = A.size();
        int soma = 0;
        
        for (int L = 1; L < N + 1; L++) {
            for (int U = L; U < N + 1; U++) {
                
                soma = 0;
                
                for (int I = L; I < U+1; I++) {
                    
                    soma = soma + A.get(I-1);
                    
                    if (soma > max) {
                        max = soma;
                    }
                    
                }
                
            }
        }
        
        return max;
    }

    public Integer BetterEnumeration(List<Integer> A) {
        Integer max_subarray = 0;
        int soma = 0;
        int index_inicio, index_fim;

        for (int i = 0; i < A.size(); ++i) {
            soma = 0;
            index_inicio = i;

            for (int j = i; j < A.size(); j++) {
                soma += A.get(j);

                if (soma > max_subarray) {
                    max_subarray = soma;
                    index_fim = j;
                }
            }
        }
        return max_subarray;
    }

    public Integer divideAndConquer(int n, List<Integer> vetor) {
        if (n == 1) {
            return vetor.get(0);
        }

        int max = 0;
        int aux = 0;
        int h = n / 2;

        // First half
        aux = divideAndConquer(h, vetor);
        if (aux > max) {
            max = aux;
        }

        // Second half
        aux = divideAndConquer(n - h, vetor.subList(h, vetor.size()));
        if (aux > max) {
            max = aux;
        }

        // Middle
        aux = maxXffix(h, vetor, 0) + maxXffix(n - h, vetor.subList(h, vetor.size()), 1);
        if (aux > max) {
            max = aux;
        }

        return max;
    }

    public Integer maxXffix(int n, List<Integer> array, int pre) {

        int max = 0;
        int aux = 0;

        for (int i = 0; i < n; i++) {
            if (pre != 0) {
                aux += array.get(i);
            } else {
                aux += array.get(n - i - 1);
            }

            // Updating max value
            if (aux > max) {
                max = aux;
            }
        }

        return max;
    }

    public Integer linear(int n, List<Integer> array) {
        int max_suffix = 0;
        Integer max_subarray = 0;
        int aux = 0;

        for (int i = 0; i < n; i++) {
            // Max suffix i
            aux = max_suffix + array.get(i);
            if (aux > 0) {
                max_suffix = aux;
            } else {
                max_suffix = 0;
            }

            // Max sub-array i
            if (max_suffix > max_subarray) {
                max_subarray = max_suffix;
            }

        }

        return max_subarray;
    }

    public void printar(PrintWriter gravarArq, String algoritmo, long tempo, int saida) {
        System.out.println(algoritmo+":");
        System.out.println("Tempo: " + tempo + " ms");
        System.out.println("Max Subarray: " + saida + "\n");
        
        
        gravarArq.printf(algoritmo + ":");
        gravarArq.printf("Tempo: " + tempo + " ms");
        gravarArq.printf("Max Subarray: " + saida + "\n");

    }

    public List<Integer> lerArquivo(int tamVetor) {
        List<Integer> listaEnderecos = new ArrayList<Integer>();
        String linha;

        try {
            FileReader reader = new FileReader("../../entradasJava.txt");
            BufferedReader leitor = new BufferedReader(reader);
            StringTokenizer st = null;
            StringTokenizer st2 = null;

            while ((linha = leitor.readLine()) != null) {
                st = new StringTokenizer(linha);
                if (st.countTokens() == 1 && Integer.parseInt(linha) == tamVetor) {
                    st2 = new StringTokenizer(leitor.readLine(), " ");

                    while (st2.hasMoreTokens()) {
                        listaEnderecos.add(Integer.parseInt(st2.nextToken()));
                    }
                    break;
                }
            }
            reader.close();
        } catch (IOException ex) {
            System.out.println("Erro arquivo!");
        }

        return listaEnderecos;
    }
    
    public static void main(String[] args) {
        new Algorithms();
    }
}
