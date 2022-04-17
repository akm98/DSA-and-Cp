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

    void addEdge(int to, int from){
        adj[to].push_back(from);
        adj[from].push_back(to);

    }

    

    bool checkCycleUsingBfs(){
        queue<pair<int,int>> q;
        for(int i=1;i<=vertices;i++){
            if(!vis[i]){
                q.push({i,-1});
            }
            while(!q.empty()){
            int cur = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it: adj[cur]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it,cur});                    
                }
                else if(it!=parent) return true; 
                }
            }
        
        }
        
        return false;


    }






    
};



int main(){
    
    Graph g(11);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(5,10);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,8);
    g.addEdge(8,9);
    g.addEdge(8,11);
    g.addEdge(9,10);
    string hasCycle = g.checkCycleUsingBfs()? "contains " : "does not contains ";
    cout<<"The graph "<<hasCycle<<"a cycle";
    return 0;
}