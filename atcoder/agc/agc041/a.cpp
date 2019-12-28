#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

LL n,a,b;

int main(){
  cin>>n>>a>>b;
  if(a < b){
    LL tmp = a;
    a = b;
    b = tmp;
  }
  if((a - b) % 2 == 0){
    cout<<(a-b)/2<<endl;
    return 0;
  }
  LL ret = (a + b - 2 + 1)/2;
  ret = min(ret,(n-a+n-b+1)/2);
  cout<<ret<<endl;
  return 0;
}
