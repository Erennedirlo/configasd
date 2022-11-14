#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int cnt){
  if(cnt<n-1){

    for(int i=n-1;i>cnt;--i){
      if(arr[i]==0){
        sort(arr+i, arr+n);
        return solve(arr, n, cnt+1);
      }
      arr[i]-=arr[i-1];
    }
    
    sort(arr+cnt+1, arr+n);
    return solve(arr, n, cnt+1);
  }
  else if(cnt==n-1){
    return arr[n-1];
  }
}
     
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;++i){
      cin>>arr[i];
    }

    int ans=solve(arr, n, 0);
    cout<<ans<<"\n";
  }
   
  return 0;
}
