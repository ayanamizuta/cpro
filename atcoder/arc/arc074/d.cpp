#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

LL a[300000],l[100001],r[100001];
int n;

int main(){
  cin>>n;
  REP(i,3*n)
    cin>>a[i];

  LL su=accumulate(a,a+n,(LL)0);
  priority_queue<LL,vector<LL>,greater<LL>> q;
  REP(i,n)
    q.push(a[i]);
  REP(i,n+1){
    l[i]=su;
    q.push(a[n+i]);
    su+=a[n+i]-q.top();
    q.pop();
  }

  su=accumulate(a+2*n,a+3*n,(LL)0);
  priority_queue<LL> q2;
  REP(i,n)
    q2.push(a[2*n+i]);
  REP(i,n+1){
    r[n-i]=su;
    q2.push(a[2*n-1-i]);
    su+=a[2*n-1-i]-q2.top();
    q2.pop();
  }
  
  LL ret=-1e18;
  REP(i,n+1){
    //cerr<<i<<" "<<l[i]<<" "<<r[i]<<endl;
    ret=max(ret,l[i]-r[i]);
  }
  cout<<ret<<endl;
  return 0;
}
