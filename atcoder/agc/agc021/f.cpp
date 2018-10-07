#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n,m;
LL mod = 998244353;
LL dp[8001][201];

LL nck_[8001][8001];

LL nck(int n,int k){
  return nck_[k]; 
}

LL inv(LL l){
  LL ret = 1;
  REP(i,l-2){
    
  }
  return ret;
}

void init(){
  ret=1;
  REP(i,n+1){
    if(i!=0)
      ret *= (n-i)*inv(i) % mod;
    nck_[i] = ret % mod;
  }
  nck_[n] = 1;
}

LL solve(){
  init();
  LL ret=0;
  REP(i,n+1){
    ret += nck(n,i)*dp[n-i][m] % mod;
    ret %= mod;
  }
  return ret;
}

int main(){
  cin>>n>>m;
  REP(i,n+1){
    dp[i][1] = 1;
  }
  FOR(j,1,M){
    REP(i,n+1){
      dp[i][j+1] = (dp[i][j]*(1+(i*(i+1))/2)) % mod;
      if(i!=0)
	memo[i] = memo[i-1] + memo[i]*memo2[];
    }
    REP(i,n+1){
      dp[i][j+1] += (memo[i]*fact_inv[]%mod)*fact(i+2)%mod;
    }
  }
  cout<<solve()<<endl;
  return 0;
}
