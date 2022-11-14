// Written by: Erennedirlo, 27/10/2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(a, x, n) for (ll a = x; a < n; ++a)
#define mod 1000000007

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

  int c, n;
  cin >> c >> n;
  
  int coins[c];
  int dp[n + 1][c];
  
  loop(i, 0, c) {
    cin >> coins[i];
    dp[0][i] = 1;
  }

  loop(i, 1, n + 1) {
    loop(j, 0, c) {
      ll x = coins[j];
      if (i - x < 0) {
        if (j > 0) {
          dp[i][j] += dp[i][j - 1];
        }
      }

      else {
        dp[i][j] += (j == 0 ? 0 : dp[i][j - 1]) + dp[i - x][j];
      }
    }
  }
  
  cout << dp[n][c - 1] % mod << "\n";

  return 0;
}
