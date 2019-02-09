#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

#define MOD 1000000007
#define FACT_MAX 1000000

LL fact[FACT_MAX];

class Combinatrics{
private:
  long long mod = MOD;
  int fact_max = FACT_MAX;
public:
  Combinatrics(){
    fact[0]=1;
    for(int i=1;i<fact_max;i++)
      fact[i] = (fact[i-1]*i)%mod;
  }
  
  long long power(long long n, long long e){
    long long ret = 1;
    long long b = n;
    while(e){
      if(e%2!=0)
	ret*=b;
      ret%=mod;
      b*=b;
      b%=mod;
      e/=2;
    }
    return ret;
  }

  long long inv(long long n){
    return power(n,mod-2);
  }

  long long div(long long n1,long long n2){
    return n1*power(n2,mod-2)%mod;
  }
  
  long long nck(int n,int k){
    if(k>n || k<0) return 0LL;
    if(k==n || k==0) return 1LL;
    return (fact[n]*inv(fact[n-k])%mod)*inv(fact[k])%mod;
  }
};

LL ret=0;
int r,c,x,y,d,l;
Combinatrics comb;

LL solve(int a,int b){
  if(d+l>a*b||a<=0||b<=0)return 0LL;
  return comb.nck(a*b,d)*comb.nck(a*b-d,l)%MOD;
}

int main(){
  cin>>r>>c>>x>>y>>d>>l;
  ret=solve(x,y);
  ret-=2*solve(x-1,y)+2*solve(x,y-1)-solve(x-2,y)-solve(x,y-2)-4*solve(x-1,y-1)+2*solve(x-2,y-1)+2*solve(x-1,y-2)-solve(x-2,y-2);
  ret=(MOD+ret%MOD)%MOD;
  cout<<ret*(LL)(r-x+1)*(LL)(c-y+1)%MOD<<endl;
  return 0;
}
