#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int h,w;
string s[300];
LL ret=0;


int main(){
  cin>>h>>w;
  REP(i,h)
    cin>>s[i];
  int d1,d2,d3;
  //kuso-code
  REP(i1,h){
    REP(i2,w){
      REP(j1,h){
	REP(j2,w){
	  REP(k1,h){
	    REP(k2,w){
	      d1=abs(i1-j1)+abs(i2-j2);
	      d2=abs(i1-k1)+abs(i2-k2);
	      d3=abs(j1-k1)+abs(j2-k2);
	      if(d1==0)break;
	      if(d1!=d2 || d2!=d3)break;
	      if(s[i1][i2]=='#' && s[j1][j2]=='#' && s[k1][k2]=='#'){
		ret++;
		cerr<<i1<<" "<<i2<<" "<<j1<<" "<<j2<<" "<<k1<<" "<<k2<<endl;
	      }
	    }
	  }
	}
      }
    }
  }
  cout<<ret/6<<endl;
  return 0;
}
