#include<iostream>
#include<list>
#include<iterator>
#include<vector>

using namespace std;
void displayGraph(list<int> graph[], int v)  // display the Graph
{
   for(int i = 1; i<v; i++) {
      cout << i << "--->";
      list<int> :: iterator it;
      for(it = graph[i].begin(); it != graph[i].end(); ++it) {
         cout << *it << " ";
      }
      cout << endl;
   }
}

void insert_edge(list<int> graph[], int u, int v)  //add vertices (u v), (v u)
{    
   graph[u].push_back(v);
}

//create a function two vectors nodeOutEdges and graphOutEdges
int g (int  v, list<int> graph[])
{
    vector<int> nodeOutEdges;
    vector<int> graphOutEdges;
    list<int> :: iterator t;

    int n=0;
    int i=0;
    
    nodeOutEdges.push_back(1); 
    while (i<v)
    {
        for (i=1; i<v; i++){
            nodeOutEdges.push_back(n);
            for(t=graph[i].begin(); t!=graph[i].end(); t++)
            {graphOutEdges.push_back(*t);}
            
            n=graphOutEdges.size();
        }
    }
    
    nodeOutEdges[0]= n-1;
    cout<<"\n nodeOutEdges: "<<endl;
    for(int i=0; i<nodeOutEdges.size(); i++) 
        cout<< nodeOutEdges[i]<<" ";
    
    cout<<"\n graphOutEdges: "<<endl;
    for(int i=0; i<graphOutEdges.size(); i++) 
        cout<< graphOutEdges[i]<<" ";
}


main(int argc, char* argv[]) 
{
   int v = 9;    //number of vertices in graph +1
   //create an array of lists whose size is v
   list<int> graph[v];
   insert_edge(graph, 1, 2);
   insert_edge(graph, 1, 3);
   insert_edge(graph, 1, 4);
   insert_edge(graph, 1, 5);
   insert_edge(graph, 2, 3);
   insert_edge(graph, 3, 1);
   insert_edge(graph, 3, 5);
   insert_edge(graph, 4, 5);
   insert_edge(graph, 5, 2);
   insert_edge(graph, 6, 7);
   insert_edge(graph, 7, 8);
   insert_edge(graph, 8, 6);
   insert_edge(graph, 8, 7);

   displayGraph(graph, v);
   g(v,graph);
}
