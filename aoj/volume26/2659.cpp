#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

long long gcd(long long a,long long b){
  if(b==0)return a;
  if(a<b)return gcd(b,a);
  return gcd(b,a%b);
}

long long lcm(long long a,long long b){
  return a*b/gcd(a,b);
}

// lcm of several variables
long long lcm_n(int n,long long *a){
  LL ret=a[0];
  for(int i=0;i<n-1;i++){
    ret=lcm(ret,a[i+1]);
  }
  return ret;
}

// output the smallest non-negative integer N s.t. N%quots[i]=rems[i]
// if contradiction occurs, output -1
long long reminder(int n,long long *rems,long long *quots){
  if(n==1)return rems[0];
  long long x1,x2,y1,y2;
  x1=rems[0];
  y1=quots[0];
  for(int i=0;i<n-1;i++){
    x2=rems[i+1];
    y2=quots[i+1];
    for(int j=0;j<y2;j++){
      if((x1+j*y1)%y2==x2){
	x1=(x1+j*y1)%lcm(y1,y2);
	y1=lcm(y1,y2);
	break;
      }
      if(j==y2-1)return -1;
    }
  }
  return x1;
}

LL n,m,d;
LL a[10],adum[10];
LL r[100][10],rdum[10];

int main(){
  cin>>n>>m>>d;
  REP(i,m)
    cin>>a[i];
  REP(i,d){
    REP(j,m)
      cin>>r[i][j];
  }
  REP(i,d){
    int num=0;
    REP(j,m){
      if(r[i][j]>=0){
	adum[num]=a[j];
	rdum[num]=r[i][j];
	num++;
      }
    }
    if(!num)continue;
    LL ret=reminder(num,rdum,adum);
    if(ret<0 || n<ret){
      n=-1;
      break;
    }
    n=ret+lcm_n(num,adum)*((n-ret)/lcm_n(num,adum));
  }

  cout<<n<<endl;
  return 0;
}
