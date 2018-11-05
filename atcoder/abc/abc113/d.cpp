#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int h,w,k;
LL mod = 1000000007;
LL dp[101][9];

int comb[8] = {1,2,3,5,8,13,21,34};

int main(){
  cin>>h>>w>>k;

  if(w==1){
    cout<<1<<endl;
    return 0;
  }

  REP(i,102){
    REP(j,w+1){
      dp[i][j]=0;
    }
  }

  dp[1][1] = comb[w-2];
  dp[1][2] = comb[max(0,w-3)];
  
  FOR(i,2,h+1){
    FOR(j,1,w+1){
      dp[i][j] = dp[i-1][j] * comb[max(0,j-2)] * comb[max(0,w-j-1)] % mod;
      if(j > 1){
	dp[i][j] += dp[i-1][j-1] * comb[max(0,j-3)] * comb[max(0,w-j-1)] % mod;
      }
      if(j < w){
	dp[i][j] += dp[i-1][j+1] * comb[max(0,j-2)] * comb[max(0,w-j-2)] % mod;
      }
      dp[i][j] %= mod;
    }
  }

  cout<<dp[h][k]%mod<<endl;
  return 0;
}
