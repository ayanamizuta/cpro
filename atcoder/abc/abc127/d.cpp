#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n,m;
vector<LL> a;
vector<pair<int,LL>> v;

int main(){
  cin>>n>>m;
  REP(i,n){
    LL tmp;
    cin>>tmp;
    a.push_back(tmp);
  }
  sort(ALL(a));
  REP(i,m){
    pair<int,LL> p;
    cin>>p.first>>p.second;
    v.push_back(p);
  }
  sort(ALL(v),[](pair<int,LL> p1,pair<int,LL> p2){return p1.second > p2.second;});
  int ind=0,ind_in;
  LL ret = 0;
  bool brk=false;
  REP(i,v.size()){
    ind_in = ind;
    FOR(j,ind,min(n,ind+v[i].first)){
      if(a[j] < v[i].second){
	ret += v[i].second;
	ind_in++;
      }else{
	brk=true;
	break;
      }
    }
    ind = ind_in;
    if(brk)break;
  }
  FOR(i,ind,n){
    ret += a[i];
  }
  
  cout<<ret<<endl;
  return 0;
}
