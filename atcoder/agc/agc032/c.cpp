#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,m;
vector<vector<int>> g(100000);

int dfs(int a,int b){
  if(g[b].size()==4)return b;
  if(g[b][0]==a)return dfs(b,g[b][1]);
  return dfs(b,g[b][0]);
}

int main(){
  cin>>n>>m;
  int a,b;
  REP(i,m){
    cin>>a>>b;
    a--;b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  bool flag=false;

  vector<int> cros;
  
  REP(i,n){
    if(g[i].size()%2==1){
      cout<<"No"<<endl;
      return 0;
    }
    if(g[i].size()>=6)flag=true;
    if(g[i].size()==4)cros.push_back(i);
  }
  if(flag || cros.size()>2){
    cout<<"Yes"<<endl;
    return 0;
  }

  if(cros.size()<2){
    cout<<"No"<<endl;
    return 0;
  }

  REP(i,4){
    if(dfs(cros[0],g[cros[0]][i])==cros[0]){
      cout<<"Yes"<<endl;
      return 0;
    }
  }

  cout<<"No"<<endl;
  return 0;
}
