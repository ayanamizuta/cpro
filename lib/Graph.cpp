#include <bits/stdc++.h>
 
using namespace std;
 
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
 
template <typename T>
vector <T> dijkstra(const graph<T> &g, int start) {
  assert(0 <= start && start < g.n);
  vector<T> dist(g.n, numeric_limits<T>::max());
  priority_queue<pair<T, int>, vector<pair<T, int> >, greater<pair<T, int> > > s;
  dist[start] = 0;
  s.emplace(dist[start], start);
  while (!s.empty()) {
    int expected = s.top().first;
    int i = s.top().second;
    s.pop();
    if (dist[i] != expected) {
      continue;
    }
    for (int id : g.g[i]) {
      auto &e = g.edges[id];
      int to = e.from ^ e.to ^ i;
      if (dist[i] + e.cost < dist[to]) {
        dist[to] = dist[i] + e.cost;
        s.emplace(dist[to], to);
      }
    }
  }
  return dist;
  // returns numeric_limits<T>::max() if there's no path
}

#define VSIZE 300
#define INF 1e15
long long cost[VSIZE][VSIZE];
template <typename T>
void WarshallFloyd(const undigraph<T> &g, int start) {
  for(int i=0;i<VSIZE;i++){
    for(int j=0;j<VSIZE;j++){
      cost[i][j]=(i==j)?0:INF;
    }
  }
  for(auto &e:g.edges){
    cost[e.from][e.to] = e.cost;
    cost[e.to][e.from] = e.cost;
  }
  for (int k = 0; k <= g.n; k++) { 
    for (int i = 0; i <= g.n; i++) {
      for (int j = 0; j <= g.n; j++) {
        cost[i][j] = min(cost[i][j],cost[i][k] + cost[k][j]);
      }
    }
  }
}

template <typename T>
bool graph::bipartite_(const graph<T> &g, int start, int color){
  if(g.visited[start]!=-1 && g.visited[start]!=color)
    return true;
  if(g.visited[start]!=-1)
    return false;
  g.visited[start]=color;
  bool ret=false;
  for(int i=0;i<g.g[start].size();i++){
    ret = ret | bipartite_(g,g.edges[g.g[start][i]].to,1-color);
  }
  return ret;
}

template <typename T>
bool graph::bipartite(const graph<T> &g){
  bool bl=true;
  for(int i=0;i<g.n;i++){
    if(g.visited[i]>=0)continue;
    bl = bl & bipartite_(g,i,0);
  }
  return bl;
}

template <const int VN=100000,const int VLN=18>
class RootedTree{
public:
  int parent[VLN][VN];
  int depth[VN];
  RootedTree(vector<vector<int>> &G){
    dfs(0,-1,0,G);
    init();
  }
  void dfs(int v,int p,int d,vector<vector<int>> &G){
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<G[v].size();i++){
      if(G[v][i]!=p) dfs(G[v][i],v,d+1,G);
    }
  }

  void init(){
    for(int i=0;i+1<VLN;i++){
      for(int k=0;k<VN;k++){
	if(parent[i][k]<0)parent[i+1][k]=-1;
	else parent[i+1][k] = parent[i][parent[i][k]];
      }
    }
  }
  
  int lca(int x,int y){
    if(depth[x]>depth[y])swap(x,y);
    for(int i=0;i<VLN;i++){
      if((depth[y]-depth[x])>>i & 1)y=parent[i][y];
    }
    if(x==y)return x;
    for(int i=VLN-1;i>=0;i--){
      if(parent[i][x]!=parent[i][y]){
	x=parent[i][x];
	y=parent[i][y];
      }
    }
    return parent[0][x];
  }
};

int main(){
  int n,m,a,b;
  cin>>n>>m;
  undigraph<int> g(n);
  for(int i=0;i<m;i++){
    cin>>a>>b;
    g.add(a,b,1);
  }
  bipartite(g);
  for(int i=0;i<n;i++){
    cerr<<g.visited[i]<<endl;
  }
  return 0;
}
