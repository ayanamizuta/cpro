#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

LL a[100000],b[100000];
int n;
vector<LL> v;

int main(){
  cin>>n;
  REP(i,n)
    cin>>a[i]>>b[i];
  REP(i,n){
    v.push_back(a[i]);
    v.push_back(b[i]);
  }
  sort(v.begin(),v.end());
  
  LL ret=LLONG_MAX,tmp=0;
  REP(i,n)
    tmp+=a[i];
  ret=min(ret,tmp);
  tmp=0;
  REP(i,n)
    tmp+=b[i];
  ret=min(ret,tmp);
  tmp=0;

  LL su=0;
  REP(i,n){
    su+=v[i];
  }
  REP(i,n){
    tmp=0;
    auto it = lower_bound(v.begin(),v.end(),a[i]);
    int d = distance(v.begin(),it);
    auto it2 = lower_bound(v.begin(),v.end(),b[i]);
    int d2 = distance(v.begin(),it2);
    if(d < n && d2 < n && !(d == n-1 && d2 == n-1)){
      tmp = su;
    }else if(d == n-1 && d2 == n-1){
      tmp = su + b[i] - v[n-2];
    }else{
      if(d >= n && d2 >= n){
	tmp = su + a[i] + b[i] - v[n-1] - v[n-2];
      }else if(d >= n){
	tmp =(d2==n-1)? su + a[i] - v[n-2]:su + a[i] - v[n-1];
      }else if(d2 >= n){
	tmp =(d==n-1)? su + b[i] - v[n-2]:su + b[i] - v[n-1];
      }
    }
    //cerr<<tmp<<endl;
    ret=min(ret,tmp);
  }
  cout<<ret<<endl;
  return 0;
}
