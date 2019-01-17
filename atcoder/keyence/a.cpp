#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int a,b,c,d;
vector<int> v;
int aa[4]={1,4,7,9};

int main(){
  cin>>a>>b>>c>>d;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  v.push_back(d);
  sort(v.begin(),v.end());
  REP(i,4){
    if(v[i]!=aa[i]){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
