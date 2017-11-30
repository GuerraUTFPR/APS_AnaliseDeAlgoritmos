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
package Main;
import java.util.Random;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author guerra
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int seed = 24; //define um valor para seed com o intuido de sempre gerar os mesmos arrays
        int n = 1; //declaração da váriavel tamanho
        
        Random generator = new Random(seed); //instancia da classe random passando a seed
        FileWriter arq = null;
        try {
            arq = new FileWriter("/home/guerra/Área de trabalho/UTFPR/Análise de Algoritmos/entradas.txt");
        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
        PrintWriter gravarArq = new PrintWriter(arq);
        
        for (int i = 2; i < 17; i++) { //gerando valores de 2⁰ até 2¹⁶
            n = (int) Math.pow(2,i); //n recebe 2 elevado a i
            gravarArq.printf("n = " + n + "\n"); //grava o valor de n no arquivo
            for (int j = 0; j < n; j++) {
                gravarArq.printf((generator.nextInt(n)-n/2) + " ");//grava o valor aleatorio no arquivo
                
            }
            gravarArq.printf("\n\n"); //pula uma linha
                   
            
        }
        
        try {
            arq.close();
        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
    
}
