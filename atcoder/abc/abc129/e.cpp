#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
string s;
LL mod = 1000000007;
LL su[100002];
LL dp[100002];
int main(){
  cin>>s;
  reverse(ALL(s));
  int n = s.size();
  REP(i,n+1){
    if(i==0)su[i]=3;
    else su[i]=(3*(su[i-1]-2)+2)%mod;
  }
  REP(i,n+1){
    if(i==0)dp[i]=1;
    else if(s[i-1]=='0')dp[i]=dp[i-1];
    else dp[i]=(su[i-1]+2*(dp[i-1]-1))%mod;
  }
  /*
  REP(i,n+1)cerr<<su[i]<<" ";
  cerr<<endl;
  REP(i,n+1)cerr<<dp[i]<<" ";
  cerr<<endl;
  */
  cout<<dp[n]<<endl;
  return 0;
}
