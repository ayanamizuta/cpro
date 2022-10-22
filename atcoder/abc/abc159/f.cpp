#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,s,a[3000];
mint table[3001];

int main(){
    cin>>n>>s;
    REP(i,n)cin>>a[i];
    REP(i,s+1)table[i]=0;
    mint ans=0;

    REP(i,n){
      table[0]+=1;
      REP(j,s+1){
        if(s-j+a[i]<=s)table[s-j+a[i]]+=table[s-j];
      }
      ans+=table[s];
    }
    cout<<ans.val()<<endl;
}