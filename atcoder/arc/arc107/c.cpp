#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,k;
int a[50][50];

int cntx[50],cnty[50];

LL mod = 998244353;

LL fact(int x){
    if(x==0)return 1;
    return (x*fact(x-1))%mod;
}

int main(){
    cin>>n>>k;
    REP(i,n){
        cntx[i] =0;
        cnty[i] =0;
        REP(j,n)cin>>a[i][j];
    }
    auto ufx = atcoder::dsu(n);
    auto ufy = atcoder::dsu(n);

    REP(i,n){
        REP(j,n){
            bool bl = true;
            REP(kk,n){
                if(a[i][kk] + a[j][kk] > k)bl = false;
            }
            if(bl)ufx.merge(i, j);
        }
    }
    //REP(i,n)cerr<<ufx.leader(i)<<" ";
    //cerr<<endl;

    REP(i,n)cntx[ufx.leader(i)]++;

    REP(i,n){
        REP(j,n){
            bool bl = true;
            REP(kk,n){
                if(a[kk][i] + a[kk][j] > k)bl = false;
            }
            if(bl)ufy.merge(i, j);
        }
    }
    //REP(i,n)cerr<<ufy.leader(i)<<" ";
    //cerr<<endl;

    REP(i,n)cnty[ufy.leader(i)]++;
    
    LL ret = 1;
    REP(i,n)ret = (ret*fact(cntx[i]))%mod;
    REP(i,n)ret = (ret*fact(cnty[i]))%mod;

    cout<<ret%mod<<endl;
}