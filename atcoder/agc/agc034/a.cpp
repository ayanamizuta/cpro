#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n,a,b,c,d;
string s;

bool enable(int x,int y){
  FOR(i,x,y){
    if(s[i]=='#' && s[i+1] == '#')
      return false;
  }
  return true;
}

bool afford(int x,int y){
  FOR(i,x,y+1){
    //cerr<<i<<s[i-1]<<" "<<s[i]<<" "<<s[i+1]<<endl;
    if(s[i-1]=='.' && s[i] == '.' && s[i+1] == '.')
      return true;
  }
  return false;
}

int main(){
  cin>>n>>a>>b>>c>>d;
  cin>>s;
  a--;b--;c--;d--;
  if(c<d){
    cout<<((enable(a,c) && enable(b,d))?"Yes":"No")<<endl;
  }else{
    cout<<((enable(a,c) && afford(b,d))?"Yes":"No")<<endl;
  }
  return 0;
}
