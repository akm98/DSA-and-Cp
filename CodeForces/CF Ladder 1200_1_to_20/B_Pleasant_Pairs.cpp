#include <bits/stdc++.h> 
using namespace std;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    int pairs = 0;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        a[i] = t;
    }
    for(int i=1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(a[i]*a[j] == i+j)
                pairs++;
        }
    }

    cout<<pairs;
}

int main() {
    int tc ;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
        cout<<endl;
    }
    return 0;
}