#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n;
string s[50];
int t[50];
string x;
int main(){
  cin>>n;
  REP(i,n)cin>>s[i]>>t[i];
  cin>>x;
  int ret=0;
  bool bl=false;
  REP(i,n){
    if(bl)ret+=t[i];
    if(s[i]==x)bl=true;
  }
  cout<<ret<<endl;
  return 0;
}
