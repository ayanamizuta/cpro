#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long
#define STRS 1

int n,k;
int a[30000];
string output[STRS];
vector<LL> v_score;



void uni_update(){
  
}

void do_opt(int idx){
  if(idx == 0){
    uni_update();
  }
}

int main(){
  cin>>n>>k;
  REP(i,n){
    cin>>a[i];
    c[i]-=i+1;
  }
  
  REP(i,STRS)
    do_opt(i);

  int opt_idx = distance(v_score.begin(),min_element(v_score.begin(),v_score.end()));

  cout<<output[opt_idx]<<endl;
  
  return 0;
}
