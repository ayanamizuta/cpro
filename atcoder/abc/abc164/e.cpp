#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int n,m,s;
vector<vector<vector<int>>> edges; // vertex, cost, time
int c[51],d[51];

LL dist[51][3001];
bool vis[51][3001];
LL ans[51];

int main(){
    cin>>n>>m>>s;
    edges.resize(n);
    REP(i,m){
      int u,v,a,b;
      cin>>u>>v>>a>>b;
      u--;
      v--;
      edges[u].push_back(vector<int>({v,a,b}));
      edges[v].push_back(vector<int>({u,a,b}));
    }
    REP(i,n)cin>>c[i]>>d[i];

    priority_queue<pair<LL,int>,vector<pair<LL,int>>,greater<pair<LL,int>>> que; // time, vertex*5000 + silver

    REP(i,n) REP(j,3001) {dist[i][j]=1e18;vis[i][j]=false;}
    
    REP(i,n+1) ans[i]=1e18;
    chmin(s,3000);
    dist[0][s] = 0;
    que.push({0,0*5000+s});

    while(!que.empty()){
      auto q = que.top(); que.pop();
      auto v=q.second/5000,silver=q.second%5000;
      auto t=q.first;

      if(vis[v][silver])continue;
      vis[v][silver]=true;
      chmin(ans[v],t);

      for(auto e: edges[v]){
        auto v_to = e[0],cost=e[1],time=e[2];
        if(silver<cost)continue;
        if(chmin(dist[v_to][silver-cost],t+time)) que.push({t+time,v_to*5000+silver-cost});
      }

      int s_up = min(silver+c[v],3000);
      if(chmin(dist[v][s_up],t+d[v])) que.push({t+d[v],v*5000+s_up});
    }

    FOR(i,1,n)cout<<ans[i]<<endl;
}