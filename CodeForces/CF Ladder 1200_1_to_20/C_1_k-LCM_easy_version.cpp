#include <bits/stdc++.h> 
using namespace std;
void solve() {
    
    int n,k;
    cin>>n>>k;
    int m = n;
    while(n>0){
        for(int i=n/2;i>0;i--){
            if(i%m==0){
                n-=i;
                cout<<i<<" ";
            }
        }
    }
    cout<<endl;


}

int main() {
    int tc ;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}