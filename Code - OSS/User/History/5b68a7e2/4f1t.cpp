// Written by: Erennedirlo, 19/09/2022
#include <bits/stdc++.h>
using namespace std;

int n,k;

int maxof(int *arr, int i){
  int max=arr[i];
  for(int j=i+k;j<n;j+=k){
    if(arr[j]>max) max=arr[j];
  }
  return max;
}

void solve(){
  cin>>n>>k;
  int arr[n];

  for(int i=0;i<n;++i){
    cin>>arr[i];
  }

  int sum=0;

  for(int i=0;i<k;++i){
    sum+=maxof(arr, i);
  }
  
  cout<<sum<<"\n";
}

int main() {
  int t;
  cin>>t;

  while(t--){
    solve();
  }

  return 0;
}
