#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

#define MOD 998244353
#define FACT_MAX 1000000

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
    if(k>n || k<0) return 0;
    if(k==n || k==0) return 1;
    return (fact[n]*inv(fact[n-k])%mod)*inv(fact[k])%mod;
  }
};

#define BITN 300
int Rank(std::vector<std::bitset<BITN>> &a){
  int rnk=0;
  int n=a.size();
  int m=BITN;
  vector<int> where (m, -1);
  for (int col=0, row=0; col<m && row<n; ++col) {
    for (int i=row; i<n; ++i)
      if (a[i][col]) {
	swap (a[i], a[row]);
	break;
      }
    if (! a[row][col])
      continue;
    where[col] = row;

    for (int i=0; i<n; ++i)
      if (i != row && a[i][col])
	a[i] ^= a[row];
    ++row;
    rnk=row;
  }
  return rnk;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<bitset<300>> a(n);
  int tmp;
  REP(i,n){
    REP(j,m){
      cin>>tmp;
      a[i][j]=(tmp==1);
    }
  }
  int rnk = Rank(a);
  Combinatrics c;
  cout<<(MOD+c.power(2LL,(LL)(n+m-1))-c.power(2LL,(LL)(n+m-rnk-1)))%MOD<<endl;
  return 0;
}
