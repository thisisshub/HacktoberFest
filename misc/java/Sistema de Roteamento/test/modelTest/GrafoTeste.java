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
package modelTest;
import java.io.IOException;
import model.Caminho;
import model.Grafo;
import model.Model;
import model.Vertice;
import org.junit.*;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;


/**
 * @author Daniel Dourado
 * @author Roberto Maia
 */
public class GrafoTeste {
    /**
 * @author Daniel Dourado
 * @author Roberto Maia
 */

    Grafo inicial;
    Grafo resultado;
    Vertice verticeAux1, verticeAux2;

    @Before
    public void setUp() throws IOException {
        inicial = new Grafo();
        resultado = new Grafo();
    }
    @Test
    public void dijkstraTest(){
        
        inicial.addAresta(30,"origem","caminhoMenor");
        inicial.addAresta(50,"origem","caminhoMaior");
        inicial.addAresta(10,"caminhoMenor","destino");
        /*inicial.addAresta(7,"caminhoMenor","caminhoIntermediario");
        inicial.addAresta(2,"caminhoIntermediario","destino");*/
        inicial.addAresta(20,"caminhoMaior","destino");
        verticeAux1 = inicial.acharVertice("origem");
        verticeAux2 = inicial.acharVertice("destino");
        resultado.setVertices(inicial.encontrarMenorCaminhoDijkstra(verticeAux1, verticeAux2));
        
        assertTrue(2==resultado.getArestas().size());//Testa o tamanho do menor caminho
        
        assertTrue(30==resultado.getArestas().get(0).getPeso());//Testa se foi escolhido caminho correto
        assertFalse(50==resultado.getArestas().get(0).getPeso());//Testa se foi escolhido caminho errado
        assertTrue(10==resultado.getArestas().get(1).getPeso());
        assertFalse(20==resultado.getArestas().get(1).getPeso());
        
        
    }
}
