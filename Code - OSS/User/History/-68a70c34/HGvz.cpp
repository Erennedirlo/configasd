// Written by: Erennedirlo, 20/10/2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> s(100001), dp(100001);

int f(int a, int n) {
  if (a == n - 1) {
    return dp[a] = abs(s[n] - s[a]);
  } else if (a == n) {
    return 0;
  }

  return dp[a] = min(f(a + 1, n) + abs(s[a] - s[a + 1]), f(a + 2, n) + abs(s[a] - s[a + 2]));
}

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }

  cout << f(1, n) << "\n";

  return 0;
}
