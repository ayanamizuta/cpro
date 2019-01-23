#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
LL H;
LL d[100000],h[100000];

int main(){
  cin>>n>>H;
  REP(i,n-1)
    cin>>d[i]>>h[i];

  LL ret=0;
  LL l=H;
  REP(i,n-1){
    if(l>d[i]){
      l-=d[i];
      continue;
    }
    
  }
  cout<<ret<<endl;
  return 0;
}
