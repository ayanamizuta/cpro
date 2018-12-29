#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long
#define RAND_ITER 100

int a[100][100];
int b[100][100];

int q,q_in;
LL score=1e18,score_in;
int out[1000][3],out_in[1000][3];

void rand_pos(){
  random_device rnd;
  mt19937 mt(rnd());   
  uniform_int_distribution<> rand100(0, 99);
  uniform_int_distribution<> rand1000(1, 1000);
  REP(i,q_in){
    out_in[i][0] = rand100(mt);
    out_in[i][1] = rand100(mt);
    out_in[i][2] = rand1000(mt);
  }
}

void add(int x,int y,int h){
  REP(i,100){
    REP(j,100){
      b[i][j] += max(0,h-abs(x-i)-abs(y-j));
    }
  }
}

LL score_(){
  LL ret=0;
  REP(i,100){
    REP(j,100)
      b[i][j]=0;
  }
  REP(i,q_in){
    REP(j,3){
      add(out_in[i][1],out_in[i][0],out_in[i][2]);
    }
  }
  REP(i,100){
    REP(j,100)
      ret+=abs(a[i][j]-b[i][j]);
  }
  return ret;
}

void out_copy(){
  REP(i,q_in){
    REP(j,3)
      out[i][j]=out_in[i][j];
  }
  score=score_in;
}

void dump(){
  cout<<q<<endl;
  REP(i,q){
    cout<<out[i][0]<<" "<<out[i][1]<<" "<<out[i][2]<<endl;
  }
}

//BTB
int main(){
  REP(i,100){
    REP(j,100)
      cin >> a[i][j];
  }

  q=1000;
  q_in=1000;
  
  REP(i,RAND_ITER){
    rand_pos();
    score_in = score_();
    if(score > score_in)
      out_copy();
    cerr<<score<<endl;
  }
  
  //dump();
  
  return 0;
}
