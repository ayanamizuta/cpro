#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

LL a[100000];
int n;

int main(){
  cin>>n;
  REP(i,n)
    cin>>a[i];
  REP(i,n){
    if(a[i]%2!=0){
      cout<<"first"<<endl;
      return 0;
    }
  }
  cout<<"second"<<endl;
  return 0;
}
