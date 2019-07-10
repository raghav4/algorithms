#include<bits/stdc++.h>
using namespace std;
class Graph
{
	public:
	int V;
	list<int>*l;
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}
	void AddEdge(int u, int v, bool direction=true){
		l[u].push_back(v);
		if(direction) 
			l[v].push_back(u);
	}
	// Recursive Traverse Helper function to traverse the graph
	void TraverseHelper(int s, bool *visited){
		cout<<s<<" ";
		visited[s] = true;
		for(int nbr: l[s]){
			if(!visited[nbr]){
				TraverseHelper(nbr,visited);
			}
		}
	}
	// Depth First Traversal (DFS)
	void Traverse(int s){
		bool *visited = new bool[V]{0};
		TraverseHelper(s,visited);
	}
	// Level Order Traversal
	// void BFS(int s){
	// 	queue<int>q;
	// 	bool *visitedInGraph = new bool[V]{0};
	// 	q.push(s);
	// 	visitedInGraph[s] = true;
	// 	while(!q.empty()){
	// 		int ft = q.front();
	// 		q.pop();
	// 		cout<<ft<<" ";
	// 		for(int nbr: l[ft]){
	// 			if(!visitedInGraph[nbr]){
	// 				q.push(nbr);
	// 				visitedInGraph[nbr] = true;
	// 			}
	// 		}
	// 	}
	// }
	void BFS(int s, int d){
		queue<int>q;
		int * dist = new int[V];
		int *whoVisitedThatNode = new int[V];
		for(int i=0;i<V;i++){

			
		}
		bool *visitedInGraph = new bool[V]{0};
		q.push(s);
		visitedInGraph[s] = true;
		while(!q.empty()){
			int ft = q.front();
			q.pop();
			cout<<ft<<" ";
			for(int nbr: l[ft]){
				if(!visitedInGraph[nbr]){
					q.push(nbr);
					visitedInGraph[nbr] = true;
				}
			}
		}
	}
	void PrintAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"--> ";
			for(int n: l[i]){
				cout<<n<<", ";
			}
			cout<<endl;
		}
	}
};
int main(int argc, char const *argv[])
{
	Graph g(5);
	g.AddEdge(0,1);
	g.AddEdge(1,2);
	g.AddEdge(0,2);
	g.AddEdge(2,3);
	g.AddEdge(3,4);
	g.BFS(0);
	//g.Traverse(0);
	//g.PrintAdjList();
	return 0;
}

// Level Order traversal or Breadth First Search in Graph
// Shortest and nearest node : Level order traversal is giving us the shortest path, if we store that path, we will have the shortest path 
// Single Source Shorterst Path