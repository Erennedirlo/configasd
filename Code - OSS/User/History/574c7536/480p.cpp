#include<bits/stdc++.h>
using namespace std;

int log10(int a){
  int counter=0;
  while(a>0){ a/=10; counter++;}
  return counter;
}

int main(){
  int n;
  cin>>n;
  
  multiset<int> msa, msb;
  
  for(int i=0;i<n;++i){
    int num;
    cin>>num;
    msa.insert(num);
  }

  for(int i=0;i<n;++i){
    int num;
    cin>>num;
    if(msa.count(num)){
      msa.erase(num);
    }
    else{
      msb.insert(num);
    }
  }
  
  int operations=0;

  for(auto itea=msa.begin(), iteb=msb.begin();msa.size();){
    int testinga=*itea, testingb=*iteb;
    while(*itea != *iteb){
      if(*itea > *iteb){
        msa.insert(log10(*itea));
        msa.erase(*itea);
      }
      else{
        msb.insert(log10(*iteb));
        msb.erase(*iteb);
      }
      operations++;
    }
    msa.erase(*itea);
    msb.erase(*itea);
  }

  cout<<operations<<"\n";

  return 0;
}
