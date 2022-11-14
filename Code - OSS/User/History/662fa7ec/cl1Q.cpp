#include<bits/stdc++.h>
using namespace std;
int nextSquare(int n){
  for(int i=n;;++i){
    int root=sqrt(i);
    if(root*root==i)
      return i;
  }
}

int ans[10001];

void solve(int n){
  if(n<0)
    return;

  int next=nextSquare(n);
  int last=(next-n);

  for(int i=last;i<=n;++i){
    ans[i]=next-i;
  }

  return solve(last-1);
  // 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
  // 4  3  2  1  0 20 19 18 17 16 15 14 13 12 11 10 9  8  7  6  5
}

int main(){
  int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;
    memset(ans, 0, n);
    solve(n-1);

    for(int i=0;i<n;++i)
      cout<<ans[i]<<" ";
    cout<<"\n";
  }

  return 0;
}
