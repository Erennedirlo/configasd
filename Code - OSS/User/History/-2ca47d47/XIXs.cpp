#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  double fp1=(double)A/B, fp2 = (double)C/D;


  int spent=0;

  if(fp1 > fp2){
    spent+=(N/A)*B;
    N%=A;
    if(((N-1) / C + 1) * D < ((N-1) / A + 1) * B){
      spent+=((N-1) / C + 1) * D;
    }
    else{
      spent+=((N-1) / A + 1) * B;
    }
  }

  else{
    spent+=(N/C)*D;
    spent%=C;
    if(((N-1) / C + 1) * D < ((N-1) / A + 1) * B){
      spent+=((N-1) / C + 1) * D;
    }
    else{
      spent+=((N-1) / A + 1) * B;
    }

  }

  cout<<spent<<"\n";

  return 0;
}
