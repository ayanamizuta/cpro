#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n,m;
int visited[100000];

void dfs(int v,vector<vector<int>> &g){
  if(visited[v]) return;
  visited[v] = 1;
  REP(i,g[v].size()){
    dfs(g[v][i],g);
  }
}

int main(){
  cin>>n>>m;
  vector<vector<int>> v(n);
  REP(i,m){
    int x,y,z;
    cin>>x>>y>>z;
    x--;y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  REP(i,n)visited[i]=0;
  int cnt=0;
  REP(i,n){
    if(!visited[i]){
      cnt++;
      dfs(i,v);
    }
  }
  cout<<cnt<<endl;
  return 0;
}
