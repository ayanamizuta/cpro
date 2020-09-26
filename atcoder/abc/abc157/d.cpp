#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
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
      
    if(rnk[x] < rnk[y])swap(x,y);
    par[y] = x;
    if(rnk[x]==rnk[y]) rnk[x]++;
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }
};



int n,m,k;
int a[100002],b[100002],c[100002],d[100002],ret[100000],top[100000];

int main(){
  cin>>n>>m>>k;
  UnionFind uf(n);
  REP(i,n)ret[i]=0;
  REP(i,m){
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
    ret[a[i]]--;
    ret[b[i]]--;
    uf.unite(a[i],b[i]);
  }
  REP(i,k){
    cin>>c[i]>>d[i];
    c[i]--;
    d[i]--;
  }
  REP(i,n)top[i]=0;

  

  REP(i,k){
    if(uf.same(c[i],d[i])){
      ret[c[i]]--;
      ret[d[i]]--;
    }
  }
  REP(i,n){
    top[uf.find(i)]++;
  }


  cout << ret[0]+top[uf.find(0)]-1;
  FOR(i,1,n)cout<<" "<<ret[i]+top[uf.find(i)]-1;
  cout<<endl;
  return 0;
}
