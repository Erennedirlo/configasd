#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v, visited;

void dfs(int a, int b, int mark) {
  visited[a][b] = mark;

  if (b - 1 >= 0 && visited[a][b - 1] == 0 && (v[a][b - 1] & 4) == 0) {
    dfs(a, b - 1, mark);
  }
  if ((long unsigned int)(b + 1) < v[0].size() && visited[a][b + 1] == 0 && (v[a][b + 1] & 1) == 0) {
    dfs(a, b + 1, mark);
  }
  if (a - 1 >= 0 && visited[a - 1][b] == 0 && (v[a - 1][b] & 8) == 0) {
    dfs(a - 1, b, mark);
  }
  if ((long unsigned int)(a + 1) < v.size() && visited[a + 1][b] == 0  && (v[a + 1][b] & 2) == 0) {
    dfs(a + 1, b, mark);
  }

  return;
}

int main() {
  int n, m;
  cin >> m >> n;
  
  v.resize(n);
  visited.resize(n);

  for (int i = 0; i < n; ++i) {
    v[i].resize(m);
    visited[i].resize(m);
    for (int j = 0; j < m; ++j) {
      cin >> v[i][j];
    }
  }

  int marker = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (visited[i][j] == 0) {
        dfs(i, j, marker);
        ++marker;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j ){
      cout << visited[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
