#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n;
int a[100000];
int v[100000];

int main(){
  cin >> n;
  REP(i,n)cin>>a[i];
  REP(i,n)v[a[i]-1]=i+1;
  REP(i,n){
    if(i==n-1)cout<<v[i];
    else cout<<v[i]<<" ";
  }
  cout<<endl;
  return 0;
}
