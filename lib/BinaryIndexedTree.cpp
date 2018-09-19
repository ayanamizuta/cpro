#include "bits/stdc++.h"
using namespace std;

//

#define RESIDUE(u,v) (capacity[u][v] - flow[u][v])
#define RCOST(u,v) (cost[u][v] + h[u] - h[v])
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

#define N 100000

int bit[N+1];

int sum(int i){
  ins ret = 0;
  while(i>0){
    ret += bit[i];
    i -= i & -i;
  }
  return ret;
}

void add(int i,int x){
  while(i<=N){
    bit[i] += x;
    i += i & -i;
  }
}

int main(){
  return 0;
}
