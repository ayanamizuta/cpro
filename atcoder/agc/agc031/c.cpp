#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

vector<int> oddpat(int l){
  if(l==1){
    vector<int> w({0,1});
    return w;
  }
  vector<int> v = oddpat(l-2);
  vector<int> ret;
  REP(i,v.size()){
    ret.push_back(v[i]);
  }
  REP(i,v.size()){
    ret.push_back(v[v.size()-1-i]+(1<<(l-2)));
  }
  REP(i,v.size()){
    if(!(i%2)){
      ret.push_back(v[i]+(3<<(l-2)));
      ret.push_back(v[i]+(2<<(l-2)));
    }else{
      ret.push_back(v[i]+(2<<(l-2)));
      ret.push_back(v[i]+(3<<(l-2)));
    }
  }
  return ret;
}

vector<int> adlib(int l){
  vector<int> v = oddpat((l+1)/2*2-1);
  if(l%2)return v;
  vector<int> ret;
  REP(i,v.size())ret.push_back(v[i]);
  REP(i,v.size())ret.push_back((1<<(l-1))+v[v.size()-1-i]);
  return ret;
}

int cntbit(int k){
  int ret=0;
  REP(i,17){
    if(k%2)ret++;
    k/=2;
  }
  return ret;
}

int n,a,b;
vector<int> pv;

int permu(int l){
  int bits[17];
  REP(i,17){
    bits[i]=l%2;
    l/=2;
  }
  REP(i,pv.size()){
    swap(bits[pv[pv.size()-1-i]],bits[pv.size()-1-i]);
  }
  int ret=0;
  REP(i,17){
    ret+=bits[i]<<i;
  }
  return ret;
}

int main(){
  cin>>n>>a>>b;
  b=a^b;
  if(cntbit(b)%2==0){
    cout<<"NO"<<endl;
    return 0;
  }
  int bi = cntbit(b);
  REP(i,17){
    if((b>>i)%2)pv.push_back(i);
  }
  vector<int> v,odd=oddpat(cntbit(b));
  if(n-cntbit(b)==0){
    cout<<"YES"<<endl;
    REP(i,odd.size()){
      if(i==0)cout<<(odd[i]^a);
      else cout<<" "<<(odd[i]^a);
    }
    cout<<endl;
    return 0;
  }
  vector<int> w=adlib(n-cntbit(b));
  REP(i,odd.size()){
    REP(j,w.size()){
      if(!(i%2))v.push_back((w[j]<<bi)+odd[i]);
      else v.push_back((w[w.size()-1-j]<<bi)+odd[i]);
    }
  }
  cout<<"YES"<<endl;
  REP(i,v.size()){
    if(i==0)cout<<(permu(v[i])^a);
    else cout<<" "<<(permu(v[i])^a);
  }
  cout<<endl;
  return 0;
}
