#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

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

vector<long long> divisor(long long n)
{
	vector<long long> num;
	for(long long i=1;i*i<=n;++i){
		if(n%i==0){
			num.push_back(i);
			if(i*i!=n)
				num.push_back(n/i);
		}
	}
	return num;
}

/* return 1 = 10**n  (mod k) */
bool try_k(LL k,LL n_){
  LL b=10,m=1,n=n_;
  while(n){
    if(n%2){
      m*=b;
      m%=k;
    }
    b*=b;
    b%=k;
    n/=2;
  }
  return m==1;
}

void solve(LL k){
  if(!(k%5) || !(k%4)){
    cout<<-1<<endl;
    return;
  }
  if(!(k%2))k/=2;
  LL acm=0,acm_minus=0;
  while(!(k%3)){
    acm++;
    k/=3;
  }
  LL m = euler_phi(k);
  for(auto n : divisor(m)){
    if(try_k(k,n) && n!=1){
      m=min(n,m);
    }
  }
  LL mdum=m;
  while(!(mdum%3)){
    acm_minus++;
    mdum/=3;
  }
  while(acm_minus<acm){
    acm_minus++;
    m*=3;
  }
  cout<<m<<endl;
}

int t;

int main(){
  cin>>t;
  LL k;
  REP(i,t){
    cin>>k;
    solve(k);
  }
}