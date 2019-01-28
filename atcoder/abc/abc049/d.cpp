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

int n,k,l;

int main(){
  cin>>n>>k>>l;
  int a,b;
  UnionFind road(n);
  UnionFind train(n);
  unordered_map<string,int> mp;
  
  REP(i,k){
    cin>>a>>b;
    road.unite(a-1,b-1);
  }
  REP(i,l){
    cin>>a>>b;
    train.unite(a-1,b-1);
  }
  REP(i,n)
    mp[to_string(road.find(i))+" "+to_string(train.find(i))]++;
  
  REP(i,n)
    cout<<mp[to_string(road.find(i))+" "+to_string(train.find(i))]<<((i==n-1)?"":" ");
  cout<<endl;
  return 0;
}
