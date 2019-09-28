#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n,k;
double ret=0.0;
int main(){
  cin>>n>>k;
  int b=1,e=0;
  REP(i,n){
    if(b>=max(n,k))break;
    e++;
    b*=2;
  }
  int term=n,init=k;
  b=1;
  REP(i,e+3){
    ret+=(double)(max(0,term-init+1))/(double)n/(double)b;
    //cerr<<i<<" "<<term-init+1<<endl;
    term = term - max(0,term-init+1);
    b*=2;
    init = (k+b-1)/b;
  }
  printf("%.10lf\n",ret);
  return 0;
}
