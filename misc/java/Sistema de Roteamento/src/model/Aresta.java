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
 * Classe responsavel pela implementacao das arestas do grafo
 * @author Daniel Dourado
 * @author Roberto Maia
 */
public class Aresta {

    private int peso;
    private Vertice origem;
    private Vertice destino;
    private boolean visitado = false;
    
    public Aresta(int peso, Vertice origem, Vertice destino) {
        this.peso = peso;
        this.origem = origem;
        this.destino = destino;
    }
    /**
     * Metodo responsavel por dizer se uma aresta foi vizitada ou nao
     * @return true se foi e false caso nao tenha sido
     */
    public boolean isVisitado() {
        return visitado;
    }
    /**
     * Metodo responsavel por alterar o estado "isVisitado" da aresta
     * @param visitado Novo estado de "isVisitado"
     */
    public void setVisitado(boolean visitado) {
        this.visitado = visitado;
    }
    /**
     * Metodo responsavel por retornar o peso da aresta
     * @return Peso da aresta
     */
    public int getPeso() {
        return peso;
    }
    /**
     * Metodo responsavel por alterar o peso da aresta
     * @param peso Novo peso da aresta
     */
    public void setPeso(int peso) {
        this.peso = peso;
    }
    /**
     * Metodo responsavel por retornar a origem da aresta
     * @return Origem da aresta
     */
    public Vertice getOrigem() {
        return origem;
    }
    /**
     * Metodo responsavel por alterar a origem da aresta
     * @param origem 
     */
    public void setOrigem(Vertice origem) {

        this.origem = origem;
    }
    /**
     * Metodo responsavel por retornar o vertice destino da aresta
     * @return 
     */
    public Vertice getDestino() {
        return destino;
    }
    /**
     * Metodo responsavel por alterar o vertice destino da aresta
     * @param destino 
     */
    public void setDestino(Vertice destino) {

        this.destino = destino;
    }

    @Override
    public String toString() {
        String s = " ";
        s += this.getOrigem().getNome() + this.getDestino().getNome();
        return s;
    }

}
