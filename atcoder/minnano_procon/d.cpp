#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int l;
LL a[200000];
LL dp[5][200002];

int main(){
  cin>>l;
  REP(i,l){
    cin>>a[i];
  }
  dp[0][0]=a[0];
  dp[1][0]=(a[0]%2)?1:(a[0]==0?2:0);
  dp[2][0]=(a[0]%2)?0:1;
  dp[3][0]=1e15;
  dp[4][0]=1e15;
  FOR(i,1,l){
    dp[0][i]=dp[0][i-1]+a[i];
    dp[1][i]=min(dp[0][i-1],dp[1][i-1])+((a[i]%2)?1:(a[i]==0?2:0));
    dp[2][i]=min(dp[0][i-1],min(dp[1][i-1],dp[2][i-1]))+((a[i]%2)?0:1);
    dp[3][i]=min(dp[2][i-1],dp[3][i-1])+((a[i]%2)?1:(a[i]==0?2:0));
    dp[4][i]=min(min(min(min(dp[4][i-1]+a[i],dp[3][i-1]+a[i]),dp[2][i-1]+a[i]),dp[1][i-1]+a[i]),dp[0][i-1]+a[i]);

    /*
    REP(j,5)
      cerr<<dp[j][i]<<" ";
    cerr<<endl;
    */
    
    REP(j,5)dp[j][i]=min(dp[j][i],(LL)1e12);
  }
  cout<<min(min(min(min(dp[0][l-1],dp[1][l-1]),dp[2][l-1]),dp[3][l-1]),dp[4][l-1])<<endl;
  return 0;
}
