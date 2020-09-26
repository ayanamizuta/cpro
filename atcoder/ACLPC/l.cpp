#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
template<class T,class U> inline bool chmin(T&x,U y){if(x>y){x=y;return true;}return false;}
template<class T,class U> inline bool chmax(T&x,U y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)
using mint=modint998244353;
struct S{
    ll t,o,l;
};
using P=bool;
S op(S a,S b){
    return {a.t+b.t+a.l*b.o,a.o+b.o,a.l+b.l};
}

S e(){
    return {0,0,0};
}

S mp(P f,S x){
    if(f) return {x.o*x.l-x.t,x.l,x.o};
    return x;
}

P cp(P f,P g){
    return f?!g:g;
}

P id(){
    return false;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<S> a;
    a.reserve(n);
    {
        int A;
        fr(i,n){
            cin>>A;
            if(A) a.push_back(S{0,0,1});
            else a.push_back(S{0,1,0});
        }
    }
    lazy_segtree<S,op,e,P,mp,cp,id> sg(a);
    int t,l,r;
    fr(_,q){
        cin>>t>>l>>r;
        if(t-1) cout<<sg.prod(l-1,r).t<<'\n';
        else sg.apply(l-1,r,true);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
