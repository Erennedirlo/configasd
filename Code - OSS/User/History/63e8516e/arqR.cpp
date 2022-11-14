#include <bits/stdc++.h>
using namespace std;

typedef struct sheet {
  long long x1, x2, y1, y2;
  long long area;
} sheet;

long long intersect(sheet a, sheet b) {
  long long overlapX = max(0LL, min(a.x2, b.x2) - max(a.x1, b.x1));
  long long overlapY = max(0LL, min(a.y2, b.y2) - max(a.y1, b.y1));
  
  return overlapX * overlapY;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  sheet white, b1, b2;
  cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
  cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
  cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;

  white.area = (white.x2 - white.x1) * (white.y2 - white.y1);
  white.area -= intersect(white, b1) + intersect(white, b2) - intersect(b1, b2);

  if (white.area > 0) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }

  return 0;
}
