#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int m;
LL k;
int main(){
  cin>>m>>k;
  if(k!=0)
    cout<<-1<<endl;
  else{
    REP(i,(LL)(1<<m)){
      cout<<i<<" "<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}
