#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

// struct mint{
//     static const long long MOD = 998244353;

//     long long v;

//     mint() : v(0) {}
//     mint(long long x){
//         x = x % MOD;
//         if(x < 0){ x += MOD; }
//         v = x;
//     }
//     mint& operator+=(mint a){
//         v += a.v;
//         if(v >= MOD){ v -= MOD; }
//         return *this;
//     }
//     mint& operator*=(mint a){
//         v *= a.v;
//         v %= MOD;
//         return *this;
//     }
//     mint& operator-=(mint a){
//         v -= a.v;
//         if(v < 0){ v += MOD; }
//         return *this;
//     }
//     mint& operator/=(mint a){
//         return (*this) *= a.inv();
//     }

//     mint operator*(mint a) const{
//         return mint(v) *= a;
//     }

//     mint operator+(mint a) const {
//         return mint(v) += a;
//     }

//     mint operator-(mint a) const {
//         return mint(v) -= a;
//     }

//     mint operator/(mint a) const {
//         return mint(v) /= a;
//     }

//     mint pow(long long k) const {
//         mint res(1),tmp(v);
//         while(k){
//             if(k&1) res *= tmp;
//             tmp *= tmp;
//             k >>= 1;
//         }
//         return res;
//     }
//     mint inv(){return pow(MOD - 2); }

//     static mint comb(long long n, int k){
//         mint res(1);
//         for(int i = 0; i < k; ++i){
//             res *= mint(n - i);
//             res /= mint(i + 1);
//         }
//         return res;
//     }

//     static mint factorial(long long n){
//         mint res(1);
//         for(int i = n; i > 1; --i){
//             res *= mint(i);
//         }
//         return res;
//     }

//     bool operator<(const mint &a) const {
//         return v < a.v;
//     };
// };

// mint operator*(long long l, mint r){ return r * l; }

// std::ostream& operator<<(std::ostream& stream, const mint& m){
//     stream << m.v;
//     return stream;
// }

using mint = modint998244353;

struct S{
    mint a;
    ll size;
};
S op(S a, S b){ return S{a.a + b.a, a.size + b.size}; }
S e() { return S{0, 0}; }
using F = pair<mint, mint>;
S mapping(F f, S x){
    return S{f.first * x.a + f.second * x.size, x.size};
}
F composition(F f, F g){
    return F(f.first * g.first, f.first * g.second + f.second);
}
F id(){ return F(1, 0); }

int main(){
    ll n, q;
    cin >> n >> q;
    vector<S> a(n);
    REP(i, n){
        ll ai;
        cin >> ai;
        a.at(i) = S{ai, 1};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    REP(i, q){
        ll t;
        cin >> t;
        if(t == 0){
            ll l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.apply(l, r, F(b, c));
        }else{
            ll l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).a.val() << endl;
        }
    }
    return 0;
}
