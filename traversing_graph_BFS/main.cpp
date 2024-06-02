#include<iostream>
#include<list>
#include<iterator>
#include <bits/stdc++.h>

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
       graph[v].push_back(u);
}
    
void BFS(int s, int V,list<int> adj[])
{
    
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++)
            visited[i] = false;
    
            list<int> queue;
    
        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push_back(s);
    
          list<int>::iterator i;
    
         while(!queue.empty())
        {
    
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout <<"\n"<< s << "\n ";
    
            queue.pop_front();
    
             for (i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited[*i]) //check if we have visite this node
                {
    
                     visited[*i] = true;
                    queue.push_back(*i);
    
                }
            }
        }
}
    
    
main(int argc, char* argv[])
{
       int v = 9;    //number of vertices in graph +1
       //create an array of lists whose size is v
       list<int> graph[v];
       insert_edge(graph, 1, 2);
       insert_edge(graph, 1, 3);
       insert_edge(graph, 2, 3);
       insert_edge(graph, 2, 4);
       insert_edge(graph, 2, 5);
       insert_edge(graph, 3, 7);
       insert_edge(graph, 3, 8);
       insert_edge(graph, 3, 5);
       insert_edge(graph, 4, 5);
       insert_edge(graph, 5, 6);
       insert_edge(graph, 7, 8);
    
       displayGraph(graph, v);
       
       //user will give a number to start the bfs
       int x;
       cout<<"Type a number to be the root of the BFS..."<<endl;
       cin>>x;
       cout<<endl;
       
       //BFS function call
       BFS(x, v, graph);
       cout << "\n\n\n";
       
          
}
