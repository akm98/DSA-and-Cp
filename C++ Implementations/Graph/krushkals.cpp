#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int vertices;
    vector<pair<int,int>> adj[7];
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; // {wt,{a,b}}
    vector<int> parent = vector<int>(7);
    vector<int> rank = vector<int>(7,0);

    int mst_wt =0;
    
public:
    Graph(int _v){
        vertices = _v;        
    }

    void addEdge(int a, int b,int wt){
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
        pq.push({wt,{a,b}});
    }

    int findParent(int a){
        if(parent[a] == a) return a;
        //parent[a] = findParent(parent[a]);
        return findParent(parent[a]);
    }



    vector<pair<int,int>> kruskal(){
        vector<pair<int,int>> mst;
        for(int i=1;i<vertices;i++) parent[i] =i;
        
        while(!pq.empty()){
            int min_wt = pq.top().first;
            int _a = pq.top().second.first;
            int _b = pq.top().second.second;

            int a = findParent(_a);
            int b = findParent(_b);

            if(a!=b){
                if(rank[a]>rank[b]) {
                    parent[b] = a;
                    
                }
                if(rank[a]<rank[b]) {
                    parent[a] = b;
                    
                }
                else{
                    parent[b] = a;
                    rank[a]++;
                }
                mst_wt+=min_wt;
                mst.push_back({_a,_b});
                
            }
            pq.pop();

        }

        return mst;

    }

    int getMSTcost(){
        return mst_wt;
    }
};
int main(){
    Graph g(7);
    g.addEdge(1,2,2);
    g.addEdge(1,4,1);
    g.addEdge(1,5,4);
    g.addEdge(2,3,3);
    g.addEdge(2,6,7);
    g.addEdge(2,4,3);
    g.addEdge(3,4,5);
    g.addEdge(3,6,8);
    g.addEdge(4,5,9);

    // g.addEdge(0,1,2);
	// g.addEdge(0,3,6);
	// g.addEdge(1,0,2);
	// g.addEdge(1,2,3);
	// g.addEdge(1,3,8);
	// g.addEdge(1,4,5);
	// g.addEdge(2,1,3);
	// g.addEdge(2,4,7);
	// g.addEdge(3,0,6);
	// g.addEdge(3,1,8);
	// g.addEdge(4,1,5);
	// g.addEdge(4,2,7);

    vector<pair<int,int>> mst = g.kruskal();

   for(auto it:mst){
       cout<<it.first<<" - "<<it.second<<endl;
   }

    cout<<"MST cost :"<<g.getMSTcost();


    return 0;

}