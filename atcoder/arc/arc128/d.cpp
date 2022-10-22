#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
int a[200000];
mint dp[200002][2];

mint subsub(int l){
  return dp[l][0]+dp[l][1];
}

mint sub(int l,int flag){
  mint ret=mint(0);
  if(!flag){
    ret+=subsub(l-2);
    FOR(i,1,l-2){
      ret+=2*subsub(i);
    }
    FOR(i,1,l-3){
      ret+=(l-3-i)*subsub(i);
    }
  }

  if(flag==1){
    ret+=subsub(l-2);
    FOR(i,1,l-3){
      ret+=subsub(i);
    }
  }

  if(flag==2){
    ret+=subsub(l-2);
  }
  
  return ret;
}

int main(){
    cin>>n;
    REP(i,n)cin>>a[i];
    dp[1][0]=1;
    dp[1][1]=1;
    FOR(i,2,n+2){
      dp[i][0]=dp[i-1][0]+dp[i-1][1];
      dp[i][1]=dp[i-1][0];
    }

    mint ret=mint(1);

    int ptr=0;
    int i =0;
    while(i<n){
      if(i<n-2 && a[i]==a[i+2]){
        ptr=i+2;
        while(ptr<n){
          if(a[ptr]!=a[ptr-2])break;
          ptr++;
        }
        ptr--;
        if((i==0 || (i>0 && a[i]==a[i-1])) && (ptr==n-1 || (ptr<n-1 && a[ptr]==a[ptr+1])))
          ret*=sub(ptr-i,2);
        else if((i==0 || (i>0 && a[i]==a[i-1])) || (ptr==n-1 || (ptr<n-1 && a[ptr]==a[ptr+1])))
          ret*=sub(ptr-i,1);
        else
          ret*=sub(ptr-i,0);
        cerr<<ptr<<endl;
        i=ptr;
      }
      else if(i!=0 && i!=n-1 && a[i]){
        ret*=2;
      }
    }

    cout<<ret.val()<<endl;
}