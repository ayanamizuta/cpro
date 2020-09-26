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

LL n;
LL p[5001],memo[5001],memo_next[5001],memo_exc[5001];

int main(){
  cin >> n;
  REP(i,n)cin>>p[i];


  Combinatrics comb;
  LL ret = 0;
  ret = n*(comb.power(n-1,k));
  REP(i,d)ret = (MOD + ret - (w[i]-1)*comb.power(n-1,k-1)%MOD)%MOD;
  REP(i,d){
    memo[]
    REP(j,d){
      
    }
  }
  FOR(i,3,n+1){
    LL sum = 0;
    REP(j,n)sum+=(sum+memo[j])%MOD;
    REP(j,d){
      memo_next[j] = comb.div((sum-memo[j])*w[j],n-1);
    }
    REP(j,d){
      ret = (MOD + ret - (memo_next[j]*fact[j-1])%MOD)%MOD;
    }
    REP(j,d)memo[j] = memo_next[j];
  }
  cout<<ret<<endl;
  return 0;
}
