#include<bits/stdc++.h>
#include <climits>
using namespace std;
#define int long long
int32_t main(){
  int n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;

  int mini=((n-1)/a+1)*b;

  for(int i=((n-1)/a+1); i>=0 ; --i){
    int tmp=LONG_LONG_MAX;
    if(i*a < n){
      tmp = (i*b) + ((n-i*a-1)/b+1)*c;
    }
    mini=min(tmp, mini);
  }

  cout<<mini<<"\n";

  return 0;
}
