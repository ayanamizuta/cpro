#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
int a[500001],cum[500001];
vector<vector<int>> v;
LL mod = 1000000007;

long long pow(long long n, long long e){
    long long ret = 1;
    long long b = n;
    while(e){
      if(e%2!=0)
	ret*=b;
      ret%=mod;
      b*=b;
      b%=mod;
      e/=2;
    }
    return ret;
  }


int main(){
  cin>>n;
  cum[0]=0;
  a[0]=0;
  REP(i,n){
    cin>>a[i+1];
    cum[i+1]=cum[i]^a[i+1];
  }
  
  vector<int> v_in;
  FOR(i,1,n+1){
    if(cum[i]!=0)v_in.push_back(cum[i]);
    else {v.push_back(v_in);v_in.erase(ALL(v_in));}
  }
  if(cum[n]!=0)v.push_back(v_in);
  
  
  LL ret=0LL;
  if(cum[n]==0)
    ret += pow(2LL,(LL)(v.size()-1));

  if(v.size()==1){
    cout<<1<<endl;
    return 0;
  }
  REP(i,v[0].size()){
    int beau=v[0][i];
    LL ret_in=1,ret_in_pre=0;
    bool flag=false;
    REP(j,v.size()-1){
      int cn = count(ALL(v[j+1]),beau);
      ret_in*=(LL)(cn+1);
      ret_in%=mod;
    }
    if(cum[n]!=0 && beau!=cum[n])ret_in=0LL;
    //cerr<<i<<" "<<beau<<" "<<ret_in<<endl;
    ret+=ret_in;
  }
  
  cout<<ret<<endl;
  
  return 0;
}
