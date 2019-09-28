#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int a[200000];
int table[200000];

int main(){
  int n;
  LL k;
  cin>>n>>k;
  REP(i,n){cin>>a[i];pre[i]=-1;}
  REP(i,n){
    if(pre[a[i]]<0)pre[a[i]]=i;
    else {table[pre[a[i]]]=(i+1)%n;pre[a[i]]=i;}
  }
  REP(i,n){
    if(pre[a[i]]<0)pre[a[i]]=i;
    else {table[pre[a[i]]]=(i+1)%n;pre[a[i]]=i;}
  }
  int init=0,per;
  REP(i,n){
    init = table[init];
    if(init==0){per=i;break;}
  }
  k%=per;
  
  return 0;
}
