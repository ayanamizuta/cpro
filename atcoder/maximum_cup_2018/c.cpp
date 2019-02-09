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

int n;
int a[100000];
LL ret=0,tmp[2];

template <typename T>
bool bipartite_(graph<T> &g, int start, int color){
  if(g.visited[start]!=-1 && g.visited[start]==color)
    return true;
  if(g.visited[start]!=-1)
    return false;
  g.visited[start]=color;
  tmp[color]++;
  bool ret=true;
  for(int i=0;i<g.g[start].size();i++){
    ret = ret & bipartite_(g,g.edges[g.g[start][i]].from ^ g.edges[g.g[start][i]].to ^ start,1-color);
  }
  return ret;
}

template <typename T>
bool bipartite(graph<T> &g){
  bool bl=true;
  for(int i=0;i<g.n;i++){
    if(g.visited[i]>=0)continue;
    tmp[0]=0;tmp[1]=0;
    bl = bl & bipartite_(g,i,0);
    ret+=max(tmp[0],tmp[1]);
  }
  return bl;
}

int main(){
  cin>>n;
  undigraph<int> g(n);
  REP(i,n){
    cin>>a[i];;a[i]--;
    g.add(i,a[i]);
  }
  if(bipartite<int>(g)){
    cout<<ret<<endl;
  }else cout<<-1<<endl;
  return 0;
}
