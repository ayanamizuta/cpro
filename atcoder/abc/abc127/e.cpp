#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
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

int n,m,k;
int main(){
  cin>>n>>m>>k;
  LL s=0;
  REP(i,n-1)s=(s+((((LL)(i+1)*(LL)(n-1-i))%MOD)*m%MOD)*m%MOD)%MOD;
  REP(i,m-1)s=(s+((((LL)(i+1)*(LL)(m-1-i))%MOD)*n%MOD)*n%MOD)%MOD;
  Combinatrics comb;
  //cerr<<s<<endl;
  cout<<(comb.nck(n*m-2,k-2)*s)%MOD<<endl;
  return 0;
}
