#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n,d;
LL x,y;
int cnt[1000][1000];
int counter[3][2001][2001];

LL nums(int sp,int x,int y,int z,int w){
  return counter[sp][z][w]+counter[sp][x][y]-counter[sp][x][w]-counter[sp][z][y];
}

bool test(LL len){
  LL a = len/d+1;
  int b = (int)(len%d)+1;
  
  LL mask[3] = {a*a,a*(a-1),(a-1)*(a-1)};
  REP(sp,3){
    REP(i,2*d){
      REP(j,2*d){
	if(cnt[i%d][j%d] > mask[sp])
	  counter[sp][i][j]=1;
	else
	  counter[sp][i][j]=0;
	if(i>0)counter[sp][i][j]+=counter[sp][i-1][j];
	if(j>0)counter[sp][i][j]+=counter[sp][i][j-1];
	if(i>0&&j>0)counter[sp][i][j]-=counter[sp][i-1][j-1];
      }
    }
  }
  /*
  REP(i,2*d){
    REP(j,2*d){
      cerr<<counter[1][i][j]<<" ";
    }
    cerr<<endl;
  }
  REP(i,2*d){
    REP(j,2*d){
      cerr<<counter[2][i][j]<<" ";
    }
    cerr<<endl;
  }
  */
  
  REP(i,d){
    REP(j,d){
      if(nums(0,i,j,i+b,j+b)>0)continue;
      if(nums(1,i+b,j,i+d,j+b)>0)continue;
      if(nums(1,i,j+b,i+b,j+d)>0)continue;
      if(nums(2,i+b,j+b,i+d,j+d)==0){
	return true;
      }
    }
  }
  return false;
}

int solve(){
  LL lb=1,ub=n*d;
  LL mid;
  while(lb<ub){
    mid = (lb+ub)/2;
    if(test(mid)){
      ub=mid;
    }else{
      lb=mid+1;
    }
  }
  return lb;
}

int main(){
  cin>>n>>d;
  REP(i,d){
    REP(j,d)
      cnt[i][j]=0;
  }
  REP(i,n){
    scanf("%d%d",&x,&y);
    cnt[x%d][y%d]+=1;
  }

  cout<<solve()<<endl;
  return 0;
}
