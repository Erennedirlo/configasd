#include <bits/stdc++.h>
using namespace std;
vector<int> c, dp;

int ans = 0;

void f(int n, int cur, int k) {
  for (int i = k; i < c.size(); ++i) {
    if (cur + c[i] <= n) {
      if (cur + c[i] == n) {
        ++ans;
        return;
      }
      f(n, cur + c[i], i);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  
  c.resize(m);
  dp.resize(n + 1);

  for (int i = 0; i < m; ++i) cin >> c[i];
  
  f(n, 0, 0);
  cout << ans << "\n";

  return 0;
}
