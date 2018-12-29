#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
string s;
int q;
int k[75];
LL d,m,dm;

int main(){
  cin>>n;
  cin>>s;
  cin>>q;
  REP(i,q)
    cin>>k[i];
  LL ret;
  REP(i,q){
    ret=0;
    d=0;
    m=0;
    dm=0;
    REP(j,n){
      if(j-k[i]>=0){
	if(s[j-k[i]]=='D'){
	  dm-=m;
	  d--;
	}else if(s[j-k[i]]=='M'){
	  m--;
	}
      }
      
      if(s[j]=='D'){
	d++;
      }else if(s[j]=='M'){
	m++;
	dm+=d;
      }else if(s[j]=='C'){
	ret+=dm;
      }
      //cerr<<j<<" "<<d<<" "<<m<<" "<<dm<<endl;
    }
    cout<<ret<<endl;
  }
  return 0;
}
