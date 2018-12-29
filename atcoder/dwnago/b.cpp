#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

#define DIG 41

int n,k;
LL a[1000],s[1001];
int numd[DIG];
bool d[DIG];

int main(){
  cin>>n>>k;
  s[0]=0;
  REP(i,n){
    cin>>a[i];
    s[i+1]=s[i]+a[i];
  }
  REP(i,DIG)
    d[i]=false;

  LL tmp;
  int ind,cap=0;
  vector<int> v;
  REP(l,DIG){
    cap=0;
    ind = DIG-l-1;
    REP(i,n){
      FOR(j,i+1,n+1){
	tmp = s[j]-s[i];
	if(tmp%(1UL<<(ind+1)) < (1UL<<ind))continue;
	if(v.size()==0) cap++;
	REP(p,v.size()){
	  if(tmp%(1UL<<(v[p]+1)) < (1UL<<v[p]))break;
	  if(p == v.size()-1){
	    cap++;
	  }
	}
      }
    }
    if(cap>=k){
      d[ind]=true;
      v.push_back(ind);
    }
  }
  
  LL ret=0;
  REP(i,DIG){
    if(d[i])
      ret+=(1UL<<i);
  }
  cout<<ret<<endl;
  return 0;
}
