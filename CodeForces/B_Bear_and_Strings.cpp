#include <bits/stdc++.h> 
using namespace std;
int main(){
   string s,temp="";
   cin>>s;
   int l=0,res=0;
   if(s.size()>=4){
    string b = "bear";
    
    bool found=false;

    for(int i=0;i<s.size()-3;i++){
        for(int j=i;j<s.size()-3;j++){
            string g = s.substr(j, 4);
            if(g == b){
                found=true;
                res +=  s.size() - j -  3;
                break;
            }
        }
        found = false;
    }    
   } 
   
   cout<<res;
}
