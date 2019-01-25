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
    if(k>n || k<0) return 0;
    if(k==n || k==0) return 1;
    return (fact[n]*inv(fact[n-k])%mod)*inv(fact[k])%mod;
  }
};

LL a,b,c;

int main(){
  cin>>a>>b>>c;
  Combinatrics comb;
  cout<<(MOD+comb.div((1-comb.div(b,a))-(comb.div(c,a)-1)*(comb.div(b,a)-1)%MOD,(comb.div(c,a)-1)*(comb.div(b,a)-1)%MOD-1))%MOD<<" "<<(MOD+comb.div((1-comb.div(c,a))-(comb.div(c,a)-1)*(comb.div(b,a)-1)%MOD,(comb.div(c,a)-1)*(comb.div(b,a)-1)%MOD-1))%MOD<<endl;
  return 0;
}
