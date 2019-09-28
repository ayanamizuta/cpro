#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;}
#define pb push_back
#define f first
#define s second
#define INF 1000000000000000000

#define int long long

const int mod =  998244353;
#define FACT_MAX 3000000

LL fact[FACT_MAX];

class Combinatrics{
private:
  long long mod = 998244353;
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

template<long long MOD>
struct ModInt{
 
  using ll = long long;
  ll val;
 
  void setval(ll v) { val = v % MOD; };
  ModInt(): val(0) {}
  ModInt(ll v) { setval(v); };
 
  ModInt operator+(const ModInt &x) const { return ModInt(val + x.val); }
  ModInt operator-(const ModInt &x) const { return ModInt(val - x.val + MOD); }
  ModInt operator*(const ModInt &x) const { return ModInt(val * x.val); }
  ModInt operator/(const ModInt &x) const { return *this * x.inv(); }
  ModInt operator-() const { return ModInt(MOD - val); }
  ModInt operator+=(const ModInt &x) { return *this = *this + x; }
  ModInt operator-=(const ModInt &x) { return *this = *this - x; }
  ModInt operator*=(const ModInt &x) { return *this = *this * x; }
  ModInt operator/=(const ModInt &x) { return *this = *this / x; }
 
  friend ostream& operator<<(ostream &os, const ModInt &x) { os << x.val; return os; }
  friend istream& operator>>(istream &is, ModInt &x) { is >> x.val; x.val = (x.val % MOD + MOD) % MOD; return is;}

  ModInt pow(ll n) const {
    ModInt a = 1;
    if(n == 0) return a;
    int i0 = 64 - __builtin_clzll(n);
    for(int i = i0 - 1; i >= 0; i--){
      a = a * a;
      if((n >> i) & 1) a *= (*this); 
    }
    return a;
  }
  ModInt inv() const { return this->pow(MOD - 2); }
};

//N=2^n, e^N=1
template<long long MOD>
void NTT(vector<ModInt<MOD>> &f, ModInt<MOD> e){
    int N = f.size();
    if(N == 1) return;
    N /= 2;
    vector<ModInt<MOD>> f0(N), f1(N);
    REP(i, N){
        f0[i].val = f[2 * i].val;
        f1[i].val = f[2 * i + 1].val;
    }
    ModInt<MOD> e2 = e * e;
    NTT(f0, e2);
    NTT(f1, e2);
 
    ModInt<MOD> c = 1;
    REP(i, N){
        f[i] = f0[i] + f1[i] * c;
        c *= e;
    }
    REP(i, N){
        f[i + N] = f0[i] + f1[i] * c;
        c *= e;
    }
}

template<long long MOD>
vector<ModInt<MOD>> convolution(vector<ModInt<MOD>> A, vector<ModInt<MOD>> B, ModInt<MOD> e){
    int N = A.size();
    NTT(A, e);
    NTT(B, e);
    vector<ModInt<MOD>> C(N);
    REP(i, N) C[i] = A[i] * B[i];
    e = e.inv();
    NTT(C, e);
    ModInt<MOD> invN = ((ModInt<MOD>)N).inv();
    REP(i, N) C[i] *= invN;
    return C;
}

using mint = ModInt<mod>; mint pow(mint x, long long n) { return x.pow(n); }
//using mint = double; //for debug
using mvec = vector<mint>;

signed main(){
  int n,m;
  cin>>n>>m;
  LL ret=0;
  Combinatrics comb;
  int i=m%2;
  /*
  while(i<=m && i<=n){
    ret += comb.nck((3*m-i)/2+n-1,n-1)*comb.nck(n,i)%MOD;
    FOR(j,2*m+1,3*m+1){
      ret = MOD + ret - n*(comb.nck((3*m-i-j+(j%2))/2+n-2,n-2)*comb.nck(n-1,i-(j%2)))%MOD;
      ret%=MOD;
    }
    i+=2;
  }
  */
  while(i<=m && i<=n){
    ret += comb.nck((3*m-i)/2+n-1,n-1)*comb.nck(n,i)%mod;
    i+=2;
  }
  cerr<<ret<<endl;
  
  mint e = 44009197;
  int bit = 11;
  mvec A(1LL<<(bit),0),B(1LL<<(bit),0);
  if(m%2==0){
    REP(i,m/2){
      A[i] = ModInt<mod>(comb.nck(i+n-2,n-2));
    }
    REP(i,min(m/2+1,n/2+1)){
      B[i] = ModInt<mod>(comb.nck(n-1,2*i));
    }
  }
  mvec C = convolution(A, B, e);
  REP(i,m/2){
    ret = (mod + ret - n*C[i].val%mod)%mod;
  }
  cerr<<A[0]<<" "<<A[1]<<" "<<A[2]<<endl;
  cerr<<B[0]<<" "<<B[1]<<" "<<B[2]<<endl;
  cerr<<C[0]<<" "<<C[1]<<endl;

  mvec A_(1LL<<(bit),0),B_(1LL<<(bit),0);
  if(m%2==0){
    REP(i,m/2){
      A_[i] = ModInt<mod>(comb.nck(i+n-2,n-2));
    }
    REP(i,min(m/2+1,n/2+1)){
      B_[i] = ModInt<mod>(comb.nck(n-1,2*i-1));
    }
  }

  mvec C_ = convolution(A_, B_, e);
  REP(i,m/2){
    ret = (mod + ret - n*C_[i].val%mod)%mod;
  }
  cerr<<A_[0]<<" "<<A_[1]<<" "<<A_[2]<<endl;
  cerr<<B_[0]<<" "<<B_[1]<<" "<<B_[2]<<endl;
  cerr<<C_[0]<<" "<<C_[1]<<endl;
  cout<<ret<<endl;
  return 0;
}
