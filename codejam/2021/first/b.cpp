#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int t,x,y,n;
string s;

int min_cost(char init,char term,int len){
  if(init=='?'&&term=='?'){
    if(len==1)return 0;
    if(len==2)return min(0,min(x,y));
    return min(min_cost('C','C',len-2),min(min_cost('C','J',len-2),min(min_cost('J','C',len-2),min_cost('J','J',len-2))));
  }else if(init=='?'){
    if(len==1)return (term=='C')?min(0,y):min(0,x);
    return min(min_cost('C',term,len-1),min_cost('J',term,len-1));
  }else if(term=='?'){
    if(len==1)return (init=='C')?min(0,x):min(0,y);
    return min(min_cost(init,'C',len-1),min_cost(init,'J',len-1));
  }
  if(init==term){
    return min(0,(x+y)*((len+1)/2));
  }
  int ret = (init=='C')?x:y;
  return min(ret,ret+(x+y)*(len/2));
}

void solve_one(int problem_num){
    cin>>x>>y>>s;
    n=s.size();
    int ret=0;
    REP(i,n-1){
      if(s[i]=='C'&&s[i+1]=='J')ret+=x;
      else if(s[i]=='J'&&s[i+1]=='C')ret+=y;
    }

    char init='*';
    int len=0;
    REP(i,n){
      if(init!='*')len++;
      if(!i&&s[i]=='?')init='?';
      else if(init=='*'&&s[i]=='?')init=s[i-1];

      if(init!='*'&&s[i]!='?'){
        ret+=min_cost(init,s[i],len);
        init='*';
        len=0;
      }
    }
    if(init!='*')ret+=min_cost(init,'?',len+1);

    cout<<"Case #"<<problem_num<<": "<<ret<<endl;
}

int main(){
  cin>>t;
  REP(i,t)solve_one(i+1);
  return 0;
}
