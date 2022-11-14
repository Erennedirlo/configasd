// Written by: Erennedirlo, 23/09/2022
#include <bits/stdc++.h>
using namespace std;

vector<int> h(100005), required(100005);
int n;

int increased(int a) {
  int sum = 0;
  int maxi = max(h[a-1], h[a+1]);
  if (maxi >= h[a]) {
    return maxi - h[a] + 1;
  } else {
    return 0;
  }
  /*if (h[a] <= h[a - 1]) {
    sum += h[a - 1] - h[a] + 1;
    if ((h[a - 1] + 1 <= h[a + 1])) {
      sum += h[a + 1] - h[a - 1] + 1;
    }
  } else if (h[a] <= h[a + 1]) {
    sum += h[a + 1] - h[a] + 1;
  }*/
}

int dp(int checker, int cur, int sum) {
  if (cur < n - 1) {

    if (checker == 0) {

      if (cur < n - 4) {
        return min(dp(1, cur + 3, sum + required[cur]), dp(0, cur + 2, sum + required[cur]));
      } else {
        return dp(0, cur + 2, sum + required[cur]);
      }

    }

    else {
      return dp(1, cur + 2, sum + required[cur]);
    }

  } else {
    return sum;
  }
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  for (int i = 1; i < n - 1; ++i) {
    required[i] = increased(i);
  }

  if (n % 2) {
    int sum = 0;
    for (int i = 1; i < n - 1; i+=2) {
      sum += required[i];
    }
    cout << sum << "\n";
  } else {
    int sum1 = dp(0, 1, 0);
    int sum2 = dp(0, 2, 0);
    cout << max(sum1, sum2) << "\n";
  }
}

int main() {
  cout.tie(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
