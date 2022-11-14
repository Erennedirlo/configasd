// Written by: Erennedirlo, 23/10/2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

  int t;
  
  for (cin >> t; t; t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cost = 0;
    int turn = 1;
    
    for (int i = 0; i < n - 1; ++i) {
      if (turn) {
        if (s[i] > s[i + 1]) {
          ++cost;
          turn  = !turn;
        }
      } else {
        if (('1' - s[i]) > ('1' - s[i + 1])) {
          ++cost;
          turn = !turn;
        }
      }
    }

    cout << cost << "\n";
  }

  return 0;
}
