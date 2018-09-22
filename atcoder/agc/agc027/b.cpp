#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
LL x_;
LL x[200001];

int main(){
  cin>>n>>x_;
  x[0]=0;
  REP(i,n)
    cin>>x[i+1];
  REP(i,n)
    x[i+1]+=x[i];
  LL ret_min=LLONG_MAX,su=0;
  FOR(k,1,n+1){
    su=0;
    REP(j,n/k+1){
      if(j==0)
	su+=5*(x[n-j*k]-x[n-(j+1)*k]);
      else
	su+=(2*j+3)*(x[n-j*k]-x[max(0,n-(j+1)*k)]);
      if((n+k)*x_+su>ret_min)break;
    }
    ret_min=min(ret_min,(n+k)*x_+su);
  }
  cout<<ret_min<<endl;
  return 0;
}
