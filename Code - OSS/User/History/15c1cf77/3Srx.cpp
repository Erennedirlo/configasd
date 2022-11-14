#include<bits/stdc++.h>
using namespace std;

int arr[17][17];
int N;

int solve(int n, int j, int sum, bool checker[17]){
  if(n==2*N){
    return sum;
  }
  if(checker[n]){
    return solve(n+1, n+2, sum, checker);
  }
  if(j == 2*N){
    checker[j]=1;
    return solve(n+1, n+2, sum^arr[n][j], checker);
  }
  else{
    sum = solve(n, j+1, sum, checker);
    checker[j] = 1;
    sum = max(sum, solve(n+1, n+2, sum^arr[n][j], checker));
    return sum;
  }
}

int main(){
  cin>>N;

  for(int i=1;i<=2*N-1;++i){
    for(int j=i+1;j<=2*N;++j){
      cin>>arr[i][j];
    }
  }
  
  bool checker[17] = {false};

  cout<<solve(1, 2, 0, checker)<<"\n";
}
