#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n;
int col[100000];

void dfs(int v,int c,vector<vector<int>> &g,vector<vector<int>> &w){
  if(col[v] >= 0)return;
  col[v]=c;
  REP(i,g[v].size()){
    dfs(g[v][i],(c+w[v][i])%2,g,w);
  }
}

int main(){
  cin>>n;
  vector<vector<int>> g(n),w(n);
  REP(i,n-1){
    int u,v;
    LL win;
    cin>>u>>v>>win;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
    w[u].push_back((int)(win%2));
    w[v].push_back((int)(win%2));
  }
  REP(i,n)col[i]=-1;

  dfs(0,0,g,w);
  
  REP(i,n){
    cout<<col[i]<<endl;
  }
  return 0;
}
