#include "DFS.h"
#include <algorithm>

using namespace std;

int maxplays = 5;

Graph::Graph(int V){

	this->V = V;
	adj = new list<int>[V];

}

void Graph::addEdge(int v, int w){

  adj[v].push_back(w);

}


void Graph::DFSaux(int v, bool visited[], int cost){

	if(cost > maxplays){
		return;
	}

  visited[v] = true; //Mark the current node as visited
  cout << v << " ";

  //Recur for all the vertices adjacent to this vertex
	//To link to game -> subst adj by all possible plays
  list<int>::iterator i;
  for(i = adj[v].begin(); i!= adj[v].end(); i++)
      if(!visited[*i])
        DFSaux(*i, visited, cost+1);
}

//Uses DFSaux recursivly

void Graph::DFS(int v){


    //Mark all the vertices as not visited
    bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

    // Call the recursive aux function to print DFS
            DFSaux(v, visited, 1);
}


void Graph::DFSIterative(int v){
	maxplays = 1;

	while(maxplays < 20){ //change to isGoalState if is finish condition
		DFS(v);
		maxplays++;
	}
}
