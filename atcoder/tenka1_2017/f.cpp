#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

int n;

long long gcd(long long a,long long b){
  if(b==0)return a;
  if(a<b)return gcd(b,a);
  return gcd(b,a%b);
}

long long lcm(long long a,long long b){
  return a*b/gcd(a,b);
}

long long euler_phi(long long n){
  LL ret=n;
  for(LL k=2;k*k<n+2;k++){
    if(n%k==0){
      ret-=ret/k;
      while(n%k==0)n/=k;
    }
  }
  if(n!=1)ret-=ret/n;
  return ret;
}

long long power(__int128 n, __int128 e, __int128 mod){
  __int128 ret = 1;
  __int128 b = n;
  while(e){
    if(e%2!=0)
      ret*=b;
    ret%=mod;
    b*=b;
    b%=mod;
    e/=2;
  }
  return (LL)ret;
}

LL solve(LL a,LL m){
  LL tor=euler_phi(m);
  if(m==2)return (a%2==0)?2:1;
  LL big=lcm(tor,m);
  LL sub=(tor==1)?1:solve(a,tor);
  return big+power(a,sub,big);
}

int main(){
  cin>>n;
  LL a,m;
  REP(i,n){
    cin>>a>>m;
    if(a==1||m==1){cout<<1<<endl;continue;}
    cout<<solve(a,m)<<endl;
  }
  return 0;
}
