#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,q;


LL op(LL a, LL b) {
    return max(a, b);
}

LL e() {
    return (LL)(-1e9);
}

int main(){
    cin>>n>>q;
    vector<LL> a(n);
    REP(i,n)cin>>a[i];
    auto seg = atcoder::segtree<LL,op,e>(a);
    REP(i,q){
        LL t,x,v;
        cin>>t>>x>>v;
        if(t==1){
            seg.set((int)x-1,v);
        }else if(t==2){
            cout<<seg.prod((int)x-1, (int)v)<<endl;
        }else{
            auto bs = [v](LL l){return l<v;};
            cout<<1+seg.max_right((int)x-1,bs)<<endl;
        }
    }
}