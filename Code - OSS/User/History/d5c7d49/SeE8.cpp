// Written by: Erennedirlo
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(a, x, n) for (int a = x; a < n; ++a)

int maxEl(vector<int> &v) {
  int maxi = 0;
  for(auto u : v) maxi = max(maxi, u);
  return maxi;
}

unordered_map<int, unordered_map<int, int>> dp;

int f(int l, int r, vector<int> &ctr, int distinct, string &s) {
  if (dp[l][r]) return dp[l][r];

  //if (l == r) return (dp[l][r] = distinct >= maxEl(ctr));
  if (l==r) return 0;
  
  int ret = 0;
  if (distinct >= maxEl(ctr)) {
    ret = 1;
  }

  if (ctr[s[l] - '0'] <= 1) {
    ctr[s[l] - '0']--;
    ret += f(l + 1, r, ctr, distinct - 1, s);
    ctr[s[l] - '0']++;
  } else {
    ctr[s[l] - '0']--;
    ret += f(l + 1, r, ctr, distinct, s);
    ctr[s[l] - '0']++;
  }

  if (ctr[s[r - 1] - '0'] <= 1) {
    ctr[s[r - 1] - '0']--;
    ret += f(l, r - 1, ctr, distinct - 1, s);
    ctr[s[r - 1] - '0']++;
  } else {
    ctr[s[r - 1] - '0']--;
    ret += f(l, r - 1, ctr, distinct, s);
    ctr[s[r - 1] - '0']++;
  }

  return dp[l][r] = ret;
}


int main() {
  cout.tie(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    vector<int> ctr(10);
    int dist = 0;

    loop(i, 0, n) {
      if (ctr[s[i] - '0'] == 0)
        ++dist;
      ++ctr[s[i] - '0'];
    }
   
    cout << f(0, n, ctr, dist, s) << "\n";
    dp.clear();
  }

  return 0;
}
