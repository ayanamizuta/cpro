#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

template <typename T>
class WeightedUnionFind{
private:
  std::vector<int> par;
  std::vector<int> rnk;
  std::vector<T> diff;
public:
  WeightedUnionFind(int n):par(n),rnk(n),diff(n){
    for(int i=0;i<n;i++){
      par[i]=i;
      rnk[i]=0;
      diff[i]=0;
    }
  }

  T weight(int x){
    find(x);
    return diff[x];
  }
  
  int find(int x){
    if(par[x] == x)
      return x;
    else{
      int ret = find(par[x]);
      diff[x] += diff[par[x]];
      par[x]=ret;
      return ret;
    }
  }

  void unite(int x,int y,T w){
    w+=weight(x);w-=weight(y);
    x=find(x);
    y=find(y);
    if(x==y)
      return;
      
    if(rnk[x] < rnk[y]) {swap(x,y);w=-w;}
    par[y] = x;
    if(rnk[x]==rnk[y]) rnk[x]++;
    diff[y]=w;
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }
};


int n,m;

int main(){
  cin>>n>>m;
  WeightedUnionFind<LL> wun(n);
  int l,r;
  LL d;
  REP(i,m){
    cin>>l>>r>>d;l--;r--;
    if(wun.same(l,r)&&d!=(wun.weight(r)-wun.weight(l))) {cout<<"No"<<endl;return 0;}
    wun.unite(l,r,d);
  }
  cout<<"Yes"<<endl;
  return 0;
}
