#include<bits/stdc++.h>
using namespace std;

int solve(int n1, int n2, int k1, int k2, int tk1, int tk2){

  if(tk1>k1 || tk2>k2)
    return 0;
  
  if(n1==0 || n2==0){
    if(n1==0){
      if(n2==0){
        return 1;
      }
      if(tk2<=k2){
        return solve(n1, n2-1, k1, k2, 0, tk2+1);
      }
      else{
        return 0;
      }
    }

    else{
      if(tk1<=k1){
        return solve(n1-1, n2, k1, k2, tk1+1, 0);
      }
      else{
        return 0;
      }
    }
  }

  int k=solve(n1-1, n2, k1, k2, tk1+1, 0);
  int y=solve(n1, n2-1 ,k1, k2, 0, tk2+1);

  return k+y;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n1, n2, k1, k2;
  cin>>n1>>n2>>k1>>k2;
  cout<<solve(n1, n2, k1, k2, 0, 0)<<"\n";
  return 0;
}
