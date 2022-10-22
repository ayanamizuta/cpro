#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t,n,c;
int ret[100],costs[100],index_[100];

void array_with_costs(){
  REP(i,n){
    index_[i]=i;
    ret[i]=0;
  }
  REP(i,n-1){
    int c = costs[i];
    ret[index_[i+c-1]]=i+1;
    REP(j,c/2)swap(index_[i+j],index_[i+c-1-j]);
  }
  ret[index_[n-1]]=n;
}

void render_ret(){
  REP(i,n){
    if(!i)cout<<ret[i];
    else cout<<" "<<ret[i];
  }
}

void solve_one(int problem_num){
    cin>>n>>c;
    if(!(c>=n-1 && n*(n+1)/2-1>=c)){
      cout<<"Case #"<<problem_num<<": IMPOSSIBLE"<<endl;
      return;
    }

    REP(i,n-1)costs[i]=n-i;
    int red = n*(n+1)/2-1-c;
    REP(i,n-1){
      if(!red)break;
      int afford = costs[n-2-i]-1;
      if(afford <= red){
        red -= afford;
        costs[n-2-i] -= afford;
      }else{
        costs[n-2-i] -= red;
        red=0;
      }
    }
    array_with_costs();

    cout<<"Case #"<<problem_num<<": ";
    render_ret();
    cout<<endl;
}

int main(){
  cin>>t;
  REP(i,t)solve_one(i+1);
  return 0;
}
