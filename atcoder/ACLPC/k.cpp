#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,q;

LL mod =998244353;

struct S{
    mint a;
    LL size;
};

S op(S a,S b){
    return S{a.a+b.a,a.size+b.size};
}

S e(){
    return S{0,0};
}

S mapping(function<S(S)> f,S x){
    return f(x);
}

function<S(S)> composition(function<S(S)> f,function<S(S)> g){
    return [f,g](S x){return f(g(x));};
}

function<S(S)> id(){
    return [](S x){return x;};
}

int main(){
    cin>>n>>q;
    vector<S> a(n);
    REP(i,n){
        int a_;
        cin>>a_;
        S m = a_;
        a[i]=m;
    }
    auto seg = atcoder::lazy_segtree<S, op, e, function<S(S)>, mapping, composition, id>(a);
    REP(i,q){   
        int qn;
        cin>>qn;
        REP(i,n){
            cerr<<seg.get(i).val()<<" ";
        }
        cerr<<endl;
        if(qn==0){
            int l,r;
            int b_,c_;
            cin>>l>>r>>b_>>c_;
            mint b = b_,c = c_;
            auto f = [b,c](mint x){return b*x+c;};
            seg.apply(l, r, f);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<seg.prod(l,r).val()<<endl;
        }
    }
}