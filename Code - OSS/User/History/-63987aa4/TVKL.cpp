#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[8]={-1, 2, 4, -3, 5, 2, -5, 2};
    int best=INT_MIN;
    int sum=0;

    for(int i=0;i<n;++i){
        sum=max(sum, sum+arr[i]);
        best=max(best, sum);
    }

    cout<<maxi;

    return 0;
}