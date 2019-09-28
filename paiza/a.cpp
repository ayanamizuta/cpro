#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int m,n,s,g;
int d[100];
vector<vector<int>> v(100);

bool dfs(int step,int pos,int prev){
  if(step==0 && pos == g)return true;
  if(step==0)return false;
  bool bl = false;
  REP(i,v[pos].size()){
    if(v[pos][i]==prev)continue;
    bl = bl || dfs(step-1,v[pos][i],pos);
  }
  return bl;
}

int main(){
  cin>>m>>n>>s>>g;
  s--;
  g--;
  REP(i,m)cin>>d[i];
  REP(i,n){
    int x;
    cin>>x;
    REP(j,x){
      int y;
      cin>>y;
      v[i].push_back(y-1);
    }
  }
  REP(i,m){
    if(dfs(d[i],s,-1)){
      cout<<"yes"<<endl;
    }else{
      cout<<"no"<<endl;
    }
  }

  return 0;
}
