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
      
      if(k<=0){
        cout<<0<<"\n";
        continue;
      }
      if(strength[i]==n){
        if(i<=2)
          counter=k;
        else{
          if(k>=i-2)
          counter=k-i+2;
        }
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
          if(ctrl==2 && k>=i-2)
            counter=1;
          
          if(i<=2){
            counter=0;
            if(i==1 && strength[i]>strength[i+1]){
              counter=1;
            }
            else if(i==2 && strength[i]>strength[i-1]){
              counter=1;
            }
            if(counter){
              k-=1;
              for(int j=3;strength[j]<strength[i] && k>0;--k, ++j, ++counter);
            }
          }
          else{
            for(int j=i+1;k>0 && strength[j]<strength[i];--k, ++j, ++counter);
          }
        }
      }
       
      cout<<counter<<"\n";
    }
  }

  return 0;
}
