#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    
    int max=INT_MIN;
    int sum=0;

    for(int i=0;i<n;++i){
        if(sum+arr[i] > 0)
        if(sum>max)
            max=sum;
        if(sum+arr[i]<0)
            sum=0;
    }

    cout<<max;

    return 0;
}