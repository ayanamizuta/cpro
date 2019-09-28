#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
LL mod = 1000000007;
int n,m;
int a[100001];
LL dp[100001];
int main(){
  cin>>n>>m;
  REP(i,n+1)a[i]=0;
  REP(i,m){
    int tmp;
    cin>>tmp;
    a[tmp]=1;
  }
  REP(i,n+1){
    if(i>1 && a[i]!=1){
      dp[i] = (dp[i-1]+dp[i-2])%mod;
    }else if(i > 0 && a[i]!=1){
      dp[i] = (dp[i-1])%mod;
    }else{
      dp[0]=1;
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}
