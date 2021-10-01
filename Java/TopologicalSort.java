import java.util.HashMap;
import java.util.Map;
import java.util.*;

class Graph {
    private class Node{
        private String label;
        public Node(String label){
            this.label = label;
        }

        @Override
        public String toString(){
            return label;
        }
    }

    private Map<String, Node> nodes = new HashMap<>();
    private Map<Node, List<Node>> adjacencyList = new HashMap<>();

    public void addNode(String label){
        Node node = new Node(label);
        nodes.putIfAbsent(label, node);
        adjacencyList.putIfAbsent(node, new ArrayList<>());
    }

    public void addEdge(String from, String to){
        Node fromNode = nodes.get(from);
        if(fromNode==null)
            throw new IllegalArgumentException();

        Node toNode = nodes.get(to);
        if(toNode == null)
            throw new IllegalStateException();

        adjacencyList.get(fromNode).add(toNode);
    }

    public void print(){
        for(Node source: adjacencyList.keySet()){
            List<Node> targets = adjacencyList.get(source);
            if(!targets.isEmpty()){
                System.out.println(source+" is connected to "+targets);
            }
        }
    }
    public List<String> topologicalSort(String root){
        Stack<Node> stack = new Stack<>();
        Set<Node> visited = new HashSet<>();
        for(Node node: nodes.values())
            topologicalSort(node, visited, stack);
        List<String> sorted = new ArrayList<>();
        while(!stack.isEmpty())
            sorted.add(stack.pop().label);
        return sorted;
    }

    private void topologicalSort(Node root, Set<Node> visited, Stack<Node> stack)
    {
        if(visited.contains(root))
            return;
        visited.add(root);

        for(Node neighbor: adjacencyList.get(root))
            topologicalSort(neighbor, visited, stack);
        stack.push(root);
    }
}
public class TopologicalSort{

    public static void main(String[] args) {
	Graph graph = new Graph();
        graph.addNode("X");
        graph.addNode("A");
        graph.addNode("P");
        graph.addNode("B");

        graph.addEdge("X","A");
        graph.addEdge("X","B");
        graph.addEdge("A","P");
        graph.addEdge("B","P");

        System.out.println(graph.topologicalSort("X"));
	}
}