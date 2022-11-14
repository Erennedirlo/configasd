#include<bits/stdc++.h>
using namespace std;

int fact(int a){
  if(a==0){
    return 1;
  }
  
  return a*fact(a-1);
}

int comb(int a, int b){
  return fact(a)/(fact(b)*fact(a-b));
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
    
    int sum=0;

    for(int i=0,isaret=1;i<n;++i,isaret*=-1){
      //sum+=isaret*arr[i]*comb(n,i);
      cout<<isaret<<":"<<arr[i]<<"*"<<comb(n,i)<<":"<<arr[i]*comb(n,i)<<"\n";
    }

    cout<<sum<<"\n";
  }

  return 0;
}
