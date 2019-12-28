#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long



int main(){
  string s;
  cin>>s;
  int size = s.size();
  LL ret=0,len=0,max=0;
  char state = '<';
  REP(i,size){
    //cerr<<ret<<" "<<len<<" "<<max<<endl;
    if(state == '<' && s[i] == '<'){
      ret+=1+len;
      len+=1;
      max+=1;
    }else if(state == '>' && s[i] == '<'){
      ret+=1;
      len=1;
      max=0;
    }else if(state == '<' && s[i] == '>'){
      max=len;
      len=1;
      if(max < len)ret+=1;
    }else if(state == '>' && s[i] == '>'){
      ret+=len;
      len+=1;
      if(max < len)ret+=1;
    }
    state = s[i];
  }
  cout<<ret<<endl;
  return 0;
}
