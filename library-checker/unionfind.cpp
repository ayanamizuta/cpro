#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

//https://judge.yosupo.jp/problem/unionfind
//accepted!

class UnionFind{
private:
  std::vector<int> par;
  std::vector<int> rnk;
public:
  UnionFind(int n):par(n),rnk(n){
    for(int i=0;i<n;i++){
      par[i]=i;
      rnk[i]=0;
    }
  }
  
  int find(int x){
    if(par[x] == x)
      return x;
    else
      return find(par[x]);
  }

  void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)
      return;
      
    if(rnk[x] < rnk[y])swap(x,y);
    par[y] = x;
    if(rnk[x]==rnk[y]) rnk[x]++;
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }
};

int n,q,t,u,v;

int main(){
  cin>>n>>q;
  UnionFind uf(n);
  REP(i,q){
    cin>>t>>u>>v;
    if(t){
      cout<<(uf.same(u,v) ? 1 : 0)<<endl;
    } else {
      uf.unite(u,v);
    }
  }
  return 0;
}
