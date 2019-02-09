
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


//Unverified
class MinCostFlow {
  struct edge {int to,long long cap,cost;int rev;};
  static const int MAX_V=100000;
  static const int INF = 1000000000;

  int V;
  vector<edge> G[MAX_V];
  int h[MAX_V];
  int dist[MAX_V];
  int prevv[MAX_V],preve[MAX_V];

  void add(int from,int to,long long cap,long long  cost){
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
  }

  long long min_cost_flow(int s,int t,long long f){
    int res = 0;
    fill(h,h+V,0);
    while(f>0){
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
      fill(dist,dist+V,INF);
      dist[s]=0;
      que.push(pair<int,int>(0,s));
      while(!que.empty()){
	pair<int,int> p = que.top();que.pop();
	int v = p.second;
	if(dist[v] < p.first)continue;
	for(int i = 0;i<G[v].size();i++){
	  edge &e = G[v][i];
	  if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
	    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
	    prevv[e.to] = v;
	    preve[e.to] = i;
	    que.push(pair<int,int>(dist[e.to],e.to));
	  }
	}
      }
      if(dist[t] == INF)return -1;
      for(int v = 0;v < V;v++)h[v] += dist[v];
      for(int v = t; v!=s;v=prevv[v]){
	d = min(d,G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * h[t];
      for(int v = t;v!=s;v=prevv[v]){
	edge &e = G[prevv[v]][preve[v]];
	e.cap -= d;
	G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};
