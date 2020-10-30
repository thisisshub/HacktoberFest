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
 * Classe responsável por conter as informações sobre o transporte que será
 * utilizado no sistema.
 * @author Roberto Maia
 * @author Daniel Dourado
 */
public class Transporte {

    double valorCombustivel;
    double custo;
    double consumoKmL;

    public Transporte(double combustivel, double consumo) {
        valorCombustivel = combustivel;
        consumoKmL = consumo;
        custo = 0;
    }

    /**
     * Método responsavel por retornar o valor do combustivel.
     * @return valorCombustivel.
     */
    public double getValorCombustivel() {
        return valorCombustivel;
    }

    /**
     * Método responsável por calcular o custo da viagem.
     * @param distancia
     * @return custo
     */
    public double calcularValor(double distancia) {
        return custo = (distancia/consumoKmL)*valorCombustivel;
    }
    
    /**
     * Método responsável por retornar o consumo de litros por quilometros.
     * @return 
     */
    public double getConsumo() {
        return consumoKmL;
    }
}
