#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
   int vertices ;
   vector<vector<int>> adj;
public:
    Graph(int V){
      vertices = V+1;    
      adj.resize(V+1);   
    }
    void addEdge(int x,int y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool dfsUtil(int cur,int desination, vector<int> &vis){
        if(cur == desination) return true;

        vector<int>:: iterator it;        
        for(it = adj[cur].begin(); it!=adj[cur].end();it++){
            if(!vis[*it]){
                vis[*it] = true;
                bool isConnected = dfsUtil(*it,desination,vis);
                if(isConnected) return true;
            }            
        }
    return false;
    }
    bool dfs(int source,int desination){
        vector<int> vis(vertices+1);
        vis[source] = true;
        return dfsUtil(source,desination,vis);

    }
    void bfs(int source, int destination){
        queue<int> q;

        vector<bool> vis(vertices);
        vector<int> parent(vertices);

        q.push(source);
        parent[source] = -1;

        
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            vis[cur] = true;

            int distance = 0;
            
            if(destination == cur){ 
                int n = destination;   
                string path=to_string(destination);
                  
                while(parent[n]!=-1 ){
                        path += " - ";
                        path +=  to_string(parent[n]);                        
                        n = parent[n];
                        distance++;
                }   
               reverse(path.begin(),path.end());
                cout<<"The shortest path is : "<<path<<" with distance of "<<distance; 
                cout<<endl;
                break;
            }

                        
            for(auto it = adj[cur].begin(); it != adj[cur].end(); it++){
                if(!vis[*it]){
                    q.push(*it);
                    parent[*it] = cur;
                    vis[*it] = true;                   
                }
            }
            
        }
    }


    void showGraph(){
        for(int i=0;i<vertices;i++){
            cout<<"Neighbours of Vertex "<<i<<"->";
            vector<int> :: iterator it;

            for(it = adj[i].begin(); it != adj[i].end(); it++){                
                    cout<<*it<<", ";
            }

            cout<<endl;
        }
    }  
};
int main(){    
    Graph g = Graph(5);
    
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(3,4);
    
    
   
    g.showGraph();  
    g.bfs(1,2);
    g.bfs(1,3);
    g.bfs(1,4);
    g.bfs(1,5);
    string ans = g.dfs(2,5)?"Possible":"Not Possible";
    cout<<"Path is "<<ans;


    return 0;
}