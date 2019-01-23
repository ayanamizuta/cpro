#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n,k;
LL a[100000],b[100000];

class cost {
public:
  LL val;
  int ind;
  cost(){}
  cost(LL v,int i){
    val=v;
    ind=i;
  }
  
  cost operator+(LL v){
    cost ret(val,ind);
    ret.val += v;
    return ret;
  } 
};

bool operator<(const cost &c1,const cost &c2){
    return c1.val>c2.val;
}

int main(){
  cin>>n>>k;
  REP(i,n)
    cin>>a[i]>>b[i];
  priority_queue<cost> q;
  REP(i,n){
    cost c(a[i],i);
    q.push(c);
  }
  LL ret=0;
  REP(i,k){
    cost c = q.top();
    c.val=c.val+b[c.ind];
    q.push(c);
    ret+=q.top().val;
    q.pop();
  }
  cout<<ret<<endl;
  return 0;
}
