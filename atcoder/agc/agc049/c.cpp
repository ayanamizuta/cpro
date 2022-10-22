#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

typedef bool S;
S op(S a, S b){ return a && b; }
S e() { return true; }
using F = S;
S mapping(F f, S x){
    return f && x;
}
F composition(F f, F g){
    return f && g;
}
F id(){ return true; }

int n;
LL a[200000],b[200000];
vector<S> a_in;

int main(){
    cin>>n;
    REP(i,n)cin>>a[i];
    REP(i,n)cin>>b[i];
    REP(i,n)a_in.push_back(false);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> segt(a_in);
    REP(i,n){
        if(a[i] <= b[i]){
            segt.set(i,true);
        }else{
            int lb=0,ub=i+1;
            while(lb < ub){
                int mid = (lb+ub)/2;
                if(a[mid] >= a[i]-b[i]){
                    ub = mid;
                }else{
                    lb = mid+1;
                }
            }
            segt.apply(lb,i+1,false);
        }
    }
    bool bl = false;
    REP(i,n){
        //cerr<<i<<" "<<a[i]<<" "<<b[i]<<" "<<segt.get(i)<<endl;
        bl = bl || segt.get(i);
    }
    if(!bl){
        cout<<0<<endl;
        return 0;
    }
    LL ret_min = n,carry=0;
    REP(i_,n){
        int i = n-i_-1;
        if(a[i] <= b[i]){
            //cerr<<i<<" "<<carry<<" "<<b[i]-a[i]+1<<endl;
            ret_min = min(ret_min,max(carry,b[i]-a[i]+1));
            if(!segt.get(i))continue;
            carry++;
        }
    }
    cout<<min(ret_min,carry)<<endl;
}