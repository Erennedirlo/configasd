// Written by: Erennedirlo, 23/10/2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int gcdOfAll(int n, int a, vector<int> &v) {
  if (a == n) {
    return v[a];
  }

  return __gcd(v[a], gcdOfAll(n, a + 1, v));
}

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

  int t;

  for (cin >> t; t; t--) {
    int n;
    cin >> n;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i) {
      cin >> v[i];
    }
    
    if (gcdOfAll(n, 1, v) == 1) {
      cout << "0" << "\n";
      continue;
    } else {
      int tmp1 = v[n];
      v[n] = __gcd(n, v[n]);
      if (gcdOfAll(n, 1, v) == 1) {
        cout << "1" << "\n";
        continue;
      }
      v[n] = tmp1;
      int tmp2 = v[n - 1];
      v[n - 1] = __gcd(n - 1, v[n - 1]);
      if (gcdOfAll(n, 1, v) == 1) {
        cout << "2" << "\n";
        continue;
      }

      v[n] = __gcd(n, v[n]);

      if (gcdOfAll(n, 1, v) == 1) {
        cout << "3" << "\n";
        continue;
      }
    }
  }

  return 0;
}
