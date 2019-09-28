#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
string s[2000];
int h,w;
int u[2001][2001],d[2001][2001],l[2001][2001],r[2001][2001];
int main(){
  cin>>h>>w;
  REP(i,h)cin>>s[i];
  REP(i,h){
    REP(j,w){
      if(s[i][j]=='#')l[i][j]=0;
      else if(j==0)l[i][j]=(s[i][j]=='#')?0:1;
      else l[i][j]=l[i][j-1]+1;
    }
  }
  REP(i,h){
    REP(j,w){
      if(s[i][w-1-j]=='#')r[i][w-1-j]=0;
      else if(j==0)r[i][w-1-j]=(s[i][w-1-j]=='#')?0:1;
      else r[i][w-1-j]=r[i][w-j]+1;
    }
  }
  REP(j,w){
    REP(i,h){
      if(s[i][j]=='#')u[i][j]=0;
      else if(i==0)u[i][j]=(s[i][j]=='#')?0:1;
      else u[i][j]=u[i-1][j]+1;
    }
  }
  REP(j,w){
    REP(i,h){
      if(s[h-1-i][j]=='#')d[h-1-i][j]=0;
      else if(i==0)d[h-1-i][j]=(s[h-1-i][j]=='#')?0:1;
      else d[h-1-i][j]=d[h-i][j]+1;
    }
  }
  /*
  REP(i,h){
    REP(j,w){
      cerr<<u[i][j]<<" ";
    }
    cerr<<endl;
  }
  REP(i,h){
    REP(j,w){
      cerr<<d[i][j]<<" ";
    }
    cerr<<endl;
  }
  REP(i,h){
    REP(j,w){
      cerr<<l[i][j]<<" ";
    }
    cerr<<endl;
  }
  REP(i,h){
    REP(j,w){
      cerr<<r[i][j]<<" ";
    }
    cerr<<endl;
  }
  */


  int ret=0;
  REP(i,h){
    REP(j,w){
      ret=max(ret,u[i][j]+d[i][j]+l[i][j]+r[i][j]-3);
    }
  }
  cout<<ret<<endl;
  return 0;
}
