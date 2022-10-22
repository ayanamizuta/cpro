#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,k;
vector<int> a;
mint dp[200001];
int main(){
    cin>>n>>k;
    a.resize(n);
    REP(i,n)cin>>a[i];
    sort(ALL(a),greater<int>);
    FOR(i,1,n){
      dp
    }
}