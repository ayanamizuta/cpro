//#include "bits/stdc++.h"
#include <string.h>
#include <iostream>
#include <random>
#include <sys/time.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long
#define N 500
#define M 27
#define L 300

int n=N,m=M,l=L;
int dx,dy,maxscore=-1;
string s[N];
char board[M+2][M+2];
int cnt[M+2][M+2],cnt_max[M+2][M+2];
bool ignore[M+2][M+2];

double st;

double getTime(){
  timeval tv;
  gettimeofday(&tv, 0);
  return tv.tv_sec + tv.tv_usec * 0.000001 - st;
}

int count__(){
  int ret=0;
  REP(i,m+2){
    REP(j,m+2){
      switch(cnt[i][j]){
      case 1:
	ret+=10;
	break;
      case 2:
	ret+=3;
	break;
      case 3:
	ret+=1;
	break;
      default:
	break;
      }
    } 
  }
  return ret;
}

char rot(char di,char r){
  if(r=='R'){
    if(di=='U')
      return 'R';
    if(di=='R')
      return 'D';
    if(di=='D')
      return 'L';
    return 'U';
  }else{
    if(di=='U')
      return 'L';
    if(di=='R')
      return 'U';
    if(di=='D')
      return 'R';
    return 'D';
  }
}

void rotset(char di){
  if(di=='U'){
    dx=-1;
    dy=0;
  }else if(di=='R'){
    dx=0;
    dy=1;
  }else if(di=='D'){
    dx=1;
    dy=0;
  }else{//L
    dx=0;
    dy=-1;
  }
}

int count_(){
  REP(i,m+2){
    REP(j,m+2){
      cnt[i][j]=0;
    }
  }

  int x,y;
  char di,bo;
  REP(i,n){
    x=m/2+1;
    y=m/2+1;
    di='U';
    bo = board[x][y];
    REP(j,l){
      if(s[i][j]=='S'){//run
	rotset(di);
	if(bo=='D'){
	  if(board[x+dx][y+dy]=='#') continue;
	  x+=dx;
	  y+=dy;
	  if(board[x+dx][y+dy]=='#') continue;
	  x+=dx;
	  y+=dy;
	}else if(bo=='T'){
	  if(board[x+dx][y+dy]=='#') continue;
	  x+=dx;
	  y+=dy;
	  if(board[x+dx][y+dy]=='#') continue;
	  x+=dx;
	  y+=dy;
	  if(board[x+dx][y+dy]=='#') continue;
	  x+=dx;
	  y+=dy;
	}else{
	  if(board[x+dx][y+dy]=='#') continue;
	  x+=dx;
	  y+=dy;
	}
      }else{//rot
	if(bo=='D'){
	  di = rot(di,s[i][j]);
	  di = rot(di,s[i][j]);
	}else if(bo=='T'){
	  di = rot(di,s[i][j]);
	  di = rot(di,s[i][j]);
	  di = rot(di,s[i][j]);
	}else if(bo=='L'){
	  di = rot(di,'L');
	}else if(bo=='R'){
	  di = rot(di,'R');
	}else{
	  di = rot(di,s[i][j]);
	}
      }
    }
    cnt[x][y]+=1;
  }
  
  return count__();
}

void dump_cnt(){
  FOR(i,1,m+1){
    FOR(j,1,m+1)
      cerr<<cnt_max[i][j];
    cerr<<endl;
  }
}

int framex[4]={0,1,0,-1};
int framey[4]={1,0,-1,0};

int max_cnt(int i,int j){
  int ret = cnt_max[i][j];
  REP(k,4)
    ret=max(ret,cnt_max[i+framex[k]][j+framey[k]]);
  return ret;
}

int maxx=0,maxy=0;


void randboard(){
  int max_=0;
  maxx=0,maxy=0;
  FOR(i,1,m+1){
    FOR(j,1,m+1){
      //if(max_<max_cnt(i,j) && !ignore[i][j]){
      if(max_<cnt_max[i][j] && !ignore[i][j]){
	max_=cnt_max[i][j];
	maxx=i;
	maxy=j;
      }
    }
  }

  ignore[maxx][maxy]=true;

  board[maxx][maxy]='#';
}

void copy(){
  REP(i,m+2){
    REP(j,m+2){
      ignore[i][j]=false;
      cnt_max[i][j]=cnt[i][j];
    }
  }
}

void dump(){
  REP(i,m+2){
    REP(j,m+2)
      cout<<board[i][j];
    cout<<endl;;
  }
}

void clear_ignore(){
  REP(i,m+2){
    REP(j,m+2){
      ignore[i][j]=false;
    }
  }
}

void solve(){
  int max_cand;
  int a=0;
  clear_ignore();
  for (int iter = 0; iter % 100 != 0 || getTime() < 2.9; iter++) {
    randboard();
    max_cand = count_();
    if(maxscore<max_cand){
      maxscore=max_cand;
      copy();
    }else
      board[maxx][maxy]='L';
  }
}

int main(){
  timeval tv;
  gettimeofday(&tv, 0);
  st = tv.tv_sec + tv.tv_usec * 0.000001;
  cin>>n>>m>>l;
  m-=2;
  REP(i,n)
    cin>>s[i];
  REP(i,m+2){
    board[0][i]='#';
    board[i][0]='#';
    board[m+1][i]='#';
    board[i][m+1]='#';
  }
  FOR(i,1,m+1){
    FOR(j,1,m+1){
      board[i][j]='L';
    }
  }
  count_();
  copy();

  solve();
  dump();
  cerr<<maxscore<<endl;
  dump_cnt();
  return 0;
}
