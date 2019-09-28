#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

string s[1000];
int h,w;
int ma;
bool visited[1000][1000];
int score[1000][1000];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void dfs(int bh,int bw){
  int x,y;
  REP(i,4){
    x = dx[i];
    y = dy[i];

    if(!visited[x][y]){
      
    }
  }
}

int main(){
  cin>>h>>w;
  int bh,bw;
  REP(i,h){
    cin>>s[i];
    REP(j,w){
      visited[i][j]=false;
      if(s[i][j]=="#"){bh=i;bw=j;visited[i][j]=true;score[i][j]=0;}
    }
  }
  dfs(bh,bw);

  int lb=0,ub=4000;
  while(true){
    if(ok)
  }
  cout<<ma<<endl;
  return 0;
}
