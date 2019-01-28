#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

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
  int lcan(int x,int y){
    int ret=0;
    if(depth[x]>depth[y])swap(x,y);
    ret+=depth[y]-depth[x];
    for(int i=0;i<VLN;i++){
      if((depth[y]-depth[x])>>i & 1)y=parent[i][y];
    }
    if(x==y)return ret;
    for(int i=VLN-1;i>=0;i--){
      if(parent[i][x]!=parent[i][y]){
	ret+=(1<<i)*2;
	x=parent[i][x];
	y=parent[i][y];
      }
    }
    return ret+2;
  }
};

int n,q;

int main(){
  cin>>n;
  int a,b;
  vector<vector<int>> v(n);
  REP(i,n-1){
    cin>>a>>b;a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  RootedTree<> rt(v);
  cin>>q;
  REP(i,q){
    cin>>a>>b;a--;b--;
    cout<<1+rt.lcan(a,b)<<endl;
  }
  return 0;
}
