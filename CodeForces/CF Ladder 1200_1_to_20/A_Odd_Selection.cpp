#include <bits/stdc++.h> 
using namespace std;
void solve() {
    int n,x,sum=0;
    cin>>n>>x;
    
    vector<int> a(n);
    int odd_l=0;
    int even_l=0;
    for(int i=0;i<n;i++){
        cin>>a[i];             
        a[i]%2 ? odd_l++ : even_l++;
    }
    
    int i = min(odd_l,x); // 0
    even_l>=x-i && i!=0? cout<<"Yes\n":cout<<"No\n";


}

int main() {
    int tc ;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}

