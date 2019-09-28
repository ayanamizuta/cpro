#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
vector<int> b,a;

int main(){
  cin>>n;
  int b_in;
  REP(i,n){
    cin>>b_in;
    b.push_back(b_in);
  }

  bool bl;
  while(b.size()>0){
    bl=false;
    REP(j,b.size()){
      if(b[b.size()-1-j]==b.size()-j){
	a.push_back(b.size()-j);
	b.erase(b.begin()+b.size()-1-j);
	bl=true;
	break;
      }
    }
    if(bl)continue;
    cout<<-1<<endl;
    return 0;
  }
  
  REP(i,a.size()){
    cout<<a[a.size()-1-i]<<endl;
  }
  return 0;
}
