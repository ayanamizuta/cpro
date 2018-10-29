#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;
vector<vector<int>> v;

int main(){
  cin>>n;
  int k=0;
  FOR(i,1,10000){
    k+=i;
    if(n<k){
      cout<<"No"<<endl;
      return 0;
    }
    if(n==k){
      k=i;
      break;
    }
  }
  if(k==1){
    cout<<"Yes"<<endl;
    cout<<2<<endl;
    cout<<1<<" "<<1<<endl;
    cout<<1<<" "<<1<<endl;
    return 0;
  }
  k+=1;
  v.resize(k);
  int su=0;
  FOR(i,1,k){
    REP(j,i){
      su+=1;
      v[j].push_back(su);
      v[i].push_back(su);
    }
  }
  
  cout<<"Yes"<<endl;
  cout<<k<<endl;
  REP(i,v.size()){
    cout<<k-1;
    REP(j,v[i].size()){
      cout<<" "<<v[i][j];
    }
    cout<<endl;
  }
  
  return 0;
}
