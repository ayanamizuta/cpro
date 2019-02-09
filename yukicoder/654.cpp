#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

class Flow {
public:
  struct edge {int to;long long cap;int rev;};
  static const int MAX_V=100000;
  static const long long  INF = 1e18;

  std::vector<edge> G[MAX_V];
  bool used[MAX_V];

  void add(int from,int to,long long cap){
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
  }

  long long dfs(int v,int t,long long f){
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0){
	long long d = dfs(e.to,t,min(f,e.cap));
	if(d>0){
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }

  long long max_flow(int s,int t){
    long long flow = 0;
    while(true){
      memset(used,0,sizeof(used));
      long long f = dfs(s,t,INF);
      if(f == 0)return flow;
      flow+=f;
    }
  }
};

int n,m;
LL d;
int offset[1000];

int main(){
  cin>>n>>m>>d;
  Flow g;
  int u,v;
  LL p,q,w;
  vector<vector<tuple<int,int,LL,LL,LL> > > times(n);
  REP(i,m){
    cin>>u>>v>>p>>q>>w;u--;v--;
    times[u].push_back(make_tuple(u,v,p,q,w));
  }
  for_each(times.begin(),times.end(),[](vector<tuple<int,int,LL,LL,LL> > &v){sort(v.begin(),v.end(),[](const tuple<int,int,LL,LL,LL> x,const tuple<int,int,LL,LL,LL> y){return get<2>(x)<get<2>(y);});});
  offset[0]=0;
  REP(i,n-1){
    offset[i+1]=offset[i]+times[i].size();
  }
  REP(i,n-1){
    REP(j,times[i].size()){
      if(j!=times[i].size()-1){
	g.add(offset[i]+j,offset[i]+j+1,g.INF);
	if(get<2>(times[i][j])==get<2>(times[i][j+1]))g.add(offset[i]+j+1,offset[i]+j,g.INF);
      }
      int t = get<1>(times[i][j]);
      int arv = (int)(lower_bound(times[t].begin(),times[t].end(),make_tuple(0,0,d+get<3>(times[i][j]),0LL,0LL),[](const tuple<int,int,LL,LL,LL> x,const tuple<int,int,LL,LL,LL> y){return get<2>(x)<get<2>(y);})-times[t].begin());
      if((t==n-1) || (arv<times[t].size())){
	g.add(offset[i]+j,(t==n-1)?offset[t]:(offset[t]+arv),get<4>(times[i][j]));
      }
    }
  }
  cout<<g.max_flow(0,offset[n-1])<<endl;
  return 0;
}
