#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
vector<pair<LL,LL>> v;

pair<LL,LL> myplus(pair<LL,LL> p, LL d, int rot){
  if(rot==0){
    p.first -= d;
  }else if(rot==1){
    p.first += d;
  }else if(rot==2){
    p.second -= d;
  }else if(rot==3){
    p.second += d;
  }
  return p;
}

LL m_dist(pair<LL,LL> p1, pair<LL,LL> p2){
  return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int main(){
  LL tmp1,tmp2;
  cin>>n;
  REP(i,n){
    cin>>tmp1>>tmp2;
    v.push_back(make_pair(tmp1,tmp2));
  }
  FOR(i,1,n){
    if((v[0].first+v[0].second+v[i].first+v[i].second)%2!=0){
      cout<<-1<<endl;
      return 0;
    }
  }

  vector<LL> d;
  LL d_in = 1LL;
  REP(i,38)
    d_in*=2;
  if((v[0].first+v[0].second)%2==0){
    REP(i,40){
      d.push_back(d_in);
      d_in = max((LL)1,d_in/2);
    }
  }else{
    REP(i,39){
      d.push_back(d_in);
      d_in = d_in/2;
    }
  }
  cout<<d.size()<<endl;
  REP(i,d.size()){
    cout<<d[i]<<" ";
  }
  cout<<endl;

  string ops[4] = {"L","R","D","U"};
  REP(i,n){
    string s_out = "";
    pair<LL,LL> pos = make_pair(0LL,0LL);
    REP(j,d.size()){
      vector<LL> v_val;
      REP(k,4){
	v_val.push_back(m_dist(v[i],myplus(pos,d[j],k)));
      }
      int min_idx = distance(v_val.begin(),min_element(v_val.begin(),v_val.end()));
      s_out += ops[min_idx];
      pos = myplus(pos,d[j],min_idx);
    }
    cout<<s_out<<endl;
  }
  return 0;
}
