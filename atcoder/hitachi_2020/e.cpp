#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,m;

int p2(int x){
  REP(i,20){
    if(x % (1<<i) != 0)return i-1;
  }
  return 0;
}

int main(){
  cin>>n>>m;
  REP(i,(1<<n)-1){
    REP(j,(1<<m)-1){
      if(p2(i+1)!=0 && p2(i+1) == p2(j+1))cout<<0;
      else cout<<1;
    }
    cout<<endl;
  }
  return 0;
}
