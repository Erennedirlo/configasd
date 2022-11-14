// Written by: Erennedirlo, 12/10/2022
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sayiUlNode, tahammul;
vector<int> sayiUlKedi(100005), komsuUlNode[100005], ziyaretEylenmis(100005);

int derinlikEhemmiyetliArama(int a, int denkGeldi) {
  if (ziyaretEylenmis[a]) {
    return 0;
  }
  ziyaretEylenmis[a] = 1;
  denkGeldi += sayiUlKedi[a];
  if (sayiUlKedi[a] == 0) {
    denkGeldi = 0;
  }
  if (denkGeldi > tahammul) {
    return 0;
  }
  if (komsuUlNode[a].size() == 1 && a != 1) {
    return 1;
  }
  
  int sum = 0;
  for (auto u: komsuUlNode[a]) {
    sum += derinlikEhemmiyetliArama(u, denkGeldi);
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
    komsuUlNode[a].push_back(b); komsuUlNode[b].push_back(a);
  }

  cout << derinlikEhemmiyetliArama(1, 0) << "\n";

  return 0;
}
