// Written by: Erennedirlo, 12/10/2022
#include <bits/stdc++.h>
using namespace std;

vector<int> c(100001), adj[100001], dist(100001);

void dfs (int a, int mark) {
  if (dist[a]) return;
  dist[a] = mark;
  for (auto u: adj[a]) {
    dfs(u, mark);
  }
}

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }

  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int parts = 0;

  for (int i = 1; i <= n; ++i) {
    if (dist[i] == 0) {
      ++parts;
      dfs(i, parts);
    }
  }
  
  long long sum = 0;

  for (int i = 1; i <= parts; ++i) {
    int min = INT_MAX;
    for (int j = 1; j <= n; ++j) {
      if (dist[j] == i && dist[j] < min) {
        min = c[j];
      }
    }
    sum += min;
  }

  cout << sum << "\n";

  return 0;
}
