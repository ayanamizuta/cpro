#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,k;
LL dp_answer[3001][3001];

LL mod = 998244353;

int main(){
    cin>>n>>k;

    //REP(i,n+1)dp_answer[0][i]=0;
    dp_answer[0][0] = 1;
    FOR(i,1,n+1){
        FOR(jj,1,n+1){
            auto j = n+1-jj;
            dp_answer[i][j] += dp_answer[i-1][j-1];
            if(2*j <= n)dp_answer[i][j] += dp_answer[i][2*j];
            dp_answer[i][j] %= mod;
        }
    }
    /*REP(i,n+1){
        REP(j,k+1)cerr<<dp_answer[i][j]<<" ";
        cerr<<endl;
    }*/
    cout<<dp_answer[n][k]<<endl;
}