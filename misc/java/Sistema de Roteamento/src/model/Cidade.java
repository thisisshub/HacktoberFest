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
 * Classe responsável por conter as informações das cidades.
 * @author Roberto Maia
 * @author Daniel Dourado
 */
public class Cidade {
    private String nomeCidade;
    private int coordenadaX;
    private int coordenadaY;

    public Cidade(String nomeCidade, String coordenadaX, String coordenadaY) {
        this.nomeCidade = nomeCidade;
        this.coordenadaX = (int) ((Double.parseDouble(coordenadaX)));
        this.coordenadaY = (int) ((Double.parseDouble(coordenadaY)));
    }  

    /**
     * Método responsável por retornar o nome da cidade.
     * @return nomeCidade
     */
    public String getNomeCidade() {
        return nomeCidade;
    }

    /**
     * Método responsável por retornar a coordenada da cidade no eixo X.
     * @return coordenadaX
     */
    public int getCoordenadaX() {
        return coordenadaX;
    }

    /**
     * Método responsável por retornar a coordenada da cidade no eixo Y.
     * @return coordenadaY
     */
    public int getCoordenadaY() {
        return coordenadaY;
    }
    
}
