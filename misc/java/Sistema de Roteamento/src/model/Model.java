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
package model;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 * Classe modelo que faz as implementações lógicas da classe Controller.
 * @author Roberto
 * @author Daniel Dourado
 */
public class Model {

    private Grafo g;
    private Transporte veiculo;

    public Model() {
        g = new Grafo();
        veiculo = new Transporte(3.45, 7.5);

    }

     /**
     * Método responsável pela leitura do arquivo de coordenadas das cidades.
     * @return Array de objetos Cidade.
     * @throws IOException 
     */
    public Cidade[] lerArquivoCidades() throws IOException {
        BufferedReader lerCidades = new BufferedReader(new FileReader("./Coordenadas Cidades.txt"));
        Cidade[] cidades = new Cidade[32];
        String linha = lerCidades.readLine();
        for (int a = 0; a < 32; a++) {
            String[] cidadeCoordenadas = linha.split(";");
            cidades[a] = new Cidade(cidadeCoordenadas[0], cidadeCoordenadas[1], cidadeCoordenadas[2]);
            linha = lerCidades.readLine();
        }
        return cidades;
    }

    /**
     * Método responsável pela leitura do arquivo que contém as vias entre
     * cidades e suas distâncias.
     * @param cidades
     * @return Array de objetos Caminho
     * @throws IOException 
     */
    public Caminho[] lerArquivoDistanciaCidades(Cidade[] cidades) throws IOException {
        BufferedReader lerArestas = new BufferedReader(new FileReader("./Rotas.txt"));
        Caminho[] caminhos = new Caminho[42];
        String linha = lerArestas.readLine();
        for (int a = 0; a < 42; a++) {
            String[] cidadesDistancia = linha.split("-");
            String origem = cidadesDistancia[0];
            String destino = cidadesDistancia[1];
            int peso = (int) Double.parseDouble(cidadesDistancia[2]);
            int i, j;
            for (i = 0; i < cidades.length - 1; i++) {
                if (origem.equalsIgnoreCase(cidades[i].getNomeCidade()) == true) {
                    break;
                }
            }
            for (j = 0; j < cidades.length - 1; j++) {
                if (destino.equalsIgnoreCase(cidades[j].getNomeCidade()) == true) {
                    break;
                }
            }
            caminhos[a] = new Caminho(cidades[i], cidades[j], peso);
            linha = lerArestas.readLine();
        }
        return caminhos;
    }

    /**
     * Método responsável por calcular o menor caminho entre dois Vertices.
     * @param origem
     * @param destino
     * @return ArrayList de Vertices.
     */
    public ArrayList<Vertice> menorCaminho(String origem, String destino) {
        Vertice v1 = g.acharVertice(origem);
        Vertice v2 = g.acharVertice(destino);
        return g.encontrarMenorCaminhoDijkstra(v1, v2);
    }

    /**
     * Método responsável por adicionar as arestas do grafo.
     * @throws IOException 
     */
    public void AddArestas() throws IOException {
        Caminho[] caminhos = this.lerArquivoDistanciaCidades(this.lerArquivoCidades());
        for (Caminho caminho : caminhos) {
            g.addAresta(caminho.distancia, caminho.origem.getNomeCidade(), caminho.destino.getNomeCidade());
        }
    }

    /**
      * Método responsável por calcular o valor que será gasto na viagem.
      * @param distancia
      * @return custo.
      */
    public double calcularValor(double distancia) {
        return veiculo.calcularValor(distancia);
    }
}
