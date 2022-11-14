#include<bits/stdc++.h>
using namespace std;
int arr[3][3];
int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;

  for(int i=0;i<3*n;++i){
    arr[i/n][s[i]-'A']++;
  }

  while(arr[0][0]!=0 || arr[0][1]!=0 || arr[0][2]!=0){
    int firstMax = max(arr[0][0], max(arr[0][1], arr[0][2])), secondMax = max(arr[1][0], max(arr[1][1], arr[1][2])), thirdMax = max(arr[2][0], max(arr[2][1], arr[2][2]));

    if(firstMax == secondMax){
      int ar[3]={arr[1][0], arr[1][1], arr[1][2]}; sort(ar, ar+3); secondMax=ar[1];
    }
    else if(firstMax == thirdMax){
      int ar[3]={arr[2][0], arr[2][1], arr[2][2]}; sort(ar, ar+3); thirdMax=ar[1];
    }
    else if(secondMax == thirdMax){
      int ar[3]={arr[2][0], arr[2][1], arr[2][2]}; sort(ar, ar+3); thirdMax=ar[1];
    }
    
    int limit=min(firstMax, min(secondMax, thirdMax));

    int indexOfA, indexOfB, indexOfC;
    if(firstMax == arr[0][0]) indexOfA=0;
    if(firstMax == arr[0][1]) indexOfA=1;
    if(firstMax == arr[0][2]) indexOfA=2;
    if(secondMax == arr[0][0]) indexOfB=0;
    if(secondMax == arr[0][1]) indexOfB=1;
    if(secondMax == arr[0][2]) indexOfB=2;
    if(thirdMax == arr[0][0]) indexOfC=0;
    if(thirdMax == arr[0][1]) indexOfC=1;
    if(thirdMax == arr[0][2]) indexOfC=2;

    arr[0][indexOfA]-=limit; arr[1][indexOfB]-=limit; arr[2][indexOfC]-=limit;
  }

  return 0;
}
