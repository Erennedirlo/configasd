// Written by: Erennedirlo, 20/09/2022
#include <bits/stdc++.h>
using namespace std;

int logon(int a) {
  int cnt = 0;

  while (a) {
    a /= 10;
    ++cnt;
  }

  return cnt;
}

void solve() {
  int n;
  cin >> n;

  set<int> msa, msb;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    msa.insert(tmp);
  }

  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    if (msa.count(tmp)) {
      msa.erase(tmp);
    } else {
      msb.insert(tmp);
    }
  }

  int counter = 0;

  while (!msa.empty()) {
    int a = *msa.rbegin(), b = *msb.rbegin();

    if (a >= b) {
      if (msb.count(logon(a))) {
        msb.erase(logon(a));
        msa.erase(a);
      } else {
        msa.erase(a);
        msa.insert(logon(a));
      }
      ++counter;
    } else {
      if (msa.count(logon(b))) {
        msa.erase(logon(b));
        msb.erase(b);
      } else {
        msb.erase(b);
        msb.insert(logon(b));
      }
      ++counter;
    }
  }

  cout << counter << "\n";
}

int main() {
  //  cout.tie(0);
  //  cin.tie(0);
  //  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
