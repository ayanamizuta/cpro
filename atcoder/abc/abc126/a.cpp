#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n;
int k;
string s;

int main(){
  cin>>n>>k>>s;
  s[k-1]=s[k-1]+32;
  cout<<s<<endl;
  return 0;
}
