#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;

  while(t--){
    int n,q;
    cin>>n>>q;
    
    vector<int> strength(n+1);

    for(int i=1;i<=n;++i)
      cin>>strength[i];

    while(q--){
      int i,k;
      cin>>i>>k;

      int ans=1;

      for(int j=1;j<=i;++j){
        if(strength[j]>strength[i]){
          ans=0;
          break;
        }
      }
      
      if(ans){
        if(strength[i]==n){
          if(i<=2){
            ans=k;
          }
          else{
            ans=k-2;
          }
        }

        else{
          if(i<=2){
            for(int j=i+1;strength[j]<strength[i];++j, ++ans);
          }
          else{
            if(k<i-1){
              ans=0;
            }
            else{
              for(int j=i+1;strength[j]<strength[i];++j, ++ans);
            }
          }
        }
      }

      cout<<ans<<"\n";
    }

  }

  return 0;
}
