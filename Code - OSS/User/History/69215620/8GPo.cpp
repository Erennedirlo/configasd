#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<tuple<int,int,int>> graph;
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=0;i<m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        graph.push_back(make_tuple<a,b,c>);
    }

    return 0;
}