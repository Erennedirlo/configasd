// Written by: Erennedirlo, 03/10/2022
#include <bits/stdc++.h>
using namespace std;

int main() {
  cout.tie(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;

    string a, b;
    getline(cin >> ws, a);
    getline(cin >> ws, b);

    vector<int> points(n);
    int counter = 0;

    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        points[i] = 1;
        ++counter;
      }
    }

    if (counter % 2) {
      cout << -1 << "\n";
    }
    else {
      int cost = 0;
      sort(points.begin(), points.end());

      for (int i = 0; counter; ++i) {

        if (points[i]) {
          counter--;

          for (int j = i + 1, first = 0; j < n; ++j) {

            if (points[j] && first == 0) {
              first = j;
              if (counter == 1) {
                if (i + 1 == j){
                  cost += x;
                } else {
                  cost += y;
                }
                points[j] = 0;
                break;
                counter--;
              }
            }
            else if (points[j]) {
              cost += y;
              points[j] = 0;
              counter--;
              break;
            }

          }
        }
      }
      cout << cost << "\n";
    }
  }

  return 0;
}
