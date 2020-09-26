#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

LL mod = 998244353;

int n,k;
LL dp[200001],dpsum[200001];
int l[11],r[11];

int main(){
  cin>>n>>k;
  REP(i,k)cin>>l[i]>>r[i];

  dp[1]=1;
  dpsum[0]=0;
  dpsum[1]=1;

  FOR(i,2,n+1){
    REP(j,k){
      int lind=l[j],rind=r[j];
      if(lind >= i)continue;
      rind = min(rind,i-1);
      //cerr<<"dbg"<<endl;
      //cerr<<i<<" "<<j<<" "<<dpsum[i-lind]<<" "<<dpsum[i-rind-1]<<endl;
      dp[i]+=mod+dpsum[i-lind]-dpsum[i-rind-1];
      dp[i]%=mod;
    }
    dpsum[i] = dpsum[i-1] + dp[i];
    dpsum[i]%=mod;
  }

  cout<<dp[n]%mod<<endl;
  return 0;
}
