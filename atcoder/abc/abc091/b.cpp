#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n,m;
unordered_map<string,int> mp;

int main(){
  cin>>n;
  string s;
  REP(i,n){
    cin>>s;
    mp[s]++;
  }
  cin>>m;
  REP(i,m){
    cin>>s;
    mp[s]--;
  }
  int ret=0;
  for(auto it:mp){
    ret=max(ret,it.second);
  }
  cout<<ret<<endl;
  return 0;
}
