#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

LL n,k;
vector<pair<LL,int>> primes;

LL prod(vector<int> &d){
  return accumulate(ALL(d),1LL,[](LL a,pair<LL,int> p){});
}

LL rel_prime_sum(LL m){
  LL ret=m*(m+1)/2%MOD;
  REP(i,1<<primes.size()){
    ret=()(ret)
  }
  return ret;
}

void upd(vector<int> &d){
  REP(i,d.size()){
    if(d[i]<primes[i].second){d[i]++;return;}
    d[i]=0;
  }
}

int main(){
  cin>>n>>k;
  LL kdum=k,p=2;
  int cnt;
  while(p*p<=kdum){
    cnt=0;
    while(!(kdum%p)){
      kdum/=p;
      cnt++;
    }
    if(cnt)primes.push_back(make_pair(p,cnt));
    p++;
  }
  if(kdum>1)primes.push_back(make_pair(kdum,1));
  vector<int> div(primes.size());
  LL ret=0;
  while(*div.end()!=(*primes.end()).second){
    LL m = prod(div);
    LL su = rel_prime_sum(n/m);
    ret=(ret+(su*k/m)%MOD)%MOD;
    upd(div);
  }
  ret=(ret+(k*(n/k)*(1+n/k)/2)%MOD)%MOD;
  cout<<ret<<endl;
  return 0;
}
