// Written by: Erennedirlo, 29/09/2022
#include <bits/stdc++.h>
using namespace std;

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);
  
  int t;

  for (cin >> t; t; --t) {
    int n;
    string s;
    cin >> n >> s;

    if (s[0] != '9') {
      for (int i = 0; i < s.length(); ++i) {
        cout << '9' - s[i];
      }
    }
    else {
      int elde = 0;
      char ans[n + 1];

      for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] != '9') {
          s[i] += elde;
          ans[i] = 11 - s[i] + '0';
        }
        else {
          s[i] = 0;
          ans[i] = '1' + elde;
        }
        elde = 1;
      }

      cout << ans;
    }
    
    cout << "\n";
  }

  return 0;
}
