#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

LL k;
LL x,y;
LL modx,mody;

int main(){
  cin>>k>>x>>y;
  if(k%2==0 && (x+y)%2!=0){
    cout<<-1<<endl;
    return 0;
  }
  if(k%2)
  if(x%k == 0 && y%k == 0){
    cout<<(abs(x)+abs(y))/k<<endl;
    LL tmpx=0,tmpy=0;
    REP(i,(abs(x)+abs(y))/k){
      if(tmpx<x || tmpx>x){
	cout<<(tmpx<x?tmpx+k:tmpx-k)<<" "<<tmpy<<endl;
	tmpx<x?tmpx+=k:tmpx-=k;
      }else{
	cout<<tmpx<<" "<<(tmpy<y?tmpy+k:tmpy-k)<<endl;
	tmpy<y?tmpy+=k:tmpy-=k;
      }
    }
  }else{
    LL candx,candy;
    if((x-y)%k==0){
      if(x > y){
	candx=x-x%k;
	candy=y-y%k+k;
      }else{
	candx=x-x%k+k;
	candy=y-y%k;
      }
    }

    LL candx2,candy2;
    if((x+y)%k==0){
      if(x + y > 0){
	candx2=x-x%k;
	candy2=y-y%k;
      }else{
	candx2=x-x%k+k;
	candy2=y-y%k+k;
      }
    }

    if((x-y)%k!=0 || (abs(candx)+abs(candy))%k>(abs(candx2)+abs(candy2))%k){
      candx=candx2;
      candy=candy2;
    }

    cout<<(abs(candx)+abs(candy))%k+1<<endl;
    LL tmpx=0,tmpy=0;
    REP(i,(abs(candx)+abs(candy))%k){
      if(tmpx<candx || tmpx>candx){
	cout<<(tmpx<x?tmpx+k:tmpx-k)<<" "<<tmpy<<endl;
	tmpx<x?tmpx+=k:tmpx-=k;
      }else{
	cout<<tmpx<<" "<<(tmpy<y?tmpy+k:tmpy-k)<<endl;
      }
    }
    back_dump(v);
  }
  return 0;
}
