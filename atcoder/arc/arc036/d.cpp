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

int n,q;

int main(){
  cin>>n>>q;
  UnionFind un(2*n);
  int w,x,y,z;
  REP(i,q){
    cin>>w>>x>>y>>z;
    if(w==1){
      if(!(z%2)){un.unite(x-1,y-1);un.unite(n+x-1,n+y-1);}
      else {un.unite(x-1,n+y-1);un.unite(n+x-1,y-1);}
    }else{
      cout<<(un.same(x-1,y-1)?"YES":"NO")<<endl;
    }
  }
  return 0;
}
