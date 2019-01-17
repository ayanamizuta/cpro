#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n,h,w;

int main(){
  cin>>n>>h>>w;
  cout<<(n-h+1)*(n-w+1)<<endl;
  return 0;
}
