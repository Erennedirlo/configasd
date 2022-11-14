// Written by: Erennedirlo, 12/10/2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[100005], c(100005), partOf(100005);

void dfs(int a, int mark) {
  if (partOf[a]) {
    return;
  }
  partOf[a] = mark;

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

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b); adj[b].push_back(a);
  }

  int parts = 1;
  
  vector<int> minOfEach(parts + 1);

  for (int i = 1; i <= n; ++i) {
    if(!partOf[i]) {
      dfs(i, parts);
      ++parts;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (minOfEach[partOf[i]] == 0 || minOfEach[partOf[i]] > c[i]) {
      minOfEach[partOf[i]] = c[i];
    }
  }
  
  ll sum = 0;
  for (int i = 1; i < parts; ++i) sum += minOfEach[i];
  
  cout << sum << "\n";
  return 0;
}
