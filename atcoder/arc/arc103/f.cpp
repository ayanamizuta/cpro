#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
vector<LL> d,init_d;
vector<LL> ind,width;
vector<pair<int,int>> ans;
vector<vector<int>> tree;

LL dfs(int pos,LL cum){
  LL ret = cum;
  REP(i,tree[pos].size())
    ret += dfs(tree[pos][i],cum+1);
  return ret;
}

int main(){
  cin>>n;
  LL tmp;
  REP(i,n){
    cin>>tmp;
    d.push_back(tmp);
    init_d.push_back(tmp);
  }
  sort(d.begin(),d.end());
  ind.resize(n);
  REP(i,n){
    int min_ind = distance(d.begin(),lower_bound(d.begin(),d.end(),init_d[i]));
    ind[min_ind] = i+1;
  }
  REP(i,n){
    width.push_back(1);
  }
  tree.resize(n);
  REP(i,n-1){
    LL s = d[n-1-i] - (n - 2*width[n-1-i]);
    //cerr<<s<<endl;
    int min_ind2 = distance(d.begin(),lower_bound(d.begin(),d.end(),s));
    if(d[min_ind2] != s || s > d[n-1-i]){
      cout<<-1<<endl;
      return 0;
     }
    ans.push_back(make_pair(min_ind2,n-1-i));
    tree[min_ind2].push_back(n-1-i);
    //tree[n-1-i].push_back(min_ind2);
    width[min_ind2] += width[n-1-i];
  }
  
  if(d[0] != dfs(0,0)){
    cout<<-1<<endl;
    return 0;
  }
  
  REP(i,ans.size())
    cout<<ind[ans[i].first]<<" "<<ind[ans[i].second]<<endl;
  return 0;
}
