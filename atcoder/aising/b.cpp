#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n,a,b;
vector<int> p;

int main(){
  cin>>n>>a>>b;
  int tmp;
  int low=0,mid=0,high=0;
  REP(i,n){
    cin>>tmp;
    p.push_back(tmp);
    if(tmp<=a)low++;
    if(tmp>a && tmp<=b)mid++;
    if(tmp>=b+1)high++;
  }
  cout<<min(low,min(mid,high))<<endl;
  return 0;
}
