#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
int main(){
    cin>>n;
    mint ret;
    REP(i,n){
      auto conv = atcoder::convolution(deq[0],deq[1]);
    }

    cout<<ret.val()<<endl;
}