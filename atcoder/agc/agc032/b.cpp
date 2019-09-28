#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;

int main(){
  cin>>n;
  if(n%2==0){
    cout<<n*(n-1)/2-n/2<<endl;
    REP(i,n){
      FOR(j,i+1,n){
	if(i+j!=n-1)
	  cout<<i+1<<" "<<j+1<<endl;
      }
    }
  }else{
    cout<<(n-1)*(n-2)/2-(n-1)/2+n-1<<endl;
    REP(i,n-1){
      FOR(j,i+1,n-1){
	if(i+j!=n-2)
	  cout<<i+1<<" "<<j+1<<endl;
      }
    }
    REP(i,n-1)cout<<i+1<<" "<<n<<endl;
  }
  return 0;
}
