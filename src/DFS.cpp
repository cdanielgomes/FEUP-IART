#include "DFS.h"
#include <algorithm>

using namespace std;

Graph::Graph(Node n){

	Node * n = new Node();
	adj = n.getState().getAdjacents();

}



void Graph::DFSaux(Node n, bool visited[], int pathCost){

	if(cost > maxplays){
		return;
	}

  visited[n] = true; //Mark the current node as visited
  cout << n << " ";

  //Recur for all the vertices adjacent to this vertex
	//To link to game -> subst adj by all possible plays
  pair<int, int>::iterator i;
  for(i = adj.begin(); i!= adj.end(); i++)
      if(!visited[*i])
        DFSaux(*i, visited, pathCost+1);
}

//Uses DFSaux recursivly

void Graph::DFS(Node n){


    //Mark all the vertices as not visited
    bool *visited = new bool[n];
        for (int i = 0; i < n; i++)
            visited[i] = false;

    // Call the recursive aux function to print DFS
            DFSaux(n, visited, 1);
}


void Graph::DFSIterative(Node n){

	while(!isGoalState(n)){
		DFS(n);
	}
}
