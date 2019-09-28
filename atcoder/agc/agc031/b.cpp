#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,c[200000],ind[200000];
LL cnt[200001];
LL mod = 1000000007;
int main(){
  cin>>n;
  REP(i,n){cin>>c[i];c[i]--;}
  REP(i,200000)ind[i]=-1;
  cnt[0]=1;
  REP(i,n){
    //cerr<<ind[c[i]]<<" "<<cnt[i]<<endl;
    if(ind[c[i]] == -1 || c[i-1]==c[i])cnt[i+1]=cnt[i];
    else cnt[i+1]=(cnt[i]+cnt[ind[c[i]]])%mod;
    ind[c[i]]=i+1;
  }
  cout<<cnt[n]<<endl;
  return 0;
}
