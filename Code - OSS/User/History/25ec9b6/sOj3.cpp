#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
vector<int> colored(100001);

int ctrl = 1;

void bipartite(int a, int color) {
  colored[a] = color;

  for (auto u : adj[a]) {
    if (colored[u] == colored[a]) {
      ctrl = 0;
      return;
    }
    if (colored[u] == 0) {
      bipartite(u, (color == 1 ? 2 : 1));
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  bipartite(1, 1);
  
  for (int i = 1; i <= n; ++i) {
    if (colored[i] == 0) {
      bipartite(i, 1);
    }
  }

  if (ctrl) {
    for (int i = 1; i <= n; ++i) {
      cout << colored[i] << " ";
    }
  } else {
    cout << "IMPOSSIBLE";
  }
  cout << "\n";

  return 0;
}
