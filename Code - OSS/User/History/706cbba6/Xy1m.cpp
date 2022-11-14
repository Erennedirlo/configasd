#include<bits/stdc++.h>
using namespace std;


int binSearch(int *arr, int value, int l, int m, int r){
  if(arr[m]==value && arr[m+1]!=value){
    return m;
  }

  if(arr[m]!=value){
    return binSearch(arr, value, l, (l+m+1)/2, m);
  }

  else{
    return binSearch(arr, value, m, (r+m+1)/2, r);
  }
}


int main(){
  int t;
  cin>>t;

  while(t--){
    int n,q;
    cin>>n>>q;
    int arr[n+1], maxes[n+1]={0};

    for(int i=1;i<=n;++i){
      cin>>arr[i];
      maxes[i]=max(maxes[i-1], arr[i]);
    }

    while(q--){
      int i,k;
      cin>>i>>k;

      if((i>=2 && k<i-2) || k==0 || arr[i]!=maxes[i]){
        cout<<0<<"\n";
      }

      else{
        int counter=1;
        if(i==1){
          if(arr[2]<arr[1])
            counter=1;
          else
            counter=0;
        }

        counter+=binSearch(maxes, maxes[i], i, (i+n)/2, n) - i;
      }
    }
  }

  return 0;
}
