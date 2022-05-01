#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &moves,int row,int col,int count,vector<vector<bool>> vis){
    
    vis[row][col] =1;
    moves[row][col] = count++;
    if(row-2>=0 and col+1<8 and !vis[row-2][col+1])
    dfs(moves,row-2,col+1,count,vis);

    if(row-2>=0 and col-1>=0 and !vis[row-2][col-1])
    dfs(moves,row-2,col-1,count,vis);
   
    if(row-1>=0 and col-2>=0 and !vis[row-1][col-2])
    dfs(moves,row-1,col-2,count,vis);

    if(row+1<8 and col-2>=0 and !vis[row+1][col-2])
    dfs(moves,row+1,col-2,count,vis);

    if(row+2<8 and col-1>=0 and !vis[row+2][col-1])
    dfs(moves,row+2,col-1,count,vis);

    if(row+2<8 and col+1<8 and !vis[row+2][col+1])
    dfs(moves,row+2,col+1,count,vis);

    if(row+1<8 and col+2<8 and !vis[row+1][col+2])
    dfs(moves,row+1,col+2,count,vis);

    if(row-1>=0 and col+2<9 and !vis[row-1][col+2])
    dfs(moves,row-1,col+2,count,vis);

    
}

int main(){
    int n=8;
    vector<vector<int>> moves(8,vector<int>(8));
    vector<vector<bool>> vis(8,vector<bool>(8,false));
    dfs(moves,0,0,0,vis);

    for(auto move:moves){
        for(int i:move){
            if(i>10)
            cout<<i<<" ";
            else
            cout<<i<<"  ";

        }
        cout<<endl;
    }
   



    return 0;
}