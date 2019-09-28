#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

string s;
int n;
LL cnt[26];
LL mod = 1000000007;

int main(){
  cin>>n;
  cin>>s;
  REP(i,n){
    cnt[(int)(s[i]-'a')]++;
  }
  LL ret=1LL;
  REP(i,26){
    ret=(ret*(1+cnt[i]))%mod;
  }
  cout<<(ret-1)<<endl;
  return 0;
}
