#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

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
      
    if(rnk[x] < rnk[y])
      par[x] = y;
    else{
      par[y] = x;
      if(rnk[x]==rnk[y]) rnk[x]++;
    }
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }
};

int n,m;

int main(){
  cin>>n>>m;
  int tmp,tmp2;
  UnionFind un(2*n);
  REP(i,n){
    cin>>tmp;
    un.unite(i,n+tmp-1);
  }
  REP(i,m){
    cin>>tmp>>tmp2;
    un.unite(tmp-1,tmp2-1);
  }
  LL ret=0;
  REP(i,n)ret+=(un.same(i,n+i))?1:0;
  cout<<ret<<endl;
  return 0;
}
