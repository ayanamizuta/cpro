#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint=atcoder::modint998244353;

#define MOD 998244353
#define FACT_MAX 100000

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

LL fact[FACT_MAX];

class Combinatrics{
private:
  long long mod = MOD;
  int fact_max = FACT_MAX;
public:
  Combinatrics(){
    fact[0]=1;
    for(int i=1;i<fact_max;i++)
      fact[i] = (fact[i-1]*i)%mod;
  }
  
  long long power(long long n, long long e){
    long long ret = 1;
    long long b = n;
    while(e){
      if(e%2!=0)
	ret*=b;
      ret%=mod;
      b*=b;
      b%=mod;
      e/=2;
    }
    return ret;
  }

  long long inv(long long n){
    return power(n,mod-2);
  }

  long long div(long long n1,long long n2){
    return n1*power(n2,mod-2)%mod;
  }
  
  long long nck(int n,int k){
    if(k>n || k<0) return 0LL;
    if(k==n || k==0) return 1LL;
    return (fact[n]*inv(fact[n-k])%mod)*inv(fact[k])%mod;
  }
};

int n,k;
mint a[200000];
mint mom[301];
int main(){
    Combinatrics comb;
    cin>>n>>k;
    REP(i,k+1){
        mom[i]=0;
    }
    REP(i,n){
        LL a_;
        cin>>a_;
        a[i] = mint(a_);
        mint m = 1;
        FOR(j,1,k+1){
            m *= a[i];
            mom[j] += m;
        }
    }
    
    FOR(i,1,k+1){
        mint ret=0;
        mint car=0;
        FOR(j,1,i/2+1){
            LL c_ = comb.nck(i,j);
            mint c = mint(c_);
            if(i-j == j)c/=2;
            ret += c*mom[i-j]*mom[j];
            car += c;
            //cerr<<i<<" "<<j<<" "<<c<<endl;
        }
        ret += mom[i]*(n-1)-mom[i]*car;
        cout<<ret.val()<<endl;
    }
}