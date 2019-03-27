#include "DFS.h"

using namespace std;

Graph::Graph(int V){

	this->V = V;
	adj = new list<int>[V];

}

void Graph::addEdgeGraph(int v, int w){

  adj[v].push_back(w);

}

void Graph::DFSaux(int v, bool visited[]){

  visited[v] = true; //Mark the current node as visited
  cout << v << " ";

  //Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for(i = adj[v].begin(); i!= adj[v].end(); i++)
      if(!visited[*i])
        DFSaux(*i, visited);
}

//Uses DFSaux recursivly

void Graph::DFS(int v){

    //Mark all the vertices as not visited
    bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

    // Call the recursive aux function to print DFS
            DFSaux(v, visited);
}
