#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int a) {
  if (visited[a]) {
    return;
  }

  visited[a] = true;

  for (auto u: adj[a]) {
    dfs(u);
  }

  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  
  adj.resize(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  visited.resize(n + 1);
  
  dfs(1);
  
  int parts = 1;
  
  for (int i = 1; i <= n; ++i) {
    if (visited[i] == 0) {
      dfs(i);
      ++parts;
    }
  }
  
  cout << (parts == 1 ? "YES: " : "NO: ") << parts <<  "\n";

  return 0;
}
