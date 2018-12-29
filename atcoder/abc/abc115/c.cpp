#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long
int n,k;
vector<LL> h;

int main(){
  cin>>n>>k;
  LL tmp;
  REP(i,n){
    cin>>tmp;
    h.push_back(tmp);
  }
  sort(h.begin(),h.end());
  LL ret = 10000000000000000;
  for(int i=0;i<h.size()-k+1;i++){
    ret = min(ret,h[k+i-1]-h[i]);
  }
  cout<<ret<<endl;
  return 0;
}
