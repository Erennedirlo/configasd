// Written by: Erennedirlo, 05/10/2022
#include <bits/stdc++.h>
using namespace std;

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

  long long t;

  for(cin >> t; t; --t) {
    long long a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    if (a <= b && a - x >= n) {
      a -= n;
    } else if (b < a && b - y >= n) {
      b -= n;
    } else if (a <= b && a - x < n) {
      n -= a - x;
      a = x;
      b = max(b - n, y);
    } else if (b < a && b - y < n) {
      n -= b - y;
      b = y;
      a = max(a - n, x);
    }

    cout << a * b << "\n";
  }

  return 0;
}
