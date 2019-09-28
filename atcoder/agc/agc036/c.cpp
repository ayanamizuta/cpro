#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

#define MOD 998244353
#define FACT_MAX 3000000

LL fact[FACT_MAX];

class Combinatrics{
private:
  long long mod = 998244353;
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

signed main(){
  int n,m;
  cin>>n>>m;
  LL ret=0;
  Combinatrics comb;
  int i=m%2;
  
  while(i<=m && i<=n){
    ret += comb.nck((3*m-i)/2+n-1,n-1)*comb.nck(n,i)%MOD;
    FOR(j,2*m+1,3*m+1){
      ret = MOD + ret - n*(comb.nck((3*m-i-j+(j%2))/2+n-2,n-2)*comb.nck(n-1,i-(j%2)))%MOD;
      ret%=MOD;
    }
    i+=2;
  }
  cout<<ret<<endl;
  return 0;
}
