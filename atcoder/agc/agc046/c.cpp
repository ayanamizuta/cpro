#include "bits/stdc++.h"
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

string s;
LL k;
LL dp[301][301][301];
int a[301];

int main(){
  cin>>s>>k;
  int n = s.size();
  int index = 0,cnt=0;
  REP(i,301){a[i]=0;}
  REP(i,n){
    if(s[n-1-i] == '0'){
      a[index] = cnt;
      cnt=0;
      index++;
    }else{
      cnt++;
    }
  }
  a[index]=cnt;

  k = min((LL)301,k);
  REP(i,301){
    REP(j,301){
      REP(l,301){dp[i][j][l]=0;}
    }
  }
  dp[0][0][0] = 1;
  FOR(i,1,index+2){
    REP(j,k+1){
      REP(m,a[i-1]+1){
        REP(l,k+1){
          if(l >= m && j >= m)
            dp[i][j][l] += dp[i-1][j-m][l-m];
          dp[i][j][l] %= MOD;
        }
      }
      REP(l,k+1){
        FOR(m,1,k+1-l){
          if(l + m <= k)
            dp[i][j][l] += dp[i-1][j][l+m];
          dp[i][j][l] %= MOD;
        }
      }
    }
  }
  /*REP(i,index+2){
    REP(j,k+1){
      cerr<<i<<" "<<j<<" "<<endl;
      REP(l,k+1){
        cerr<<dp[i][j][l]<<" ";
      }
      cerr<<endl<<endl;
    }
  }*/

  LL ret = 0;
  REP(i,k+1)ret = (ret + dp[index+1][i][0]) % MOD;
  cout<<ret<<endl;
  return 0;
}
