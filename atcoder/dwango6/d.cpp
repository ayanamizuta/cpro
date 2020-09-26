#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n;
int a[100000];
int main(){
  cin>>n;
  if(n==2){cout<<-1<<endl;return 0;}
  REP(i,n)cin>>a[i];

  return 0;
}
