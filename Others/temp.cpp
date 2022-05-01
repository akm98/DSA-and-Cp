#include <bits/stdc++.h>
using namespace std;



int main(){
    string a = "aa";
    string b = "bbww";

    a = a+b;

    b = a.substr(0,a.length()-b.length());
    a = a.substr(b.length());

    cout<<a<<"--"<<b;
    return 0;
}