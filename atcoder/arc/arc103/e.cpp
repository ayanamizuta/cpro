#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

string s;
int n;
vector<int> v;

int main(){
  cin>>s;
  n=s.size();
  if(s[n-1]=='1' | s[0]=='0'){
    cout<<-1<<endl;
    return 0;
  }
  REP(i,n-1){
    if(s[i] != s[n-2-i]){
      cout<<-1<<endl;
      return 0;
    }
  }
  FOR(i,0,n/2){
    if(s[i] == '1')
      v.push_back(i);
  }
  if(v.size()==0){
    REP(i,n-1)
      cout<<i+1<<" "<<n<<endl;
    return 0;
  }

  string s_out="";
  int par,init=1;
  REP(i,v.size()){
    par = v[i]+1;
    FOR(j,init,par){
      s_out += to_string(j) + " " + to_string(par) + "\n";
    }
    if(i!=v.size()-1)
      s_out += to_string(par) + " " + to_string(v[i+1]+1) + "\n";
    else
      s_out += to_string(par) + " " + to_string(n) + "\n";
    init = v[i]+2;
  }

  FOR(i,init,n)
    s_out += to_string(i) + " " + to_string(n) + "\n";
  
  cout<<s_out;
  return 0;
}
