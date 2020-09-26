#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

//https://judge.yosupo.jp/problem/associative_array

LL q;
LL n,k,v;

int main(){
  unordered_map<LL,LL> um;
  cin>>q;
  REP(i,q){
    cin>>n;
    if(n){
      cin>>k;
      cout<<um[k]<<endl;
    }else{
      cin>>k>>v;
      um[k]=v;
    }
  }
  return 0;
}
