#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

LL n,p;

int main(){
  cin>>n>>p;
  if(n==1){
    cout<<p<<endl;
    return 0;
  }
  LL m=2,p_=p,ret=1,tmp=0;
  while(m < 1000002){
    tmp=0;
    while(p_%m==0){
      p_/=m;
      tmp++;
      if(tmp>=n){
	tmp-=n;
	ret*=m;
      }
    }
    m++;
  }
  cout<<ret<<endl;
  return 0;
}
