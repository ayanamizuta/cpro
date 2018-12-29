#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long
#define FRAME (4+8)

int last = 900;
int framex[FRAME];
int framey[FRAME];
int a[100][100],a_[100][100];
int q;
int maxx,maxy,h;
int out[1000][3];

int bound_(int num){
  if(num<300)
    return 80;
  else if(num<400)
    return 60;
  else if(num<600)
    return 60;
  else if(num<700)
    return 60;
  else
    return 30;
  return 100;
}

void max_elem(){
  int ret,max_=0;
  REP(i,100){
    REP(j,100){
      if(max_<a[i][j]){
	maxx=i;
	maxy=j;
	max_=a[i][j];
      }
    }
  }
}

bool ok(int x,int y){
  return x>=0 && x<100 && y>=0 && y<100;
}

void height(int num){
  //int framex[FRAME] = {0,1,0,-1};
  //int framey[FRAME] = {1,0,-1,0};
  int ret=1000000;
  REP(i,FRAME){
    if(ok(maxx+framex[i],maxy+framey[i]))
      ret=min(ret,a[maxx+framex[i]][maxy+framey[i]]);
  }
  if(num>last)
    h=min(max(1,min(100,ret+1)),bound_(num));
  else{
    h=100;
    h =min(h,bound_(num));
  }
}

void elim(){
  REP(i,100){
    REP(j,100){
      a[i][j] -= max(0,h-abs(maxx-i)-abs(maxy-j));
    }
  }
}

LL score_(){
  LL ret=0;
  REP(i,100){
    REP(j,100)
      ret+=abs(a[i][j]);
  }
  return ret;
}

void dump(){
  cout<<q<<endl;
  REP(i,q){
    cout<<out[i][0]<<" "<<out[i][1]<<" "<<out[i][2]<<endl;
  }
}

void initframe(){
  int cnt=0;
  int bnd=1;
  char rot = 'R';
  int x=0,y=bnd;
  while(cnt<FRAME){
    framex[cnt]=x;
    framey[cnt]=y;
    if(rot == 'R'){
      y--;
      x++;
      if(y==0)
	rot='D';
    }else if(rot == 'D'){
      y--;
      x--;
      if(x==0)
	rot='L';
    }else if(rot == 'L'){
      y++;
      x--;
      if(y==0)
	rot='U';
    }else{
      y++;
      x++;
      if(x==0){
	rot='R';
	bnd++;
	y++;
      }
    }
    cnt++;
  }
}

//BTB
int main(){
  initframe();
  REP(i,100){
    REP(j,100){
      cin >> a[i][j];
      a_[i][j] = a[i][j];
    }
  }

  q=1000;
  
  REP(i,q){
    max_elem();
    height(i);
    out[i][0]=maxy;
    out[i][1]=maxx;
    out[i][2]=h;
    elim();
  }
  
  dump();

  cerr<<score_()<<endl;
  return 0;
}
