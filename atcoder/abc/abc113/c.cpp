#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n,m;
int p[100000];
vector<vector<LL>> v;
unordered_map<string,int> mp;
int s[100000];
int ret[100000];

int main(){
  cin>>n>>m;
  v.resize(n);
  int pin;
  LL l;
  REP(i,m){
    cin>>pin>>l;
    pin--;
    v[pin].push_back(l);
    mp[to_string(pin)+" "+to_string(l)]=i;
  }
  REP(i,n){
    sort(v[i].begin(),v[i].end());
    REP(j,v[i].size()){
      s[mp[to_string(i)+" "+to_string(v[i][j])]] = i+1;
      ret[mp[to_string(i)+" "+to_string(v[i][j])]] = j+1;
    }
  }
  REP(i,m){
    printf("%06d%06d\n",s[i],ret[i]);
  }
  return 0;
}
