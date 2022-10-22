#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long


int op(int a, int b) {
    return max(a, b);
}

int e() {
    return (int)(-1e9);
}

int n,p[200000];
vector<int> v;

struct S{
  int ll=-1;
  int l=-1;
  int r=-1;
  int rr=-1;
};

S table[200000];

int main(){
    cin>>n;
    REP(i,n){
      cin>>p[i];
      table[i].r=n;
      table[i].rr=n;
    }
    REP(i,n)v.push_back(p[i]);
    auto segt = atcoder::segtree<int,op,e>(v);
    REP(i,n){
      auto s=table[i];
      int lb=i+1,ub=n+1;
      while(lb<ub){
        auto mid = (lb+ub)/2;
        auto m = segt.prod(i,mid);
        if(m==p[i])lb=mid+1;
        else ub=mid;
      }
      s.r=lb-1;

      lb=s.r+1;
      ub=n+1;
      while(lb<ub){
        auto mid = (lb+ub)/2;
        auto m = segt.prod(s.r+1,mid);
        if(m<=p[i])lb=mid+1;
        else ub=mid;
      }
      s.rr=lb-1;

      lb=0;
      ub=i;
      while(lb<ub){
        auto mid = (lb+ub)/2;
        auto m = segt.prod(mid,i+1);
        if(m==p[i])ub=mid;
        else lb=mid+1;
      }
      s.l=lb-1;

      lb=0;
      ub=s.l;
      while(lb<ub){
        auto mid = (lb+ub)/2;
        auto m = segt.prod(mid,s.l);
        if(m<=p[i])ub=mid;
        else lb=mid+1;
      }
      s.ll=lb-1;
      table[i]=s;
    }

    LL ret=0;
    REP(i,n){
      auto s=table[i];
      //cerr<<s.ll<<" "<<s.l<<" "<<s.r<<" "<<s.rr<<endl;
      if(s.ll==s.l && s.rr==s.r)continue;
      if(s.ll==s.l)ret+=((LL)p[i]*(i+1))*(s.rr-s.r);
      else if(s.rr==s.r)ret+=((LL)p[i]*(n-i))*(s.l-s.ll);
      else{
        ret+=((LL)p[i]*(s.rr-s.r))*(i-s.l);
        ret+=((LL)p[i]*(s.l-s.ll))*(s.r-i);
      }
    }
    cout<<ret<<endl;
}