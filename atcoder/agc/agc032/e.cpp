#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
LL m;
LL a[200000];

bool ok(int x){
  FOR(i,x,n){
    if(a[x+i]+a[2*n-1-(i-x)]<m)return false;
  }
  return true;
}

int main(){
  cin>>n>>m;
  REP(i,2*n)cin>>a[i];

  sort(a,a+2*n);

  int lb=0,ub=n;
  while(lb<ub){
    int mid = lb+(ub-lb)/2;
    if(ok(mid)){
      ub=mid;
    }else{
      lb=mid+1;
    }
  }
  LL ret=0;
  REP(i,lb)ret=max(ret,(a[i]+a[2*lb-1-i])%m);
  FOR(i,lb,n)ret=max(ret,(a[lb+i]+a[2*n-1-(i-lb)])%m);
  cout<<ret<<endl;
  return 0;
}
