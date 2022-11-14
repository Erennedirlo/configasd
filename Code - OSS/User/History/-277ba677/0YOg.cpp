// Written by: Erennedirlo, 06/10/2022
#include <bits/stdc++.h>
using namespace std;

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);
  
  int t;

  for (cin >> t; t; --t) {
    int n;
    cin >> n;

    int even = 0, odd = 0;

    for (int i = 0; i < n; ++i) {
      int tmp;
      cin >> tmp;
      (tmp % 2) ? (++odd) : (++even);
    }

    if (n == 2) {
      cout << (even ? "Alice" : "Bob") << "\n";
      continue;
    }
    
    int alices = (n + 1) / 2;

    int alicesEven = 0, alicesOdd = 0;

    int ans = 0;
    
    if (even < alices) {
      alicesEven = even;
      alicesOdd = alices - even;
    }
    else {
      alicesEven = alices;
      alicesOdd = 0;
    }

    for (;alicesOdd <= min(odd, alices);) {
      if (alicesOdd % 2) {
        ans = 1;
        break;
      }
      --alicesEven;
      ++alicesOdd;
    }

    cout << (ans ? "Bob" : "Alice") << "\n";
  }

  return 0;
}
