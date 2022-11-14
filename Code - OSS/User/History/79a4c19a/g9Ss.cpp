#include<bits/stdc++.h>
using namespace std;

int solve(int n1, int n2, int k1, int k2, int tk1, int tk2){

  if(n1==0 || n2==0){
    if(n1==0){
      if(n2==0){
        return 0;
      }
      else{
        if(tk2>k2){
          return -1;
        }
          return solve(n1, n2-1, k1, k2, 0, tk2+1)+1;
      }
    }
    else{
      if(tk1>k1){
        return -1;
      }
      return solve(n1-1, n2, k1, k2, tk1+1, 0)+1;
    }
  }

  if(tk1<k1){
    if(tk2<k2){
      int k,y;
      if(n1>=1)
        k=solve(n1-1, n2, k1, k2, tk1+1, 0);
      if(n2>=1)
        y=solve(n1, n2-1, k1, k2, 0, tk2+1);
      return k+y+2;
    }

    else{
      return solve(n1-1, n2, k1, k2, tk1+1, 0)+1;
    }
  }

  if(tk2<k2){
    return solve(n1, n2-1, k1, k2, 0, tk2+1)+1;
  }

  return -1;
}

int main(){
  int n1, n2, k1, k2;
  cin>>n1>>n2>>k1>>k2;
  cout<<solve(n1, n2, k1, k2, 0, 0)<<"\n";
  return 0;
}
