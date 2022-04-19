#include <bits/stdc++.h>
using namespace std;

class Graph{
private:

    int vertices;
    vector<pair<int,int>> adj[6];
    vector<bool> mst =  vector<bool>(6,0);
    vector<int> key =  vector<int>(6,1000);
    

public:

    Graph(int _v){
        vertices = _v;
        key[0]=0;
        
    }

    void addEdge(int from,int to,int wt){
        adj[from].push_back({to,wt});
        adj[to].push_back({from,wt});

    }

    void getMST_prims(){
        int v = vertices;
        int t = 1;
        int min_node = 0;
        int min_val = INT_MAX;
        mst[min_node] = 1;
        key[min_node] = 0;
        int cur = 0;
        vector<int> parent(vertices,-1);        
        for(int z=0;z<vertices-1;z++){            
            
            
            for(int i=0;i<vertices;i++){
                if(mst[i]){
                    for(auto neigh:adj[i]){
                        if(!mst[neigh.first] and neigh.second<min_val){
                            min_val = neigh.second;
                            min_node = neigh.first;
                            cur = i;
                        }
                                                     
                    }
                }
            }
          
          
           mst[min_node] = 1;
           key[min_node] = min_val;
           parent[min_node] = cur;
           min_val = INT_MAX;

        }
        for(int i=0;i<vertices;i++){
            cout<<"parsssent of "<<i<<" -> " <<parent[i]<<endl;
        }
       

    }


};

int main(){
    Graph g(6);
    g.addEdge(0,3,1);
    g.addEdge(0,4,6);
    g.addEdge(0,1,2);


    g.addEdge(1,2,3);
    g.addEdge(1,3,3);
    g.addEdge(1,5,7);

    g.addEdge(2,3,5);
    g.addEdge(2,5,8);

    g.addEdge(3,4,6);



    g.getMST_prims();
}