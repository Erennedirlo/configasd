#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
  int n,m;
  cin>>n>>m;

  vector<pair<int,int>> adj[n+1];

  for(int i=0;i<m;++i){
    int a,b,w;
    cin>>a>>b>>w;
    adj[a].push_back(make_pair(b,w));
    adj[b].push_back(make_pair(a,w));
  }

  int startingNode=1;
  int distances[n+1][2];
  for(int i=1;i<=n;++i){
    distances[i][0]=LONG_LONG_MAX;
  }

  distances[startingNode][0]=distances[startingNode][1]=0;

  priority_queue<pair<int,int>> pq;
  bool processed[n+1]={false};

  pq.push(make_pair(0, startingNode));
  while(!pq.empty()){
    int curNode=pq.top().second;
    int curWeight=pq.top().first;
    pq.pop();
    
    if(processed[curNode]) continue;
    processed[curNode]=1;

    for(auto a:adj[curNode]){
      int u=a.first, w=a.second;
      if(distances[curNode][0]+w < distances[u][0]){
        distances[u][0]=distances[curNode][0]+w;
        distances[u][1]=curNode;
        pq.push(make_pair(-distances[u][0], u));
      }
    }
  }
  
  if(distances[n][0]==LONG_LONG_MAX){
    cout<<-1;
  }
  else{
    stack<int> toPrint;
    toPrint.push(n);
    for(int i=n;i!=1;i=distances[i][1]) toPrint.push(distances[i][1]);
  
    while(!toPrint.empty()){ cout<<toPrint.top()<<" "; toPrint.pop();}
  }

  return 0;
}
