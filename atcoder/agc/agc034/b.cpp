#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
string s;
int main(){
  cin>>s;
  int n = s.size();
  LL cnt=0;
  LL ret=0;
  int idx=0;
  while(idx < n-1){
    if(s[idx]=='A'){
      cnt++;
      idx++;
    }else if(s[idx]=='B' && s[idx+1]=='C'){
      ret+=(LL)cnt;
      idx+=2;
    }else{
      cnt=0;
      idx++;
    }
  }
  cout<<ret<<endl;
  return 0;
}
