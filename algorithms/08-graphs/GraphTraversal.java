

public class GraphTraversal {
    public static void main(String[] args) {
        Graph g = new Graph(new String[] { "A", "B", "C", "D", "E", "F", "G", "H", "I" });
        g.AddEdges(0, new int[] { 1, 2 });
        g.AddEdges(1, new int[] { 0, 3, 4 });
        g.AddEdges(2, new int[] { 0, 3, 5 });
        g.AddEdges(3, new int[] { 1, 2, 4 });
        g.AddEdges(4, new int[] { 1, 5 });
        g.AddEdges(5, new int[] { 2, 3, 4, 7 });
        g.AddEdges(6, new int[] { 7, 8 });
        g.AddEdges(7, new int[] { 5, 6, 8 });
        g.AddEdges(8, new int[] { 6, 7 });

      g.BFS();
    }
}
