#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long
int n;
LL x;
LL p[51];
LL len[51];

LL p_(int l){
  if(l==0)
    return 1;
  return 1+2*p_(l-1);
}

LL len_(int l){
  if(l==0)
    return 1;
  return 3+2*len_(l-1);
}

LL solve(int l,LL s){
  if(s==0)
    return 0;
  if(s>=2+len[l-1]){
    return 1+p[l-1]+solve(l-1,s-2-len[l-1]);
  }else if(s>=1+len[l-1]){
    return p[l-1]+solve(l-1,s-2-len[l-1]);
  }else if(s>=2){
    return solve(l-1,s-1);
  }else{
    return 0;
  }
}

int main(){
  cin>>n>>x;
  FOR(i,1,n+1){
    p[i]=p_(i);
    len[i]=len_(i);
  }
  cout<<solve(n,x)<<endl;
  return 0;
}
