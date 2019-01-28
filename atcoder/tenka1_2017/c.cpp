#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long


int main(){
  LL n;
  cin>>n;
  FOR(h,1,3501){
    FOR(w,1,3501){
      if(((4*h-n)*w-n*h)!=0&&(n*h*w)/((4*h-n)*w-n*h)>0&&(n*h*w)%((4*h-n)*w-n*h)==0){
	cout<<h<<" "<<w<<" "<<(n*h*w)/((4*h-n)*w-n*h)<<endl;
	return 0;
      }
    }
  }
  return 0;
}
