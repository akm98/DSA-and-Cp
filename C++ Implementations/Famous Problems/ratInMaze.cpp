#include <bits/stdc++.h>
using namespace std;

vector<string> path;
vector<vector<int>> vis(4,vector<int>(4,0));


void dfs(vector<vector<int>> &m,int i,int j,string p,vector<vector<int>> visi){
        int n = m.size();

        if(visi[i][j] == 1)
            return;
        visi[i][j] =1;
        if(i==n-1 and j==n-1){
            path.push_back(p);
            
        }

        if(i-1>=0 and m[i-1][j]==1) dfs(m,i-1,j,p+'U',visi);
        if(i+1<n and m[i+1][j]==1)  dfs(m,i+1,j,p+'D',visi);
        if(j-1>=0 and m[i][j-1]==1) dfs(m,i,j-1,p+'L',visi);
        if(j+1<n and m[i][j+1]==1)  dfs(m,i,j+1,p+'R',visi);
    }
   
   
    void bfs(vector<vector<int>> &m){
        queue<pair<int,int>> q;
        vector<vector<char>> parent(4,vector<char>(4,'x'));
        int n=4;
        q.push({0,0});
        vis[0][0]=1;
        string p="";
        parent[0][0]='z';
        while(!q.empty()){
            
            auto cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;
               
                if(i-1>=0 and m[i-1][j]==1 and vis[i-1][j]==0){
                    q.push({i-1,j});
                    vis[i-1][j] = 1;
                    p=p+'U';
                    parent[i-1][j] = 'U';
                }
                if(i+1<n and m[i+1][j]==1 and vis[i+1][j]==0){
                    q.push({i+1,j});
                     vis[i+1][j] = 1;
                    p=p+'D';
                     parent[i+1][j] = 'D';
                }

                if(j-1>=0 and m[i][j-1]==1 and vis[i][j-1]==0){
                    q.push({i,j-1});
                     vis[i][j-1] = 1;
                    p=p+'L';
                     parent[i][j-1] = 'L';
                }

                if(j+1<n and m[i][j+1]==1 and vis[i][j+1]==0) {
                    q.push({i,j+1});
                     vis[i][j+1] = 1;
                    p=p+'R';
                     parent[i][j+1] = 'R';
                }
            
        }// D -> R -> X
        int i=3,j=3;
        p="";
        while(parent[i][j]!='z'){
            if(parent[i][j]=='R'){ j=j-1;
                p+='R';
            }
            
            else if(parent[i][j]=='L'){  j = j+1;
                p+='L';
            }

            else if(parent[i][j]=='D'){ i =i-1;
                p+='D';
            }
            else if(parent[i][j]=='U'){ i = i+1;
                p+='U';
            }
        }
        reverse(p.begin(),p.end());
           path.push_back(p);


    }

vector<string> findPath(vector<vector<int>> &m, int n) {
            // Your code goes here
            
            string p ="";
            vector<vector<int>> visi(4,vector<int>(4,0));
            dfs(m,0,0,p,visi);
            //bfs(m);
            return path;
        }

int main(){
    vector<vector<int>> m(5 ,vector<int>(5,0));
    m ={{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1}};
        

    vector<string> ans = findPath(m,5);
    cout<<"---";
    for(auto i:path){
        cout<<i<<endl;
    }
    return 0;

}
    
    
  