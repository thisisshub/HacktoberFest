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

/**
 * Classe onde estão armazenadas as informações e métodos das arestas.
 * @author Roberto Maia
 * @author Daniel Dourado
 */
public class Caminho {
    Cidade origem;
    Cidade destino;
    int distancia;
    
    public Caminho(Cidade origem, Cidade destino, int peso){
        this.origem = origem;
        this.destino = destino;
        this.distancia = peso;
    }

    /**
     * Método para retornar a coordenada do eixo X da cidade origem.
     * @return x1.
     */
    public int getX1() {
        return origem.getCoordenadaX();
    }

    /**
     * Método para retornar a coordenada do eixo X da cidade destino.
     * @return x2.
     */
    public int getX2() {
        return destino.getCoordenadaX();
    }

    /**
     * Método para retornar a coordenada do eixo Y da cidade origem.
     * @return y1.
     */
    public int getY1() {
        return origem.getCoordenadaY();
    }

    /**
     * Método para retornar a coordenada do eixo Y da cidade destino.
     * @return y2.
     */
    public int getY2() {
        return destino.getCoordenadaY();
    }

    /**
     * Método para retornar a distancia entre as cidades.
     * @return distancia.
     */
    public int getDistancia() {
        return distancia;
    }
    
    /**
     * Método para retorno do objeto cidade origem.
     * @return origem.
     */
    public Cidade getOrigem() {
        return origem;
    }

    /**
     * Método para retorno do objeto cidade destino.
     * @return destino.
     */
    public Cidade getDestino() {
        return destino;
    }
}
