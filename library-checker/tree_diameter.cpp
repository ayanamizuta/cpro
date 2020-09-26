#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

vector<vector<pair<int,LL>>> g;
int n;

int dfs(int u, int v, int dist, LL cost) {
  for(auto e : g[v]){
    int w = e.first;
    if(v == w)continue;
    LL cost = e.second;
    auto ret = dfs(u,v,1,cost);
  }
  return ret;
}

int maximal_distance_vertex(int u,bool track) {
  for(auto e : g[u]){
    int v = e.first;
    LL cost = e.second;
    auto ret = dfs(u,v,1,cost);
  }
  return 
}

int main(){
  cin>>n;
  REP(i,n-1){
    int a,b;
    LL c;
    cin>>a>>b>>c;
    g[a].push_back(make_pair(b,c));
    g[b].push_back(make_pair(a,c));
  }

  int u = maximal_distance_vertex(0,false);
  int v = maximal_distance_vertex(u,true);

  cout<<x<<" "<<y<<endl;
  REP(i,track.size()){
    if(i)
      cout<<" "<<track[i];
    else
      cout<<track[i]<<endl;
  }
  return 0;
}
