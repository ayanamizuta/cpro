#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,q;
LL ret=0;
LL tablex[200001],tabley[200001];
bool freex[200001],freey[200001];
int findx,findy;

int main(){
  cin>>n>>q;
  LL fx=n-2,fy=n-2;
  REP(i,200001){
    tablex[i]=n-2;
    tabley[i]=n-2;
    freex[i] = false;
    freey[i] = false;
  }
  findx=n;
  findy=n;
  REP(i,q){
    int qk,coord;
    cin>>qk>>coord;
    if(qk==1){
      FOR(l,coord,n){
        tabley[coord]=0;
        if(freey[l])break;
        freey[l]=true;
        tabley[l]=fx;
        tabley[coord]=0;
      }
      fy = min(fy,(LL)coord-2);
    }else{
      FOR(l,coord,n){
        tablex[coord]=0;
        if(freex[l])break;
        freex[l]=true;
        tablex[l]=fy;
        tablex[coord]=0;
      }
      fx = min(fx,(LL)coord-2);
    }
  }
  FOR(i,2,n){
    if(freex[i])ret+=tablex[i];
    if(freey[i])ret+=tabley[i];
  }
  ret+=fx*fy;
  cout<<ret<<endl;
  return 0;
}
