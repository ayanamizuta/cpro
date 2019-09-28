#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n;
string s[10000];
LL lb=0,ra=0;

LL innercnt(string s){
  LL cnt=0;
  if(s[s.size()-1]=='A')ra++;
  if(s[0]=='B')lb++;
  REP(i,s.size()-1){
    if(s[i]=='A' && s[i+1]=='B')cnt++;
  }
  return cnt;
}

int main(){
  cin>>n;
  LL cnt=0;
  REP(i,n){
    cin>>s[i];
    cnt+=innercnt(s[i]);
  }
  if(lb==ra){
    bool flg=true;
    REP(i,n){
      flg = flg && !((s[i][0]=='B') ^ (s[i][s[i].size()-1]=='A'));
    }
    if(flg)
      cout<<cnt+max(0LL,min(lb,ra)-1LL)<<endl;
    else
      cout<<cnt+min(lb,ra)<<endl;
  }else
    cout<<cnt+min((LL)(n-1),min(lb,ra))<<endl;
  return 0;
}
