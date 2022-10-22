#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t,n,q;
int score[3];
string s[3];
char chars[2] = {'F','T'};

// only visible verdict
bool feasible[1024];
int feasible_num;
int max_score;
string max_score_str;

int gcd_(int a,int b){
  if(a<b)return gcd_(b,a);
  if(!b)return a;
  return gcd_(b,a%b);
}

string reduce_frac(int a,int b){
  int c = gcd_(a, b);
  return to_string(a/c)+"/"+to_string(b/c);
}

void init_feasible(){
  REP(i,1<<q){
    int score_[3] = {0,0,0};
    REP(j,n){
      REP(k,q){
        score_[j] += (s[j][k] == chars[(i>>k)%2])?1:0;
      }
    }
    bool bl=true;
    REP(j,n){
      if(score_[j] != score[j])bl=false;
    }
    feasible[i] = bl;
  }
  feasible_num=0;
  REP(i,1<<q)feasible_num+=feasible[i]?1:0;
}

int calc_score(int i){
  int ret=0;
  REP(j,1<<q){
    if(!feasible[j])continue;
    REP(k,q){
      ret+=((i>>k)%2 == (j>>k)%2)?1:0;
    }
  }
  return ret;
}

void search_max_score(){
  int cand=-1,max_score_ = -1;
  REP(i,1<<q){
    int score_ = calc_score(i);
    if(max_score_ < score_){
      max_score_ = score_;
      cand = i;
    }
  }
  max_score = max_score_;
  max_score_str = "";
  REP(i,q){
    max_score_str += (cand>>i)%2?"T":"F";
  }
}

// only visible verdict
void solve_one(int problem_num){
  cin>>n>>q;
  REP(i,n)cin>>s[i]>>score[i];
  init_feasible();
  search_max_score();

  cout<<"Case #"<<problem_num<<": "<<max_score_str<<" "<<reduce_frac(max_score,feasible_num)<<endl;
}
int main(){
  cin>>t;
  REP(i,t)solve_one(i+1);
  return 0;
}
