// Written by: Erennedirlo, 12/10/2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sayiUlNode, tahammul;
vector<int> sayiUlKedi(100005), komsuUlNode[100005];

int dfs(int a, int denkGeldi) {
  denkGeldi += sayiUlKedi[a];
  if (denkGeldi > tahammul) {
    return 0;
  }
  if (!komsuUlNode[a].size()) {
    return 1;
  }
  
  int sum = 0;
  for (auto u: komsuUlNode[a]) {
    sum += dfs(u, denkGeldi);
  }

  return sum;
} 

int main() {
  cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);
  cin >> sayiUlNode >> tahammul;

  for (int i = 1; i <= sayiUlNode; ++i) {
    cin >> sayiUlKedi[i];
  }

  for (int i = 0; i < sayiUlNode - 1; ++i) {
    int a, b;
    cin >> a >> b;
    komsuUlNode[a].push_back(b);
  }

  cout << dfs(1, sayiUlKedi[1]) << "\n";

  return 0;
}
