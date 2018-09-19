#include "bits/stdc++.h"
using namespace std;

#define RESIDUE(u,v) (capacity[u][v] - flow[u][v])
#define RCOST(u,v) (cost[u][v] + h[u] - h[v])
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

#define SEGSIZE 200000
#define INPUT_SIZE 100000

//max segt
//segt[best]->max value

int segt[SEGSIZE];
int input[INPUT_SIZE];
int depth=0;
int best=0;
int start=0;

int par(int i){
  if(i==0)
    return -1;
  return (i-1)/2;
}

void update(int d,int x){
  int i=d+start;
  segt[i]=x;
  while(par(i)!=-1){
    segt[par(i)]=max(segt[i],segt[(i+1)/2*4-1-i]);
    i=par(i);
  }
  i=0;
  while(i<start){
    i=(segt[i]==segt[2*i+1])?2*i+1:2*i+2;
  }
  best=i-start;
}

void init(int n){
  while((1<<depth)<n){
    depth++;
  }
  start=(1<<depth)-1;
  REP(i,1<<(depth+1)){
    if(i<start)
      segt[i]=0;
    else if(i<start+n)
      segt[i]=input[i-start];
    else
      segt[i]=-INT_MAX;
  }
  FOR(i,start,start+n){
    int tmp=i;
    while(par(tmp)!=-1){
      segt[par(tmp)]=max(segt[tmp],segt[(tmp+1)/2*4-1-tmp]);
      tmp=par(tmp);
    }
  }
  int i=0;
  while(i<start){
    i=(segt[i]==segt[2*i+1])?2*i+1:2*i+2;
  }
  best=i-start;
}


int main(){
  return 0;
}
