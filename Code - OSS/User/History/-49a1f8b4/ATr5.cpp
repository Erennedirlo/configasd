// Written by: Erennedirlo, 20/09/2022
#include <bits/stdc++.h>
using namespace std;

int log10(int a) {
  int cnt = 0;

  while (a) {
    a /= 10;
    ++cnt;
  }

  return cnt;
}

void solve() {
  int n;
  cin >> n;
  multiset<int> msa, msb;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    msa.insert(tmp);
  }

  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;

    if (msa.count(tmp)) {
      msa.erase(tmp);
    } else {
      msb.insert(tmp);
    }
  }

  int counter = 0;

  cout<<"\n\n"<<*msa.end()<<" "<<*msb.end()<<"\n\n";

  while (*msa.end() > 9 || *msb.end() > 9) {
    int a = *msa.end(), b = *msb.end();
    
    if (a > 9) {
      int save = a;

      while (!msb.count(a)) {
        a = log10(a);
        ++counter;
      }

      msb.erase(a);
      msa.erase(save);
    }

    if (b > 9){
      int save = b;
      
      while(!msa.count(b)){
        b=log10(b);
        ++counter;
      }

      msa.erase(b);
      msb.erase(save);
    }
  }

  for(auto u : msa){
    if(u!=1){
      ++counter;
    }
  }

  for(auto u : msb){
    if(u!=1){
      ++counter;
    }
  }

  cout << counter << "\n";
}

int main() {
  cout.tie(0);
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
