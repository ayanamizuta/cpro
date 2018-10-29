#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
vector<LL> a,b;
LL tmp;
vector<LL> l,r;


int main(){
  cin>>n;
  REP(i,n){
    cin>>tmp;
    a.push_back(tmp);
    b.push_back(tmp);
  }

  sort(a.begin(),a.end());
  l.push_back(a[0]);
  a.erase(a.begin());
  bool bl=true;
  while(a.size()){
    if(bl){
      l.push_back(a[a.size()-1]);
      a.erase(a.end()-1);
      if(a.size()==0) break;
      r.push_back(a[a.size()-1]);
      a.erase(a.end()-1);
    }else{
      l.push_back(a[0]);
      a.erase(a.begin());
      if(a.size()==0) break;
      r.push_back(a[0]);
      a.erase(a.begin());
    }
    bl = !bl;
  }
  
  LL ret=0;
  REP(i,l.size()-1){
    ret+=abs(l[i]-l[i+1]);
  }
  if(r.size()>0){
    ret+=abs(l[0]-r[0]);
    REP(i,r.size()-1){
      ret+=abs(r[i]-r[i+1]);
    }
  }

  sort(b.begin(),b.end());
  l.resize(0);
  r.resize(0);
  l.push_back(b[b.size()-1]);
  b.erase(b.end()-1);
  bl=true;
  while(b.size()){
    if(bl){
      l.push_back(b[0]);
      b.erase(b.begin());
      if(b.size()==0) break;
      r.push_back(b[0]);
      b.erase(b.begin());
    }else{
      l.push_back(b[b.size()-1]);
      b.erase(b.end()-1);
      if(b.size()==0) break;
      r.push_back(b[b.size()-1]);
      b.erase(b.end()-1);
    }
    bl = !bl;
  }
  
  LL ret2=0;
  REP(i,l.size()-1){
    ret2+=abs(l[i]-l[i+1]);
  }
  if(r.size()>0){
    ret2+=abs(l[0]-r[0]);
    REP(i,r.size()-1){
      ret2+=abs(r[i]-r[i+1]);
    }
  }
  
  cout<<max(ret,ret2)<<endl;
  return 0;
}
