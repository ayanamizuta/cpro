#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

vector<LL> divisors(LL n){
  vector<LL> ret;
  for(LL i=1 ; i*i<=n ; ++i){
    if(n%i == 0){
      ret.push_back(i);
      if(i!=1 && i*i!=n){
	ret.push_back(n/i);
      }
    }
  }
  return ret;
}

int main(){
  LL n;
  cin>>n;
  vector<LL> v = divisors(n);

  LL ret=0LL;
  REP(i,v.size()){
    LL r = v[i];
    if(n%r==0 && (n/r-1>r))ret+=n/r-1;
  }
  cout<<ret<<endl;
  return 0;
}
