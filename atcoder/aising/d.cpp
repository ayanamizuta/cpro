#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n,q;
vector<LL> a;
vector<LL> xs;
LL lows[100000],ms[100000];

int main(){
  cin>>n>>q;
  LL tmp;
  REP(i,n){
    cin>>tmp;
    a.push_back(tmp);
  }
  REP(i,q){
    cin>>tmp;
    xs.push_back(tmp);
  }

  lows[0]=0;
  REP(i,(n+1)/2){
    if(n%2==0){
      lows[i+1]=lows[i]+a[1+2*i];
    }else{
      lows[i+1]=lows[i]+a[2*i];
    }
  }
  ms[0]=0;
  REP(i,n){
    ms[i+1]=ms[i]+a[n-1-i];
  }

  LL x;
  REP(i,q){
    x=xs[i];
    if(x-a[0]<=a[n/2]-x){
      cout<<ms[(n+1)/2]<<endl;
      continue;
    }
    if(n>=3 && a[n-3]<=x && abs(x-a[n-3])>abs(a[n-2]-x)){
      cout<<lows[(n+1)/2]<<endl;
      continue;
    }
    int ub=(n+1)/2,lb=1,k=1;
    while(ub!=lb){
      k = lb+(ub-lb)/2;
      if((a[n-k]-x)<(x-a[n-2*k+1])){
	ub=k;
      }else if(n-2*k>=0 && (x-a[n-2*k])<=(a[n-k-1]-x)){
	lb=k+1;
      }else break;
    }
    cout<<ms[k]+lows[(n+1)/2-k]<<endl;
  }
  return 0;
}
