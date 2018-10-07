#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long
#define MOD 998244353
#define FACT_MAX 1000000

int n,k;
LL mod = MOD;

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
  
  long long nck(int n,int k){
    if(k>n || k<0) return 0;
    if(k==n || k==0) return 1;
    return (fact[n]*inv(fact[n-k])%mod)*inv(fact[k])%mod;
  }
};

int main(){
  cin>>n>>k;
  LL ret=0;
  Combinatrics c;
  REP(i,k+1){
    if(i < k - i || i < n)continue;
    if(i==k-i){
      if(2*i-n+2>k)
	ret+=c.nck(k-1,i);
      else
	ret+=c.nck(k-1,i)-c.nck(k-1,k-2*i+n-2);
    }else
      ret+=(2*i-k>=n)?c.nck(k,i):c.nck(k,i)-c.nck(k,2*i-n+1);
    //cerr<<i<<" "<<ret<<endl;
    ret%=mod;
  }
  cout<<(ret+mod)%mod<<endl;
  return 0;
}
