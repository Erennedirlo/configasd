#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;

  int c1, c2, c3, c4;
  c1 = ((n - 1) / a + 1) * b;
  c3 = ((n - 1) / c + 1) * d;

  c2 = (n / a) * b + (((n % a) - 1) / c + 1) * d;
  //if ((n - c) % a == 0 && n-c > 0)
  //  c2 = d + ((n - c) / a) * b;
  
  if((n-c)/a < n/a){
    c2 = d + ((n - c-1) / a+1) * b;
  }

  c4 = (n / c) * d + (((n % c) - 1) / a + 1) * b;
  //if ((n - a) % c == 0 && n-a > 0)
  //  c4 = b + ((n - a) / c) * d;

  if((n-a)/c < n/c){
    c4 = b + ((n - a-1) / c+1) * d;
  }

  cout << min(c1, min(c2, min(c3, c4))) << "\n";

  return 0;
}
