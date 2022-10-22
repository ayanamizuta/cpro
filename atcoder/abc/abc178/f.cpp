#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int n,a[200000],b[200000];

int main(){
    cin>>n;
    REP(i,n)cin>>a[i];
    REP(i,n)cin>>b[i];

    int lp=0,rp=n-1;
    while(lp!=rp){
      while(lp<n && a[lp]!=b[lp])lp++;
      while(rp>=0 && a[rp]!=b[rp])rp--;
      if(rp>=0 && lp<n && a[lp]==b[lp] && a[rp]==b[rp] && b[lp]!=b[rp])swap(b[lp],b[rp]);
      else break;
    }

    REP(i,n){
      if(lp>rp)break;
      if(a[i]!=b[lp] && b[i]!=b[lp]){
        swap(b[i],b[lp]);
        lp++;
      }
    }
    if(lp<=rp){cout<<"No"<<endl;return 0;}
    cout<<"Yes"<<endl;

    REP(i,n-1)cout<<b[i]<<" ";
    cout<<b[n-1]<<endl;
}