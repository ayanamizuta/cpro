#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

template <typename T>
class graph {
  public:
  struct edge {
    int from;
    int to;
    T cost;
  };
  
  vector <edge> edges;
  vector < vector <int> > g;
  vector <int> visited; // to represent bipartite graph
  int n;
 
  graph(int n) : n(n) {
    g.resize(n);
    visited.resize(n,-1);
  }
 
  virtual void add(int from, int to, T cost = 0){
    assert(0 <= from && from < n && 0 <= to && to < n);
    g[from].push_back(edges.size());
    g[to].push_back(edges.size());
    edges.push_back({from,to,cost});
  }
};
 
template <typename T>
class undigraph : public graph<T> {
  public:
  using graph<T>::edges;
  using graph<T>::g;
  using graph<T>::n;
 
  undigraph(int n) : graph<T>(n) {
  }
 
  void add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    g[from].push_back(edges.size());
    g[to].push_back(edges.size());
    edges.push_back({from, to, cost});
  }
};

class UnionFind{
private:
  std::vector<int> par;
  std::vector<int> rnk;
  std::vector<LL> wei;
public:
  std::vector<LL> cap;
  UnionFind(int n,LL *x):par(n),rnk(n),wei(n),cap(n){
    for(int i=0;i<n;i++){
      par[i]=i;
      rnk[i]=0;
      wei[i]=x[i];
      cap[i]=0;
    }
  }
  
  int find(int x){
    if(par[x] == x)
      return x;
    else
      return find(par[x]);
  }

  LL weight(int x){
    return wei[find(x)];
  }

  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)
      return;
      
    if(rnk[x] < rnk[y])swap(x,y);
    par[y] = x;
    if(rnk[x]==rnk[y]) rnk[x]++;
    wei[x]+=wei[y];
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }

  int capfind(int x){
    if(x==par[x])return cap[x]?x:-1;
    int y = capfind(par[x]);
    if(y!=-1)return y;
    return cap[x]?x:-1;
  }
};

int n,m,acm=0;
bool visited[100000];
LL x[100000];

void solve(int e,LL cost,undigraph<LL> &g){
  acm++;
  visited[e]=true;
  REP(i,g.g[g.edges[e].from].size()){
    if(visited[g.g[g.edges[e].from][i]])continue;
    visited[g.g[g.edges[e].from][i]]=true;
    if(g.edges[g.g[g.edges[e].from][i]].cost<=cost){
      solve(g.g[g.edges[e].from][i],cost,g);
    }
  }
  REP(i,g.g[g.edges[e].to].size()){
    if(visited[g.g[g.edges[e].to][i]])continue;
    visited[g.g[g.edges[e].to][i]]=true;
    if(g.edges[g.g[g.edges[e].to][i]].cost<=cost){
      solve(g.g[g.edges[e].to][i],cost,g);
    }
  }
}

int main(){
  cin>>n>>m;
  REP(i,m)visited[i]=false;
  undigraph<LL> g(n);
  REP(i,n)cin>>x[i];
  LL y;
  int a,b;
  REP(i,m){
    cin>>a>>b>>y;a--;b--;
    g.add(a,b,y);
  }
  vector<int> index(m);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(),[&](int x,int y){return g.edges[x].cost<g.edges[y].cost;});
  UnionFind un(n,x);
  vector<int> v;
  REP(i,m){
    un.unite(g.edges[index[i]].from,g.edges[index[i]].to);
    if(un.weight(g.edges[index[i]].from) >= g.edges[index[i]].cost){
      v.push_back(index[i]);
    }
  }
  REP(i,m){
    int e = index[index.size()-1-i];
    
    if(*lower_bound(v.begin(),v.end(),e)==e&&!visited[e]){solve(e,g.edges[e].cost,g);}
  }
  cout<<m-acm<<endl;
  return 0;
}
