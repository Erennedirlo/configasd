#include<bits/stdc++.h>
using namespace std;

int main(){
//  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin>>t;

  while(t--){
    int n,q;
    cin>>n>>q;

    int strength[n+1];
    for(int i=1;i<=n;++i)
      cin>>strength[i];

    while(q--){
      int i,k,counter=0;
      cin>>i>>k;

      if(strength[i]==n){
        if(i<=2)
          counter=k;
        else
        counter=k-i+2;
      }

      else{
        int ctrl=1;
        for(int j=1;j<i;++j){
          if(strength[j]>strength[i]){
            ctrl=0; break;
          }
          if(j>1){
            ctrl=2;
          }
        }

        if(!ctrl)
          counter=0;

        else{
          if(ctrl==2 && i>=k-2)
            counter=1;
          
          k-=i-2;
          for(int j=i+1;k>0 && strength[j]<strength[i];--k, ++j, ++counter);
        }
      }

      cout<<counter<<"\n";
    }
  }

  return 0;
}
