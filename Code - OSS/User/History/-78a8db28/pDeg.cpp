#include<bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0); ios_base::sync_with_stdio(0);

  int n;
  cin>>n;
  int arr[n+1], container[n];
  memset(container, 0, n);

  int incr=1;
  for(int i=1;i<=n;++i){
    cin>>arr[i];
    container[i]++;
    if(arr[i-1]>arr[i]){
      incr=0;
    }
  }


  if(!incr){
    cout<<-1<<"\n";
    return 0;
  }

  if(arr[0]>=2){
    cout<<-1<<"\n";
    return 0;
  }

  int b[n+1];
  memset(b, 0, n+1);

  for(int i=1;i<=n){

    if(arr[i]==0){
      int num=-1;
      for(int i=1;i<n;++i){
        if(container[i]==0){
          num=container[i];
          break;
        }
      }
      b[i]=num;
    }
    else{
      b[i]=minWrite;
      minWrite=
    }







  }
}