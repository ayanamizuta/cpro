#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

string s;
int n,ind=0;
string w = "keyence";

int main(){
  cin>>s;
  n=s.size();
  bool bl=true;
  FOR(i,n-7,n){
    if(s[i]!=w[i-(n-7)]){
      bl=false;
      break;
    }
  }
  if(bl){
    cout<<"YES"<<endl;
    return 0;
  }

  bl=true;
  FOR(i,0,7){
    if(s[i]!=w[i]){
      bl=false;
      break;
    }
  }
  if(bl){
    cout<<"YES"<<endl;
    return 0;
  }

  bl=true;
  REP(i,7){
    if(s[i]!=w[i]){
      ind=i;
      break;
    }
  }
  REP(i,7-ind){
    if(s[n-1-i]!=w[7-1-i]){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
