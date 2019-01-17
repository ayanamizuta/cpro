#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
vector<LL> a,b,suf,sor;
int sufnum=0,sornum=0;

int main(){
  cin>>n;
  LL tmp;
  REP(i,n){
    cin>>tmp;
    a.push_back(tmp);
  }
  REP(i,n){
    cin>>tmp;
    b.push_back(tmp);
  }
  REP(i,n){
    if(a[i]<b[i]){
      sufnum++;
      suf.push_back(b[i]-a[i]);
      sor.push_back(0);
    }else{
      sor.push_back(a[i]-b[i]);
      suf.push_back(0);
    }
  }

  
  sort(suf.begin(),suf.end());
  LL sum=0;
  REP(i,n){
    sum+=suf[i];
  }
  sort(sor.begin(),sor.end());
  REP(i,n){
    if(sum<=0)break;
    sum-=sor[n-1-i];
    sornum++;
  }
  if(sum>0){
    cout<<-1<<endl;
    return 0;
  }
  cout<<sufnum+sornum<<endl;
  return 0;
}
