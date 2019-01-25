#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

LL n;

long long gcd(long long a,long long b){
  if(b==0)return a;
  if(a<b)return gcd(b,a);
  return gcd(b,a%b);
}

long long lcm(long long a,long long b){
  return a*b/gcd(a,b);
}

long long power(long long n, long long e,long long m){
  long long ret = 1;
  long long b = n;
  while(e){
    if(e%2!=0)
      ret*=b;
    ret%=m;
    b*=b;
    b%=m;
    e/=2;
  }
  return ret;
}

long long euler_phi(long long n){
  LL ret=n;
  for(LL k=2;k*k<n+2;k++){
    if(n%k==0){
      ret-=ret/k;
      while(n%k==0)n/=k;
    }
  }
  if(n!=1)ret-=ret/n;
  return ret;
}

int main(){
  cin>>n;
  vector<LL> primes;
  LL m=n;
  for(LL k=2;k*k<m+2;k++){
    if(!(m%k)){
      primes.push_back(k);
      m/=k;
      if(m%k==0){cout<<-1<<endl;return 0;}
    }
  }
  if(m!=1)primes.push_back(m);
  REP(i,primes.size())
    primes[i]--;
  LL l = accumulate(primes.begin(),primes.end(),1,[](LL x,LL y){return lcm(x,y);});
  if(gcd(n,l)!=1){cout<<-1<<endl;return 0;}
  vector<LL> divisors;
  LL tor=euler_phi(l);
  LL rem=n;
  for(LL k=1;k*k<=l;k++){
    if(!(tor%k)){
      divisors.push_back(k);
      if(power(n,k,l)==1%l){cout<<k<<endl;return 0;}
    }
  }
  REP(i,divisors.size()){
    LL e = tor/divisors[divisors.size()-1-i];
    if(power(n,e,l)==1){cout<<e<<endl;return 0;}
  }
  return 0;
}
