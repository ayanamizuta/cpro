#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
vector<LL> a,asum;

int main(){
  cin>>n;
  REP(i,n){
    a.push_back(0);
    asum.push_back(0);
    cin>>a[i];
  }
  asum.push_back(0);
  LL ret=-1000000000,su=0;
  REP(i,n)su+=a[i];
  sort(ALL(a));
  reverse(ALL(a));
  REP(i,n)asum[i+1]=asum[i]+a[i];
  int pos=0;
  FOR(i,1,n){
    LL cand = 2*asum[i]-su;
    if(ret < cand){
      ret=cand;
      pos=i;
    }
  }
  cout<<ret<<endl;
  LL now=a[pos];
  REP(i,n-1){
    if(i<pos-1){
      cout<<now<<" "<<a[i]<<endl;
      now-=a[i];
    }else if(i==(pos-1)){
      cout<<a[pos-1]<<" "<<now<<endl;
      now=a[pos-1]-now;
    }else{
      cout<<now<<" "<<a[i+1]<<endl;
      now-=a[i+1];
    }
  }
  return 0;
}
