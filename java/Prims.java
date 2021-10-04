//srishti1302
import java.util.*;

class Prims {
	
	 static int V ;

	int minKey(int key[], Boolean mstSet[])
	{
		
		int min = Integer.MAX_VALUE, min_index = -1;

		for (int v = 0; v < V; v++)
			if (mstSet[v] == false && key[v] < min) {
				min = key[v];
				min_index = v;
			}

		return min_index;
	}

	// A utility function to print the constructed MST stored in
	// parent[]
	void printMST(int parent[], int graph[][])
	{
		System.out.println("Edge \tWeight");
		for (int i = 1; i < V; i++)
			System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
	}

	// Function to construct and print MST for a graph represented
	// using adjacency matrix representation
	void primMST(int graph[][])
	{
		// Array to store constructed MST
		int parent[] = new int[V];

		// Key values used to pick minimum weight edge in cut
		int key[] = new int[V];

		// To represent set of vertices included in MST
		Boolean mstSet[] = new Boolean[V];

		// Initialize all keys as INFINITE
		for (int i = 0; i < V; i++) {
			key[i] = Integer.MAX_VALUE;
			mstSet[i] = false;
		}

		// Always include first 1st vertex in MST.
		key[0] = 0; // Make key 0 so that this vertex is
		// picked as first vertex
		parent[0] = -1; // First node is always root of MST

		// The MST will have V vertices
		for (int count = 0; count < V - 1; count++) {
			// Pick thd minimum key vertex from the set of vertices
			// not yet included in MST
			int u = minKey(key, mstSet);

			// Add the picked vertex to the MST Set
			mstSet[u] = true;

			// Update key value and parent index of the adjacent
			// vertices of the picked vertex. Consider only those
			// vertices which are not yet included in MST
			for (int v = 0; v < V; v++)

				if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v]) {
					parent[v] = u;
					key[v] = graph[u][v];
				}
		}

		// print the constructed MST
		printMST(parent, graph);
	}

	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		int v=s.nextInt();
		int e=s.nextInt();
		Prims t = new Prims();
		V=v;
		int graph[][] = new int[v][v];
		//Arrays.fill(graph, 0);
		for(int i=0;i<e;) {
			System.out.println("Enter "+ ++i+" edge source n destination n weight");
			int src=s.nextInt();
			int dest=s.nextInt();
			graph[src][dest]=s.nextInt();
			graph[dest][src]=graph[src][dest];
		}
		
		
		t.primMST(graph);
		s.close();
	}
}
