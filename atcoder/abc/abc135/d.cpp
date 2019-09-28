#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

#define MOD 1000000007
string s;
LL dp[100002][13];

int main(){
  cin>>s;
  int n = s.size();
  int mod = 1;
  REP(i,13)dp[0][i]=0;
  dp[0][0]=1;
  REP(i,n){
    if(s[n-1-i]=='?'){
      REP(j,13){
	REP(k,10){
	  dp[i+1][(j+mod*k)%13] += dp[i][j];
	  dp[i+1][(j+mod*k)%13] %= MOD;
	}
      }
    }else{
      REP(j,13){
	//cerr<<i<<" "<<j<<" "<<(s[n-1-i]-'0')<<" "<<endl;
	dp[i+1][(j+(s[n-1-i]-'0')*mod)%13] += dp[i][j];
	dp[i+1][(j+(s[n-1-i]-'0')*mod)%13] %= MOD;
      }
    }
    mod = mod*10%13;
  }

  /*
  REP(i,n+1){
    REP(j,13){
      cerr<<dp[i][j]<<" ";
    }
    cerr<<endl;
  }
  */
  
  cout<<dp[n][5]%MOD<<endl;
  return 0;
}
