#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,m,k;

int main(){
    cin>>n>>m>>k;
    if(n==1){
        mint ret = k;
        ret = ret.pow(m);
        cout<<ret.val()<<endl;
        return 0;
    }else if(m==1){
        mint ret = k;
        ret = ret.pow(n);
        cout<<ret.val()<<endl;
        return 0;
    }else{
        mint ret = 0;
        FOR(i,1,k+1){
            mint a = i,b = i-1,c = k-b;
            ret += c.pow(m)*(a.pow(n) - b.pow(n));
        }
        cout<<ret.val()<<endl;
        return 0;
    }
}