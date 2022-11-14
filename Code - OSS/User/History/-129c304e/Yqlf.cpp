#include<bits/stdc++.h>
#include <ios>
using namespace std;
int main (){
  //ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  
  int t;
  cin>>t;
  while(t--){
    int n,first;
    cin>>n>>first;

    int ans=1;

    while(n>1){
      int tmp;
      cin>>tmp;
      if(tmp%first != 0){
        ans=0;
      }
      --n;
    }
    
    if(ans)
      cout<<"YES"<<"\n";
    else
      cout<<"NO"<<"\n";
  }


  return 0;
}
