#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,m,ro,co;
int a[50][50];
int score=0;
bool visited[50][50];
int xs[4]={1,0,-1,0};
int ys[4]={0,1,0,-1};

int dfs(int i,int j,int q){
  int ret=0;
  visited[i][j]=true;
  REP(k,4){
    if((0<=i+xs[k])&&(i+xs[k]<n)&&(0<=j+ys[k])&&(j+ys[k]<n)&&(!visited[i+xs[k]][j+ys[k]])&&(a[i+xs[k]][j+ys[k]]==q))ret+=dfs(i+xs[k],j+ys[k],q);
  }
  return 1+ret;
}

void dfs_elim(int i,int j,int q){
  score+=a[i][j];
  a[i][j]=100000;
  REP(k,4){
    if(0<=i+xs[k]&&i+xs[k]<n&&0<=j+ys[k]&&j+ys[k]<n&&a[i+xs[k]][j+ys[k]]==q)dfs_elim(i+xs[k],j+ys[k],q);
  }
}

bool crop(){
  REP(i,n){
    REP(j,n)visited[i][j]=false;
  }
  REP(i,n){
    REP(j,n){
      if(a[i][j]<=dfs(i,j,a[i][j])){
	ro=i;
	co=j;
	dfs_elim(i,j,a[i][j]);
	return true;
      }
    }
  }
  return false;
}

void min_search(){
  int mi=300000;
  REP(i,n){
    REP(j,n){
      if(mi > a[i][j]){ro=i;co=j;mi=a[i][j];}
    }
  }
}

int main(){
  cin>>n>>m;
  REP(i,n){
    REP(j,n)cin>>a[i][j];
  }
  REP(i,m){
    if(crop()){cout<<2<<" "<<ro<<" "<<co<<endl;continue;}
    min_search();
    cout<<1<<" "<<ro<<" "<<co<<endl;
    a[ro][co]++;
  }
  cerr<<score<<endl;
  return 0;
}
