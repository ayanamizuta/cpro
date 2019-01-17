#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

string s[400];
bool v[400][400];
vector<vector<int>> ans;
vector<vector<int>> ans_sub;
int h,w,cur=0;

void dfs(int i,int j,char c){
  if(v[i][j])return;
  if(c=='.'){
    ans_sub[cur].push_back((i*w+j));
  }
  if(c=='#'){
    ans[cur].push_back(i*w+j);
  }
  v[i][j]=true;
  if(i-1>=0 && !v[i-1][j] && s[i-1][j]!=c)dfs(i-1,j,s[i-1][j]);
  if(i+1<h && !v[i+1][j] && s[i+1][j]!=c)dfs(i+1,j,s[i+1][j]);
  if(j-1>=0 && !v[i][j-1] && s[i][j-1]!=c)dfs(i,j-1,s[i][j-1]);
  if(j+1<w && !v[i][j+1] && s[i][j+1]!=c)dfs(i,j+1,s[i][j+1]);
}

int main(){
  cin>>h>>w;
  REP(i,h)
    cin>>s[i];

  REP(i,h){
    REP(j,w)
      v[i][j]=false;
  }

  REP(i,h){
    REP(j,w){
      if(v[i][j])continue;
      vector<int> p1;
      vector<int> p2;
      ans.push_back(p1);
      ans_sub.push_back(p2);
      cur=ans.size()-1;
      dfs(i,j,s[i][j]);
    }
  }
  
  LL ret=0;
  REP(i,ans.size()){
    ret+=(LL)(ans[i].size()*ans_sub[i].size());
  }
  cout<<ret<<endl;
  return 0;
}
