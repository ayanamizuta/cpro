#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

long long gcd(long long a,long long b){
  if(b==0)return a;
  if(a<b)return gcd(b,a);
  return gcd(b,a%b);
}

long long lcm(long long a,long long b){
  return a*b/gcd(a,b);
}

bool bl=false;

long long solve(long long x1,long long y1,long long x2,long long y2){
  REP(i,y2){
    if((x1+i*y1)%y2==x2)return (x1+i*y1)%lcm(y1,y2);
  }
  bl=true;
  return -1;
}

LL x[3],y[3];

int main(){
  cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];
  LL ret,lc=lcm(y[0],y[1]);
  ret = solve(x[0],y[0],x[1],y[1]);
  ret = solve(ret,lc,x[2],y[2]);
  if(bl){
    cout<<-1<<endl;
    return 0;
  }
  cout<<((ret%(lcm(lc,y[2]))==0)?lcm(lc,y[2]):ret%(lcm(lc,y[2])))<<endl;
  return 0;
}
