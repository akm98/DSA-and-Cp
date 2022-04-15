#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int vertices;
    vector<pair<int,int>> adj[100];

public:
    Graph(int V){
        vertices = V;
    }
    void addEdge(int from,int to,int wt){
        adj[from].push_back({to,wt});
    }


    void shortestPath(int source, int destination){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distance(100,INT_MAX);
        distance[source] = 0;
        vector<bool> vis(100);
        pq.push({0,source});
        while(!pq.empty()){

            pair<int,int> node = pq.top();
            int dist = node.first;
            int v = node.second;
            pq.pop();
            if(vis[v]) continue;
            for(auto it: adj[v]){
                int vertex = it.first;
                int wt = it.second;
                if(distance[v] + wt < distance[vertex]){
                     distance[vertex] = distance[v] + wt;
                     pq.push({distance[vertex],vertex});
                }
            }
        }
        
            cout<<"Distance from "<<source<<" to "<<destination<<" is: "<<distance[destination];
        


    }

    
};

int main(){

    Graph g(5);

    g.addEdge(1,2,1);
    g.addEdge(1,3,5);
    g.addEdge(2,3,2);
    g.addEdge(2,4,2);
    g.addEdge(2,5,1);
    g.addEdge(3,5,2);
    g.addEdge(4,5,3);
    g.addEdge(4,6,1);
    g.addEdge(5,6,2);

    g.shortestPath(1,6);







    return 0;
}




