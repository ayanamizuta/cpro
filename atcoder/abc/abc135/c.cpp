#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n;
LL a[100001];
LL b[100000];

int main(){
  LL ret=0;
  cin>>n;
  REP(i,n+1)cin>>a[i];
  REP(i,n)cin>>b[i];

  REP(i,n){
    LL tmp=min(b[i],a[i]+a[i+1]);
    ret+=tmp;
    a[i+1]-=max(0LL,tmp-a[i]);
  }

  cout<<ret<<endl;
  return 0;
}
