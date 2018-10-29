#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

LL n,k,mod=1000000007;

LL pow(LL l,LL e){
  LL ret=1,b=l;
  while(e){
    if(e%2==1)
      ret*=b;
    ret%=mod;
    b*=b;
    b%=mod;
    e/=2;
  }
  return ret;
}

int main(){
  cin>>n>>k;
  LL ret=0;

  ret+=k;
  ret%=mod;

  if(n%2==0){
    ret+=(pow(k,(n+2)/4)-k)*(n/2)%mod;
    ret+=(pow(k,n/2)-pow(k,(n+2)/4))*(n/2)%mod;
  }else{
    ret+=(pow(k,(n+1)/2)-k)*n%mod;
  }
  
  cout<<(mod+ret)%mod<<endl;
  return 0;
}
