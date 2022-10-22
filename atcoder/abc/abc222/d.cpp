#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

LL dp[3001][3001];
int n;
int a[3000],b[3000];
LL acm[3001];
LL mod = 998244353;

int main(){
    cin>>n;
    REP(i,n)cin>>a[i];
    REP(i,n)cin>>b[i];

    REP(i,n){
      if(a[i]>b[i]){
        cout<<0<<endl;
        return 0;
      }
      
      FOR(j,a[i],b[i]+1){
        if(!i){
          dp[i+1][j]=1;
        }else{
          dp[i+1][j]=acm[j];
        }
      }

      acm[0]=dp[i+1][0];
      REP(j,3000){
        acm[j+1]=(acm[j]+dp[i+1][j+1])%mod;
      }
      
    }

    /*REP(i,n+1){
      REP(j,n){

      cerr<<dp[i][j]<<" ";
      }
      cerr<<endl;
    }*/

    LL ret=0;
    REP(i,3001){
      ret+=dp[n][i];
      ret%=mod;
    }
    cout<<ret<<endl;
}