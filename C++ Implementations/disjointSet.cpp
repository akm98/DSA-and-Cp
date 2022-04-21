#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    int vertices;
    vector<int> rank = vector<int>(8,0);
    vector<int> parent = vector<int>(8,999);
public:
    Graph(int _v){
        vertices = _v;    
        for(int i=1;i<=_v;i++){
            parent[i] = i;
        }
    }

    int findParent(int a){
        int n = a;
        if(parent[a] == a) return a;
        parent[a] = findParent(parent[a]);
        return parent[a];
    }

    void Union(int _a, int _b){
        int a = findParent(_a);
        int b = findParent(_b);

        if(rank[a]>rank[b]){
            parent[b] = a;
        }else if(rank[a]<rank[b]){
            parent[a] = b;
        }else{
            rank[a]++;
            parent[b] = a;
        }
        
    }

   

    vector<int> getParent(){
        return parent;
    }


};

int main(){
    Graph g(7);

    g.Union(1,2);
    g.Union(2,3);
    g.Union(4,5);
    g.Union(6,7);
    g.Union(5,6);
    g.Union(3,7);

    vector<int> parent = g.getParent();

    for(int i=1;i<=7;i++){
        cout<<"parent of "<<i<<" -> "<<parent[i]<<endl;
    }
}