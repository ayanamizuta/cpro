#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

LL a[100000],b[100000],c[100000];
int x[100000],y[100000];
int m,na,nb;

int main(){
  cin>>na>>nb>>m;
  REP(i,na)cin>>a[i];
  REP(i,nb)cin>>b[i];
  REP(i,m)cin>>x[i]>>y[i]>>c[i];
  LL mina = 100001,minb=100001;
  REP(i,na)mina=min(mina,a[i]);
  REP(i,nb)minb=min(minb,b[i]);
  LL ret = mina+minb;
  REP(i,m)ret = min(ret,a[x[i]-1]+b[y[i]-1]-c[i]);
  cout<<ret<<endl;
  return 0;
}
