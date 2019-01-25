#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

#define MASK 2001
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


int n;
LL a[200000],b[200000];
LL dp[4003][4003];

void dump(){
  REP(i,5){
    REP(j,5){
      cerr<<dp[MASK-2+i][MASK-2+j]<<" ";
    }
    cerr<<endl;
  }
  cerr<<endl;
}

int main(){
  cin>>n;
  REP(i,n)
    cin>>a[i]>>b[i];
  REP(i,n){
    dp[MASK-a[i]][MASK-b[i]]++;
    dp[MASK+a[i]][MASK+b[i]]++;
  }
  LL ret=0;
  FOR(i,1,4003){
    FOR(j,1,4003){
      if(i>MASK&&j>MASK){
	ret=(ret+dp[i][j]*(dp[i-1][j]+dp[i][j-1]))%MOD;
	dp[i][j]=0;
      }
      dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1])%MOD;
    }
  }
  Combinatrics comb;
  REP(i,n){
    ret=(MOD+ret-comb.nck((LL)(2*a[i]+2*b[i]),(LL)(2*a[i])))%MOD;
  }
  ret=comb.div(ret,2LL);
  cout<<ret<<endl;
  return 0;
}
