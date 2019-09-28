#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
LL l,a,b,m;



LL moddigit(LL n){
  LL ret=1;
  LL b=10;
  while(n>0){
    if(n%2==1){
      ret*=b;
      ret%=m;
    }
    b=b*b%m;
    n=n/2;
  }
  return ret;
}

int digit(LL n){
  LL nn=1;
  FOR(i,1,19){
    if(n<=nn)return i;
    nn*=10;
  }
}

LL solve_sub(LL p,LL q){
  LL n = (LL)(q-p)/b+1;
  LL ret=0,mod=moddigit(digit(p));
  LL x=p;
  REP(i,n){
    ret+=x;
    ret%=m;
    
    x=(x*mod+mod*b)%m;
  }
  return ret;
}

LL solve(LL car,LL idx){
  if(idx >= l)return car;
  LL p = a + b*idx;
  LL lb=0,ub=l-1;
  while(lb<ub){
    LL mid = (lb+ub)/2;
    if(digit(p)<digit(a+mid*b)){
      ub=mid;
    }else{
      lb=mid+1;
    }
  }
  if(ub > lb)
  LL n=lb-idx+1;
  LL su = solve_sub(p,a+b*lb);
  cerr<<idx<<" "<<p<<" "<<a+b*lb<<" "<<su<<endl;
  return solve(((car*moddigit(n*digit(p)))%m+su)%m,lb+1);
}

int main(){
  cin>>l>>a>>b>>m;
  cout<<solve(0LL,0LL)<<endl;
  return 0;
}
