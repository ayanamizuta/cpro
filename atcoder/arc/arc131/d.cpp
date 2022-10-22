#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,m,d;
LL r[100001],s[100001];

LL score_at(LL p){
  if(p<0)
    return score_at(-p);
  if(p>r[m])
    return 0;
  
  int lb=0;
  int ub=m-1;
  while(lb<ub){
    int mid = (lb+ub+1)/2;
    if(p<=r[mid])
      ub=mid-1;
    else
      lb=mid;
  }
  //cerr<<p<<" "<<lb<<endl;
  return s[lb];
}

LL expe(LL start){
  LL ret = score_at(start);
  LL lb=start,ub=start;
  REP(i,n-1){
    LL l=score_at(lb-d),r=score_at(ub+d);
    //cerr<<start<<" "<<i<<" "<<l<<" "<<r<<endl;
    if(l>r){
      ret+=l;
      lb = lb-d;
    }else{
      ret+=r;
      ub = ub+d;
    }
  }
  return ret;
}

int main(){
    cin>>n>>m>>d;
    REP(i,m+1)cin>>r[i];
    REP(i,m)cin>>s[i];

    LL ret=max(expe(-r[1]),expe(0));
    ret = max(ret,expe(r[1]/2));
    ret = max(ret,expe(r[1]/2+1));
    ret = max(ret,expe(r[1]/2-1));

    cout<<ret<<endl;
}