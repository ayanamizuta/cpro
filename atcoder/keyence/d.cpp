#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define LL long long

#define MOD 1000000007
#define FACT_MAX 1000000

LL fact[FACT_MAX];

class Combinatrics{
private:
  long long mod = MOD;
  int fact_max = FACT_MAX;
public:
  Combinatrics(){
    fact[0]=1;
    for(int i=1;i<fact_max;i++)
      fact[i] = (fact[i-1]*i)%mod;
  }
  
  long long power(long long n, long long e){
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

  long long inv(long long n){
    return power(n,mod-2);
  }
  
  long long nck(int n,int k){
    if(k>n || k<0) return 0;
    if(k==n || k==0) return 1;
    return (fact[n]*inv(fact[n-k])%mod)*inv(fact[k])%mod;
  }
};

LL n,m;
vector<LL> a,b,v;

int main(){
  cin>>n>>m;
  LL tmp;
  REP(i,n){
    cin>>tmp;
    a.push_back(tmp);
  }
  REP(i,m){
    cin>>tmp;
    b.push_back(tmp);
  }
  Combinatrics comb;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  REP(i,a.size()-1){
    if(a[i]==a[i+1]){
      cout<<0<<endl;
      return 0;
    }
  }
  REP(i,b.size()-1){
    if(b[i]==b[i+1]){
      cout<<0<<endl;
      return 0;
    }
  }
  if(a[a.size()-1]!=n*m || b[b.size()-1]!=n*m){
    cout<<0<<endl;
    return 0;
  }

  v.push_back(0);
  
  int ia=0,ib=0;
  FOR(i,1,n*m+1){
    ia=min(ia,(int)n-1);
    ib=min(ib,(int)m-1);
    if(a[ia]==i && b[ib]==i){
      v.push_back(i);
      ia++;
      ib++;
    }else if(a[ia]==i){
      v.push_back(i);
      ia++;
    }else if(b[ib]==i){
      v.push_back(i);
      ib++;
    }
  }

  LL cum=1;
  ia=a.size()-1;
  ib=b.size()-1;
  LL target;
 
  REP(i,v.size()-1){
    target=v[v.size()-1-i];
    LL blank = (n-ia)*(m-ib)-(n*m-target);
    LL band = target-v[v.size()-2-i];
    cerr<<blank<<" "<<band<<endl;
    if(blank<band){
      cout<<0<<endl;
      return 0;
    }
    
    if(a[ia]==b[ib])
      cum=(cum*comb.nck((int)blank-1,(int)band-1)%MOD)*fact[(int)band-1]%MOD;
    else if(a[ia]==target)
      cum=((cum*(m-ib)%MOD)*comb.nck((int)blank-1,(int)band-1)%MOD)*fact[(int)band-1]%MOD;
    else if(b[ib]==target)
      cum=((cum*(n-ia)%MOD)*comb.nck((int)blank-1,(int)band-1)%MOD)*fact[(int)band-1]%MOD;

    if(ia==0)ib--;
    else if(ib==0)ia--;
    else if(a[ia-1]<b[ib-1])ib--;
    else if(a[ia-1]>b[ib-1])ia--;
    else{
      ia--;
      ib--;
    }
  }

  cout<<cum<<endl;
  return 0;
}
