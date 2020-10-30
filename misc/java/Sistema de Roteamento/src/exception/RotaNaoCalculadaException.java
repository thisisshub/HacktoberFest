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
package exception;

/**
 * Classe responsável por tratar erro caso o usuário tente finalizar uma rota
 * sem a ter calculado.
 * @author Roberto Maia
 * @author Daniel Dourado
 */
public class RotaNaoCalculadaException extends MinhaException{
    
    public RotaNaoCalculadaException() {
        super("Por favor, calcule a rota antes de finaliza-la.");
    }
    
}
