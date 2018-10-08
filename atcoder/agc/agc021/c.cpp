#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

string s;
int k,n;

int dp[300][300][300];

int main(){
  cin>>s>>k;
  n=s.size();
  FOR(d,1,n+1){
    FOR(init,0,n-d+1){
      REP(l,k+1){
	if(d==1)dp[init][init+d-1][l]=1;
	else if(l==0){
	  if(s[init]==s[init+d-1])
	    dp[init][init+d-1][0]=(d==2)?2:2+dp[init+1][init+d-2][0];
	  else
	    dp[init][init+d-1][0]=max(dp[init][init+d-2][0],dp[init+1][init+d-1][0]);
	}else{
	  if(s[init]==s[init+d-1]){
	    dp[init][init+d-1][l]=(d==2)?2:2+dp[init+1][init+d-2][l];
	  }else{
	    dp[init][init+d-1][l]=max(max(dp[init][init+d-2][l],dp[init+1][init+d-1][l]),2+dp[init+1][init+d-2][l-1]);
	  }
	}
      }
    }
  }
  cout<<dp[0][n-1][k]<<endl;
  return 0;
}
