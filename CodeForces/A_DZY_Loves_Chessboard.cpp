#include <bits/stdc++.h> 
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> board(n , vector<char> (m)) ;
    vector<vector<char>> res(n , vector<char> (m)) ;
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            cin>>board[i][j];
        }        
    }
    bool b,w;
    for(int i=0;i<n;i++){
        if(i%2==0)
            b = true;
        else
            b = false;    
        w = !b;    
        for (int j = 0; j < m; j++)
        {   
            if(b)
                res[i][j] = 'B';
            else
                res[i][j] = 'W';
            b = !b;
            w = !w;
        }        
    }
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            if(board[i][j] == '-')
                res[i][j] = '-';
        }
                 
    }
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            cout<<res[i][j];
        }
            cout<<endl;        
    }
   
     
}