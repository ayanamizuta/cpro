#include <vector>
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
