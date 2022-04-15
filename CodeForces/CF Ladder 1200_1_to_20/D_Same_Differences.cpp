#include <bits/stdc++.h> 
using namespace std;
int main(){
    int t;
    cin>>t;
   


    while(t--){
        int n;
        cin>>n;
              
        long long res=0;
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            x -=i;
            res+=umap[x];
            umap[x]++;
        }
          
        cout<<res<<endl;
        

    }
}
