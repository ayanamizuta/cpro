#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n,x;
int b[100000],l[100000],u[100000];
LL dept=0;
vector<pair<int,LL>> v;

bool ok(LL m){
  int fills = min(n,(int)(m/(LL)x));
  LL  res   = m%(LL)x;
  if(fills==n)return true;

  LL defaultdel = 0;
  REP(j,fills){
    int i = v[j].first;
    defaultdel += (LL)l[i]*(LL)b[i]+(LL)(x-b[i])*(LL)u[i];
  }
  REP(j,n){
    int i = v[j].first;
    int nexti = v[fills].first;
    LL del=0;
    if(res < b[i])
      del += (LL)(res)*(LL)l[i];
    else
      del += (LL)l[i]*(LL)b[i]+(LL)(res-b[i])*(LL)u[i];
    if(j >= fills)del += defaultdel;
    else del += defaultdel - ((LL)l[i]*(LL)b[i]+(LL)(x-b[i])*(LL)u[i]) +((LL)l[nexti]*(LL)b[nexti]+(LL)(x-b[nexti])*(LL)u[nexti]);

    if(dept <= del)return true;
  }
  return false;
  
}

int main(){
  cin>>n>>x;
  REP(i,n){
    cin>>b[i]>>l[i]>>u[i];
    dept+=(LL)l[i]*(LL)b[i];
    v.push_back(make_pair(i,(LL)(x-b[i])*(LL)u[i]+(LL)l[i]*(LL)b[i]));
    //cerr<<i<<" "<<v[i].second<<endl;
  }
  sort(ALL(v),[&](pair<int,LL> p1,pair<int,LL> p2){return p1.second > p2.second;});
  LL lb=0,ub=10000000001;
  while(lb<ub){
    LL mid = (lb+ub)/2;
    if(ok(mid)){
      ub = mid;
    }else{
      lb = mid+1;
    }
  }
  cout<<lb<<endl;
  return 0;
}
