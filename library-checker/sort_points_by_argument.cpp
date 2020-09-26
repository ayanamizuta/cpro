#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
vector<pair<LL,LL> > v;

int main(){
  cin>>n;
  REP(i,n){
    LL a,b;
    cin>>a>>b;
    pair<LL, LL> p = make_pair(a,b);
    v.push_back(p);
  }

  sort(ALL(v), [](auto const& ele1, auto const& ele2){
    if(!ele1.second)
      return ele1.first*ele2.second > ele2.first*ele1.second;
  });

  REP(i,n)cout<<v[i].first<<" "<<v[i].second<<endl;
  return 0;
}
