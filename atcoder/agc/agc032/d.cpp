#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
LL a,b;
int p[5000],inv[5000];
LL dp[5001][10001],mindp[5001][10002];

int main(){
  cin>>n>>a>>b;
  REP(i,n){cin>>p[i];p[i]--;}
  REP(i,n)inv[p[i]]=i;
  REP(i,n+1)mindp[i][0]=0LL;
  REP(i,2*n+1){dp[0][i]=0LL;mindp[0][i+1]=0LL;}
  
  FOR(i,1,n+1){
    REP(j,2*n+1){
      //cerr<<i<<" "<<j<<" "<<2*inv[i-1]+1<<" "<<mindp[i-1][j]<<endl;
      if(2*inv[i-1]+1==j)
	dp[i][j]=mindp[i-1][j];
      else if(2*inv[i-1]+1 < j)
	dp[i][j]=mindp[i-1][j]+a;
      else
	dp[i][j]=mindp[i-1][j]+b;
    }

    mindp[i][0]=dp[i][0];
    REP(j,2*n+1){
      if(j%2!=0)
	mindp[i][j+1] = min(dp[i][j],min(dp[i][j+1],mindp[i][j]));
      else
	mindp[i][j+1] = mindp[i][j];
    }
  }

  /*
  REP(i,n+1){
    REP(j,2*n+1)
      cerr<<dp[i][j]<<" ";
    cerr<<endl;
  }

  REP(i,n+1){
    REP(j,2*n+2)
      cerr<<mindp[i][j]<<" ";
    cerr<<endl;
  }
  */
  
  
  cout<<*min_element(dp[n],dp[n]+2*n+1)<<endl;
  return 0;
}
