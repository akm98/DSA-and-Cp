#include <bits/stdc++.h> 
using namespace std;

int main() {
    int tc ;
    cin >> tc;
    while (tc--)
    {
        int n;
        vector<int> mountains;
        cin>>n;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int h;
            cin>>h;
            mountains.push_back(h);
        }
        sort(mountains.begin(),mountains.end());         
        res[0]=mountains[0];
        res[n-1] = mountains[1];
    
        sort(mountains.begin(),mountains.end(), greater<int>());
        for(int i = 1;i<n-1;i++){
            res[i] = mountains[i-1];
        }
        for(auto i:res){
            cout<<i<<" ";
        }
        res.clear();
        mountains.clear();
        cout<<endl;
    }
    
    return 0;
}