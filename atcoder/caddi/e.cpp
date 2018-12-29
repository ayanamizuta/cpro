#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long
#define M 12

int n;
LL a[200000];
LL suml[M][200001],sumk[M][200001];

int main(){
  cin>>n;
  REP(i,n){
    cin>>a[i];
  }
  
  LL pow,b,b_;
  REP(i,M)
    sumk[i][n]=0;
  REP(i,M)
    sumk[i][n-1]=i;
  REP(i,n-1){
    b_=1;
    REP(j,M){
      pow=0;
      b=1;
      while(b_*a[n-2-i]>b*a[n-1-i]){
	pow++;
	b*=4;
      }
      sumk[j][n-2-i]=(LL)j+sumk[min((int)pow,M-1)][n-1-i]+max((LL)0,pow-(M-1))*(i+1);
      b_*=4;
    }
  }
  REP(i,M)
    suml[i][0]=0;
  REP(i,M)
    suml[i][1]=i;
  REP(i,n-1){
    b_=1;
    REP(j,M){
      pow=0;
      b=1;
      while(a[i]*b<a[i+1]*b_){
	pow++;
	b*=4;
      }
      suml[j][i+2]=(LL)j+suml[min((int)pow,M-1)][i+1]+max((LL)0,pow-(M-1))*(i+1);
      b_*=4;
    }
  }

  LL ret=10000000000000;
  FOR(i,0,n+1){
    if(i==0)ret=i+2*suml[0][i]+2*sumk[0][i];
    else ret=min(ret,i+2*suml[0][i]+2*sumk[0][i]);
  }
  cout<<ret<<endl;
  return 0;
}
