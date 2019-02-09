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


int h,w,s,t;
string st[100];

int main(){
  cin>>h>>w;
  Flow g;
  REP(i,h){
    cin>>st[i];
    REP(j,w){
      if(st[i][j]=='S'){s=i*w+j;g.add(0,1+i,g.INF);g.add(0,1+h+j,g.INF);}
      if(st[i][j]=='T'){t=i*w+j;g.add(1+i,1+h+w,g.INF);g.add(1+h+j,1+h+w,g.INF);}
      if(st[i][j]=='o'){g.add(1+i,1+h+j,1);g.add(1+h+j,1+i,1);}
    }
  }
  if((t/w==s/w) || (t%w==s%w)){cout<<-1<<endl;return 0;}
  cout<<g.max_flow(0,1+h+w)<<endl;
  return 0;
}
