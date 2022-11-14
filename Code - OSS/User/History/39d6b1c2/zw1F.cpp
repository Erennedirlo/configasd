#include<bits/stdc++.h>
using namespace std;

int findMax(int *arr, int n){
  int maxi=INT_MIN;
  int indofMaxi=-1;

  for(int i=0;i<n;++i){
    if(maxi<arr[0]){
      maxi=arr[i];
      indofMaxi=i;
    }
  }

  arr[indofMaxi]=0;
  return maxi;
}

int main(){
  int a,b,h,w,n;
  cin>>a>>b>>h>>w>>n;

  int arr[n];
  for(int i=0;i<n;++i){
    cin>>arr[i];
  }
  
  int i=0,counter=0;

  while(a>h || b>w && i<n){
    int timesa=a/h, timesb=b/w;
    if(timesa>=timesb){
      h*=findMax(arr, n);
      counter++;
    }
    else{
      w*=findMax(arr, n);
      counter++;
    }
    ++i;
  }

  if(a>h || b>w){
    cout<<-1<<"\n";
  }
  else{
    cout<<counter<<"\n";
  }
  return 0;
}
