/**
 * Componente Curricular: Módulo Integrado de Programação II
 * Autor: <Roberto Maia Rodrigues Junior e Daniel Cavalcante Dourado>
 * Data:  <07/02/2019>
 *
 * Declaro que este código foi elaborado por mim de forma individual e
 * não contém nenhum trecho de código de outro colega ou de outro autor, 
 * tais como provindos de livros e apostilas, e páginas ou documentos 
 * eletrônicos da Internet. Qualquer trecho de código de outra autoria que
 * uma citação para o  não a minha está destacado com  autor e a fonte do
 * código, e estou ciente que estes trechos não serão considerados para fins
 * de avaliação. Alguns trechos do código podem coincidir com de outros
 * colegas pois estes foram discutidos em sessões tutorias.
 */
package controller;

import java.io.IOException;
import java.util.ArrayList;
import model.Caminho;
import model.Cidade;
import model.Model;
import model.Vertice;

/**
 * Controller do programa que gerencia os métodos da Classe Model.
 * @author Daniel Dourado
 * @author Roberto Maia
 */
public class Controller {
    private Model m;
    
    public Controller(){
        m = new Model();
    }
    
    /**
     * Método responsável pela leitura do arquivo de coordenadas das cidades.
     * @return Array de objetos Cidade.
     * @throws IOException 
     */
    public Cidade[] lerArquivoCidades() throws IOException{
        return m.lerArquivoCidades();
    }
    
    /**
     * Método responsável pela leitura do arquivo que contém as vias entre
     * cidades e suas distâncias.
     * @param cidades
     * @return Array de objetos Caminho
     * @throws IOException 
     */
    public Caminho[] lerArquivoDistanciaCidades(Cidade[] cidades) throws IOException {
        return m.lerArquivoDistanciaCidades(cidades);
    }
    
    /**
     * Método responsável por calcular o menor caminho entre dois Vertices.
     * @param origem
     * @param destino
     * @return ArrayList de Vertices.
     */
    public ArrayList<Vertice> menorCaminho(String origem, String destino) {
        return m.menorCaminho(origem, destino);
    }
    
    /**
     * Método responsável por adicionar as arestas do grafo.
     * @throws IOException 
     */
     public void AddArestas() throws IOException {
         m.AddArestas();
     }
     
     /**
      * Método responsável por calcular o valor que será gasto na viagem.
      * @param distancia
      * @return custo.
      */
     public double calcularValor( double distancia){
         return m.calcularValor(distancia);
     }
}
