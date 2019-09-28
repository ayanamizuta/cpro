#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int main(){
  LL s,x1=0,x2,y1,y2;
  cin>>s;
  LL lb=0,ub=1000000000;
  while(lb<ub){
    LL mid = (lb+ub)/2;
    if(mid*mid < s){
      lb=mid+1;
    }else{
      ub=mid;
    }
  }
  x1=lb;y2=lb;
  while(x1*y2-s > 1000000000){
    x1++;
    y2--;
  }
  LL del = x1*y2 - s;
  x2=1;y1=del;
  cout<<0<<" "<<0<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
  //cerr<<x1*y2-x2*y1<<endl;
  return 0;
}
