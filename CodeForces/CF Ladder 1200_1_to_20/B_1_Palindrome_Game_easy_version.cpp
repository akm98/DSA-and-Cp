#include <bits/stdc++.h> 
using namespace std;
void solve() {
    int n;
    cin>>n;
    string S;
    cin>>S;
    int z=0;
    for(char s : S){
        if(s == '0')
            z++;
    }
    if(z%2==0 or z<2)
        cout<<"BOB";
    else
        cout<<"ALICE";
    

    
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