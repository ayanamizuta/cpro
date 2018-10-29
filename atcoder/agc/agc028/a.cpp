#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n,m;
string s,t;

int mygcd(int a,int b){
  if(b==0) return a;
  return mygcd(min(a,b),max(a,b)%min(a,b));
}

int main(){
  cin>>n>>m>>s>>t;
  int g = mygcd(n,m);
  int n_del=n/g,m_del=m/g;
  int p=0,q=0;
  REP(i,n/n_del){
    if(s[p]!=t[q]){
      cout<<-1<<endl;
      return 0;
    }
    p+=n_del;
    q+=m_del;
  }
  cout<<(LL)n*(LL)(m/g)<<endl;
  return 0;
}
