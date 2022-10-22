#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

#define MOD 1000000007
#define FACT_MAX 1000000

LL fact[FACT_MAX];
int a[100000];

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

  long long div(long long n1,long long n2){
    return n1*power(n2,mod-2)%mod;
  }
  
  long long nck(int n,int k){
    if(k>n || k<0) return 0LL;
    if(k==n || k==0) return 1LL;
    return (fact[n]*inv(fact[n-k])%mod)*inv(fact[k])%mod;
  }
};

int t;
int n;
LL ret;
vector<int> v;

int count_stack(){
    int cur = -1;
    int ret=0;
    REP(i,v.size()){
        if(cur<v[v.size()-1-i]){
            cur=v[v.size()-1-i];
            ret++;
        }
    }
    return ret;
}

LL dfs(int round){
    LL ret=0;
    if(v.size()==n){
        return 1;
    }
    REP(i,n){
        if(find(ALL(v),i)==v.end()){
            v.push_back(i);
            if(count_stack()!=a[round]){
                v.pop_back();
                continue;
            }
            ret+=dfs(round+1);
            v.pop_back();
            ret%=MOD;
        }
    }
    return ret;
}

void solve(int pn){
    cin>>n;
    REP(i,n)cin>>a[i];
    v.resize(0);
    auto ret = dfs(0);
    cout<<"Case #"<<pn<<": "<<ret<<endl;
}

int main(){
    cin >> t;
    REP(i,t)solve(i+1);
    return 0;
}
