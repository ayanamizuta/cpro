#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long


class UnionFind{
private:
  std::vector<int> par;
  std::vector<int> rnk;
  std::vector<int> wei;
public:
  UnionFind(int n):par(n),rnk(n),wei(n){
    for(int i=0;i<n;i++){
      par[i]=i;
      rnk[i]=0;
      wei[i]=0;
    }
  }
  
  int find(int x){
    if(par[x] == x)
      return x;
    else
      return find(par[x]);
  }

  void unite(int x,int y,int w){
    x=find(x);
    y=find(y);
    if(x==y)
      return;

    if(rnk[x] < rnk[y])swap(x,y);
    par[y] = x;
    if(rnk[x]==rnk[y]) rnk[x]++;
    wei[y]=w;
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }

  int weight(int x,int y){
    if(x==y)return 0;
    if(rnk[x] < rnk[y])swap(x,y);
    return max(wei[y],weight(x,par[y]));
  }
};

int n,m,q;

int main(){
  cin>>n>>m;
  int a,b;
  UnionFind un(n);
  REP(i,m){
    cin>>a>>b;a--;b--;
    un.unite(a,b,i+1);
  }
  cin>>q;
  REP(i,q){
    cin>>a>>b;a--;b--;
    if(!un.same(a,b))cout<<-1<<endl;
    else{
      cout<<un.weight(a,b)<<endl;
    }
  }
  return 0;
}
