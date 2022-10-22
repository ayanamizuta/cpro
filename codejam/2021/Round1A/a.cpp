#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t,n;
LL x[100];

void solve_one(int problem_num){
    cin>>n;
    REP(i,n)cin>>x[i];
    int ret=0;

    cout<<"Case #"<<problem_num<<": "<<ret<<endl;
}

int main(){
  cin>>t;
  REP(i,t)solve_one(i+1);
  return 0;
}
