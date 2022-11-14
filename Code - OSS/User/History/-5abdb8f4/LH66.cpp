// Written by: Erennedirlo, 23/09/2022
#include <bits/stdc++.h>
using namespace std;

vector<int> h(100005);

int increased(int a) {
  int sum = 0;
  if (h[a] <= h[a - 1]) {
    sum += h[a - 1] - h[a] + 1;
    if ((h[a] + h[a - 1] - h[a] + 1) <= h[a + 1]) {
      sum += h[a + 1] - (h[a] + h[a - 1] - h[a] + 1) + 1;
    }
  } else if (h[a] <= h[a + 1]) {
    sum += h[a + 1] - h[a] + 1;
  }
  return sum;
}

int dp(int checker, int index, int size, int sum) {
  if (index < size-1) {
    if (checker) {
      return dp(checker, index + 2, size, sum + increased(h[index]));
    } else {
      if (index < size - 2) {
        return max(dp(1, index + 1, size, sum + increased(h[index])),
                   dp(checker, index + 2, size, sum + increased(h[index])));
        
      } else {
        return dp(checker, index + 2, n, sum + increased(h[index]));
      }
    }
  } else {
    return sum;
  }
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  if (n % 2) {
    int sum = dp(0, 1, n, 0);
    cout << sum << "\n";
  } else {
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i < n - 1; i += 2) {
      sum1 += increased(h[i]);
    }

    for (int i = 2; i < n - 1; i += 2) {
      sum2 += increased(h[i]);
    }

    cout << min(sum1, sum2) << "\n";
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
