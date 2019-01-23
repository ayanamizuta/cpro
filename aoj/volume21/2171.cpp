#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

#define EPS (1e-8)
template <typename T>
std::vector<T> Gauss_Jordan(const std::vector<vector<T>> &A,const std::vector<T> &b){
  int n=A.size();
  std::vector<vector<T>> B(n,std::vector<T>(n+1));
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)B[i][j]=A[i][j];
  for(int i=0;i<n;i++)B[i][n]=b[i];

  for(int i=0;i<n;i++){
    int pivot=i;
    for(int j=i;j<n;j++){
      if(abs(B[j][i])>abs(B[pivot][i]))pivot=j;
    }
    swap(B[i],B[pivot]);

    if(abs(B[i][i])<EPS)return std::vector<T>();

    for(int j=i+1;j<=n;j++)B[i][j]/=B[i][i];
    for(int j=0;j<n;j++){
      if(i!=j){
	for(int k=i+1;k<=n;k++)B[j][k]-=B[j][i]*B[i][k];
      }
    }
  }
  std::vector<T> x(n);
  for(int i=0;i<n;i++)x[i]=B[i][n];
  return x;
}

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

int n,s,t;
int q[100];
int a[100][100];

int main(){
  while(true){
    cin>>n>>s>>t;
    if(n==0)break;
    s--;
    t--;
    REP(i,n)
      cin>>q[i];
    undigraph<int> g(n);
    REP(i,n){
      REP(j,n){
	cin>>a[i][j];
	if(a[i][j]&& i<j)
	  g.add(i,j,a[i][j]);
      }
    }
    WarshallFloyd(g,0);
    if(cost[s][t]==INF){
      cout<<"impossible"<<endl;
      break;
    }

    vector<int> v;
    REP(i,n){
      if(cost[i][t]!=INF)v.push_back(i);
    }

    undigraph<int> h(v.size());
    REP(i,v.size()){
      if(v[i]==s)s=i;
      if(v[i]==t)t=i;
    }
  
    vector<vector<double>> A(v.size(),vector<double>(v.size()));
    vector<double> b(v.size());
    REP(i,v.size()){
      if(i==t){
	A[i][i]=1;
	b[i]=0;
	continue;
      }
      A[i][i]=-1;
      int den=0;
      if(q[v[i]]){
	REP(j,v.size()){
	  if(a[v[i]][v[j]] && cost[v[i]][v[t]]-cost[v[j]][v[t]]==a[v[i]][v[j]])den++;
	}
	REP(j,v.size()){
	  if(a[v[i]][v[j]] && cost[v[i]][v[t]]-cost[v[j]][v[t]]==a[v[i]][v[j]]){
	    A[i][j]+=1/(double)den;
	    b[i]-=a[v[i]][v[j]]/(double)den;
	  }
	}
      }else{
	REP(j,v.size()){
	  if(a[v[i]][v[j]])den++;
	}
	REP(j,v.size()){
	  if(a[v[i]][v[j]]){
	    A[i][j]+=1/(double)den;
	    b[i]-=a[v[i]][v[j]]/(double)den;
	  }
	}
      }
    }
  
    vector<double> ret=Gauss_Jordan(A,b);
  
    printf("%.10lf\n",ret[s]);
  }
  return 0;
}
