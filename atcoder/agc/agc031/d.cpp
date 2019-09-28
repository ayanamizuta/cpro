#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
LL k;
vector<int> p,q;
vector<int> mods[6];

vector<int> compose(const vector<int> &v1,const vector<int> &v2){
  vector<int> v;
  REP(i,v1.size())v.push_back(v1[v2[i]]);
  return v;
}

vector<int> inverse(const vector<int> &v){
  vector<int> retv(v.size());
  REP(i,v.size())retv[v[i]]=i;
  return retv;
}

int main(){
  cin>>n>>k;
  int tmp;
  REP(i,n){
    cin>>tmp;tmp--;
    p.push_back(tmp);
  }
  REP(i,n){
    cin>>tmp;tmp--;
    q.push_back(tmp);
  }
  mods[0]=p;mods[1]=q;
  REP(i,4){
    mods[2+i]=compose(mods[1+i],inverse(mods[i]));
  }
  LL iter = (k-1)/6;
  vector<int> pow,b;
  REP(i,n)pow.push_back(i);
  b=compose(q,compose(inverse(p),compose(inverse(q),p)));
  while(iter>0){
    if(iter%2){
      pow = compose(pow,b);
    }
    b=compose(b,b);
    iter/=2;
  }
  vector<int> v = compose(compose(pow,mods[(k-1)%6]),inverse(pow));
  REP(i,n){
    if(i==0)cout<<v[i]+1;
    else cout<<" "<<v[i]+1;
  }
  cout<<endl;
  return 0;
}
