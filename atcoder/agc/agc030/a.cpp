#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

LL a,b,c;

int main(){
  cin>>a>>b>>c;
  cout<<b+min(a+b+1,c)<<endl;
  return 0;
}
