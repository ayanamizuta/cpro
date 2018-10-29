#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

#define MOD 1000000007
#define FACT_MAX 100001

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

LL mod=MOD;
int n;
LL a[100000];
LL cum[100001];
LL memo[100001];
LL w[100001];

int main(){
  cin>>n;
  REP(i,n)
    cin>>a[i];
  Combinatrics c;

  cum[1]=1;
  FOR(i,1,n){
    cum[i+1]=((i+1)*cum[i]%mod+fact[i]%mod)%mod;
  }
  w[1]=cum[n];
  FOR(i,2,n/2+2){
    memo[i]=cum[i];
    FOR(j,i,n){
      memo[j+1]=memo[j]*(j+1)%mod;
      FOR(k,1,i+1){
	memo[j+1]+=(fact[j+1-k]*c.nck(i-1,k-1)%mod)*fact[k-1]%mod;
	memo[j+1]%=mod;
      }
    }
    w[i]=memo[n];
  }
  FOR(i,1,n/2+2){
    w[n-i+1]=w[i];
  }
  
  LL ret=0;
  REP(i,n){
    ret+=a[i]*w[i+1]%mod;
    ret%=mod;
  }
  cout<<(ret+mod)%mod<<endl;
  return 0;
}
