#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i, j, k) for (int i = j; i < k; ++i)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> p(n), sums(n);
  cin >> p[0];
  sums[0] = p[0];
  loop(i, 1, n) {
    cin >> p[i];
    sums[i] += sums[i - 1];
  }

  int ctr = 0;

  loop(i, 0, n) {
    loop(j, i, n) {
      int av;
      if (i == 0) av = sums[j];
      else av = (sums[j] - sums[i - 1]) / (j - i + 1);

      loop(k, i, j + 1) if (p[k] == av) {
        ++ctr;
        break;
      }
    }
  }

  cout << ctr << "\n";

  return 0;
}
