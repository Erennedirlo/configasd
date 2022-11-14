#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  
  while(t--){
    int n,m;
    cin>>n>>m;
    int a[n+1]; 
    for(int i=1;i<=n;++i)
      cin>>a[i];
    
    vector<int> pairs[n+1];
    for(int i=0;i<m;++i){
      int f1,f2;
      cin>>f1>>f2;
      pairs[f1].push_back(f2);
      pairs[f2].push_back(f1);
    }

    int ans=INT_MAX;
    if(m%2==0){
      ans=0;
    }

    else{
      for(int i=1;i<=n;++i){
        if(pairs[i].size()%2){
          ans=min(ans,a[i]);
        }
      }

      for(int i=1;i<=n;++i){
        if(pairs[i].size()%2==0){
          for(auto neighbour:pairs[i]){
            ans=min(ans,a[i]+a[neighbour]);
          }
        }
      }
    }
    cout<<ans<<"\n";
    
  }

  return 0;
}
