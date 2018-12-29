#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

#define THRES 2000

LL dp1[2001][2001],dp2[2001][2001];
LL x[2001],y[200001],l,di1=0,di2=0;
int n;
int main(){
  cin>>l>>n;
  if(n>=THRES){
    REP(i,n){
      cin>>y[i+1];
    }
    REP(i,THRES){
      x[i+1]=y[i+1];
    }
    di1 = y[n-THRES];
    di2 = l-y[THRES+1];
    FOR(i,1,THRES+1){
      if(i+1<=THRES)
	dp1[1][i]=max(x[i+1]-x[i],l-(x[i+1]-x[i]));
      if(i-1>=1)
	dp2[1][i]=max(x[i]-x[i-1],l-(x[i]-x[i-1]));
    }
    FOR(i,2,THRES){
      FOR(j,1,THRES+1){
	if(j+i<=THRES)
	  dp1[i][j]=max(x[j+1]-x[j]+dp1[i-1][j+1],l-(x[j+i]-x[j])+dp2[i-1][j+i]);
	if(j-i>=1)
	  dp2[i][j]=max(x[j]-x[j-1]+dp2[i-1][j-1],l-(x[j]-x[j-i])+dp1[i-1][j-i]);
      }
    }
    di2+=max(x[1]+dp1[THRES-1][1],l-x[THRES]+dp2[THRES-1][THRES]);


    REP(i,THRES){
      x[i+1]=y[n-THRES+i+1]-y[n-THRES];
    }
    di1 = y[n-THRES];
    FOR(i,1,THRES+1){
      if(i+1<=THRES)
	dp1[1][i]=max(x[i+1]-x[i],l-(x[i+1]-x[i]));
      if(i-1>=1)
	dp2[1][i]=max(x[i]-x[i-1],l-(x[i]-x[i-1]));
    }
    FOR(i,2,n){
      FOR(j,1,THRES+1){
	if(j+i<=THRES)
	  dp1[i][j]=max(x[j+1]-x[j]+dp1[i-1][j+1],l-(x[j+i]-x[j])+dp2[i-1][j+i]);
	if(j-i>=1)
	  dp2[i][j]=max(x[j]-x[j-1]+dp2[i-1][j-1],l-(x[j]-x[j-i])+dp1[i-1][j-i]);
      }
    }
    di1+=max(x[1]+dp1[THRES-1][1],l-x[THRES]+dp2[THRES-1][THRES]);

    
    cout<<max(di1,di2)<<endl;
    return 0;
  }
  REP(i,n){
    cin>>x[i+1];
  }
  FOR(i,1,n+1){
    if(i+1<=n)
      dp1[1][i]=max(x[i+1]-x[i],l-(x[i+1]-x[i]));
    if(i-1>=1)
      dp2[1][i]=max(x[i]-x[i-1],l-(x[i]-x[i-1]));
  }
  FOR(i,2,n){
    FOR(j,1,n+1){
      if(j+i<=n)
	dp1[i][j]=max(x[j+1]-x[j]+dp1[i-1][j+1],l-(x[j+i]-x[j])+dp2[i-1][j+i]);
      if(j-i>=1)
	dp2[i][j]=max(x[j]-x[j-1]+dp2[i-1][j-1],l-(x[j]-x[j-i])+dp1[i-1][j-i]);
    }
  }
  cout<<max(x[1]+dp1[n-1][1],l-x[n]+dp2[n-1][n])<<endl;
  return 0;
}
