#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t,m,p[95];
LL n[95];
LL sums;
LL max_score=0;

bool is_ok(LL score){
  LL score_ = score;
  LL sums_del=0;
  REP(i,m){
    int cnt=0;
    while(!(score_%p[i])){
      cnt++;
      sums_del+=p[i];
      score_/=p[i];
    }
    if(n[i]<cnt)return false;
  }
  if(score_!=1 || sums-sums_del!=score)return false;
  return true;
}

void search_max_score(){
  max_score=0;
  REP(i,min((LL)10000,sums-1)){
    LL score_cand = sums-i;
    if(is_ok(score_cand))max_score=max(max_score,score_cand);
  }
}

// only verdict 1,2
void solve_one(int problem_num){
    cin>>m;
    sums=0;
    REP(i,m){
      cin>>p[i]>>n[i];
      sums+=p[i]*n[i];
    }
    search_max_score();

    cout<<"Case #"<<problem_num<<": "<<max_score<<endl;
}

int main(){
  cin>>t;
  REP(i,t)solve_one(i+1);
  return 0;
}
