import java.util.LinkedList;
import java.util.Queue;

class Graph {

    public static class Vertex {
        public String name;
        public boolean visited;
        public Edge[] vertexLinks;
        public double totalLength;
        public Vertex sourceOfTotalLength;
        @Override
        public String toString() {
            return "name is : " + name + "\nisVisited? " + visited;
        }
    }

    public static class Edge {
        public double weight;
        public Vertex source;
        public Vertex target;
        public Edge(Vertex source, Vertex target, double weight)
        {
            this.source = source;
            this.target = target;
            this.weight = weight;
        }
        @Override
        public String toString() {
            return "source : " + source + "\ndestination : " + target + "\nweight is : " + weight;
        }
    }
    private int lastIndex = 0;
    public Vertex[] vertices;
    public Graph(String[] names)
    {
        vertices = new Vertex[names.length];
        for (String name : names)
        {
            this.vertices[lastIndex] = new Vertex();
            this.vertices[lastIndex].name = name;
            lastIndex++;
        }
    }
    public void AddEdges(int vertexIndex, int[] targets)
    {
        this.vertices[vertexIndex].vertexLinks = new Edge[targets.length];
        for (int i = 0; i < targets.length; i++)
        {
            this.vertices[vertexIndex].vertexLinks[i] =
                new Edge(this.vertices[vertexIndex], 
                        this.vertices[targets[i]], 
                        0);
        }
    }
    public void AddEdges(int vertexIndex, int[] targets, double[] weights)
    {
        this.vertices[vertexIndex].vertexLinks = new Edge[targets.length];
        for (int i = 0; i < targets.length; i++)
        {
            this.vertices[vertexIndex].vertexLinks[i] =
              new Edge(this.vertices[vertexIndex],
              this.vertices[targets[i]],
              weights[i]);
        }
    }

    public void BFS()
    {
        System.out.println("BFS From Graph Class;");
        Queue<Vertex> vertexs = new LinkedList<>();
        vertexs.offer(vertices[0]);
        vertices[0].visited = true;
        Vertex current;
        while (!vertexs.isEmpty()) {
            current = vertexs.poll();
            for (int i = 0; i < current.vertexLinks.length; i++) {
                if (!current.vertexLinks[i].target.visited) {
                    vertexs.offer(current.vertexLinks[i].target);
                    current.vertexLinks[i].target.visited = true;
                    System.out.println("from " + current.name + " to " + current.vertexLinks[i].target.name);
                    System.out.println("-------------------");
                }
            }
        }
        
        RestoreVertices();
    }
    public void DFS(){
        System.out.println("DFS From Graph Class;");
        DFSRecursion(this.vertices[0]);
        RestoreVertices();
      }
      private void DFSRecursion(Vertex current_vertex){
        current_vertex.visited = true;
        Edge[] destinations = current_vertex.vertexLinks;
        for (int i = 0; i < destinations.length; i++)
        {
          if (destinations[i].target.visited == false){
            System.out.println(current_vertex.name + " - "
                                          + destinations[i].target.name);
            DFSRecursion(destinations[i].target);
          }
        }
        
      }
      public void RestoreVertices()
      {
          for (Vertex v : this.vertices)
          {
              v.visited = false;
              v.totalLength = 0;
              v.sourceOfTotalLength = null;
          }
      }
    public void Dijkstra() {
        System.out.println("Dijkstra From Graph Class;");
          for(int i =1; i < this.vertices.length; i++){
            this.vertices[i].totalLength = Double.MAX_VALUE;
          }

          Vertex current_vertex;
          for(int i =0; i < this.vertices.length; i++){
            current_vertex = this.vertices[i];
            Edge[] destinations = current_vertex.vertexLinks;
            if(destinations == null) continue;
            
            Edge current_edge;
            for(int j =0; j < destinations.length; j++){
              current_edge = destinations[j];
              double new_length = current_vertex.totalLength + current_edge.weight;
              if(new_length < current_edge.target.totalLength){
                current_edge.target.totalLength = new_length;
                current_edge.target.sourceOfTotalLength = current_vertex;

              }
            }
            
          }

          String path = this.vertices[this.vertices.length -1].name;
          Vertex v = this.vertices[this.vertices.length -1];
          while(v.sourceOfTotalLength != null){
            path = v.sourceOfTotalLength.name + " - " + path;
            v = v.sourceOfTotalLength;
          }
          System.out.println(this.vertices[this.vertices.length -1].totalLength);
          System.out.println(path);

          this.RestoreVertices();
    }

}
