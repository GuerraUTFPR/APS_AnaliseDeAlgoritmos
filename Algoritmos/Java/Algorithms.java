
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
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
            List<Integer> arr = lerArquivo((int) Math.pow(2, ordem));            

            //----------------------------------------------            
            inicio = Calendar.getInstance().getTimeInMillis();
            saida = Enumeration(arr);
            fim = Calendar.getInstance().getTimeInMillis();

            tempo = fim - inicio;

            printar(gravarArq, "Enumeration", tempo, saida);

            //----------------------------------------------
            inicio = Calendar.getInstance().getTimeInMillis();
            saida = BetterEnumeration(arr);
            fim = Calendar.getInstance().getTimeInMillis();

            tempo = fim - inicio;

            printar(gravarArq, "BetterEnumeration", tempo, saida);

            //----------------------------------------------                  
            inicio = Calendar.getInstance().getTimeInMillis();
            saida = divAndConquer(arr, 0, arr.size()-1);
            fim = Calendar.getInstance().getTimeInMillis();

            tempo = fim - inicio;

            printar(gravarArq, "Div and Conquer", tempo, saida);
            
//----------------------------------------------
            inicio = Calendar.getInstance().getTimeInMillis();
            saida = linear(arr);
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
	int aux = 0;

	for(int i = 0; i < A.size(); i++){
            for(int j = i; j < A.size(); j++){
                // Sum for sub-array array[i:j]
                aux = 0;
                for(int k = i; k <= j; k++){
                    aux += A.get(k);
                }
                // Updating max value
                if(aux > max){
                    max = aux;
                }
            }
        }
        
        return max;
    }

    public Integer BetterEnumeration(List<Integer> A) {
        int max = 0;
	int aux = 0;

	for(int i = 0; i < A.size(); i++){
            aux = 0;
            for(int j = i; j < A.size(); j++){
                aux += A.get(j);

                // Updating max value
                if(aux > max) max = aux;
            }
	}

        return max;
    }

    public Integer crossingSum(List<Integer> arr, Integer l, Integer m, Integer h){
        Integer sum = 0;       
        Integer left_sum = -999999999;
        Integer right_sum = -999999999;
        
        for (int i = m; i > l-1; i--) {
            sum = sum + arr.get(i);
            if (sum > left_sum){
                left_sum = sum;
            }
            
        }
        sum = 0;
        for (int i = m+1; i < h+1; i++) {
            sum = sum + arr.get(i);
            if (sum > right_sum){
                right_sum = sum;
            }
        }
        
        
        return left_sum + right_sum;
    }
    
    public Integer divAndConquer(List<Integer> arr, Integer l, Integer h){
        if(l.equals(h)){
            return arr.get(l);
        }
        
        Integer mid = (l+h)/2;
        Integer maximum = Math.max(divAndConquer(arr, l, mid), Math.max(divAndConquer(arr, mid+1, h), crossingSum(arr, l, mid, h)));
        
        return maximum;
    }

    public Integer linear(List<Integer> array) {
        int max_suffix = 0;
	int max_subarray = 0;
	int aux = 0;

	for(int i = 0; i < array.size(); i++){
            // Max suffix i
            aux = max_suffix + array.get(i);
            if(aux > 0){
                max_suffix = aux;
            }
            else{
                max_suffix = 0;
            }

            // Max sub-array i
            if(max_suffix > max_subarray){
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
            FileReader reader = new FileReader("entradasJava.txt");
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
