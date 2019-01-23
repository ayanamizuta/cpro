#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int a[2000];
int n;

int main(){
  cin>>n;
  REP(i,n)
    cin>>a[i];
  bitset<4000000> b;
  b[0]=true;
  LL gr = accumulate(a,a+n,0);
  REP(i,n){
    b|=b<<a[i];
  }
  FOR(i,(gr+1)/2,gr+1){
    if(b[i]){
      cout<<i<<endl;
      break;
    }
  }
  return 0;
}
