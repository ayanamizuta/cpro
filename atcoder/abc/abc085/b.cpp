#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
set<int> s;
int main(){
  cin>>n;
  int tmp;
  REP(i,n){
    cin>>tmp;
    s.insert(tmp);
  }
  cout<<s.size()<<endl;
  return 0;
}
