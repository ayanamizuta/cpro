#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int main(){
  struct hoge {int huga,piyo;};
  vector<hoge> v{{1,2},{2,3},{3,4}};
  cout<<"lb of 0:"<<lower_bound(ALL(v),(hoge){0,1},[](const hoge a,const hoge b){return a.huga<b.huga;})-v.begin()<<endl;
  cout<<"lb of 2:"<<lower_bound(ALL(v),(hoge){2,2},[](const hoge a,const hoge b){return a.huga<b.huga;})-v.begin()<<endl;
  return 0;
}
