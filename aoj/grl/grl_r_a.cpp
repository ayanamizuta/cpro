#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

template<const int MAX_V=100000,const int INF = 1000000000>
class Flow {
public:
  struct edge {int to,cap,rev;};

  std::vector<edge> G[MAX_V];
  bool used[MAX_V];

  void add(int from,int to,int cap){
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
  }

  int dfs(int v,int t,int f){
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0){
	int d = dfs(e.to,t,min(f,e.cap));
	if(d>0){
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }

  int max_flow(int s,int t){
    int flow = 0;
    while(true){
      memset(used,0,sizeof(used));
      int f = dfs(s,t,INF);
      if(f == 0)return flow;
      flow+=f;
    }
  }
};

int n,m;

int main(){
  int u,v,c;
  Flow<> g;
  cin>>n>>m;
  REP(i,m){
    cin>>u>>v>>c;
    g.add(u,v,c);
  }
  cout<<g.max_flow(0,n-1)<<endl;
  return 0;
}
