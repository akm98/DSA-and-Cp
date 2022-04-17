#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
   int vertices;
   list<int> adj[12];
   vector<bool> vis =  vector<bool> (100);
   

public:
    Graph(int v){        
        vertices = v;        
    }

    void addEdge(int from, int to){
        adj[from].push_back(to);

    }

    void topologicalSort_BFS(){
      vector<int> indegree(vertices,0);
      vector<int> result;

      for(int i=0; i<vertices; i++){
          for(auto it: adj[i]){
              indegree[it]++;
          }
      }

      queue<int> q;
      for(int i=0;i<vertices;i++){
          if(indegree[i]==0)
            q.push(i);
      }

      while(!q.empty()){
          int cur = q.front();
          q.pop();
          result.push_back(cur);
          for(auto neigh: adj[cur]){
              indegree[neigh]--;
              if(indegree[neigh]==0)
                q.push(neigh);
          }

      }
      for(int i:result){
          cout<<i<<" -> ";
      }
    }
     
     void topologicalSort_DFS(){
         stack<int> st;
         for(int i=0;i<vertices;i++){             
                if(!vis[i]){
                    dfs(i,st);
                }             
       }
       while(!st.empty()){
           cout<<st.top()<<" -> ";
           st.pop();
       }
     }

     void dfs(int node,stack<int> &st){
        vis[node]=1;
        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                dfs(neigh,st);
            }
        }
        st.push(node);
     }
};

int main(){
    // Graph g(6);
    // g.addEdge(0,1);
    // g.addEdge(0,3);
    // g.addEdge(1,2);
    // g.addEdge(1,3);
    // g.addEdge(2,3);
    // g.addEdge(2,4);
    // g.addEdge(3,4);
    // g.addEdge(3,5);
    // g.addEdge(4,5);
    // g.topologicalSort_DFS();
    // cout<<endl;
    Graph g1(6);
    g1.addEdge(2,3);
    g1.addEdge(3,1);
    g1.addEdge(4,0);
    g1.addEdge(4,1);
    g1.addEdge(5,0);
    g1.addEdge(5,2);
    g1.topologicalSort_DFS();
    cout<<endl;
    g1.topologicalSort_BFS();
    
    return 0;

}
