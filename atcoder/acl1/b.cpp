#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

struct Pcnt{
    LL p;
    int cnt;
};

LL n;
vector<Pcnt> primes;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

LL pow(LL a,LL b){
    LL ret = 1,b_=a;
    while(b){
        if(b%2)ret*=b_;
        b_ = b_*b_;
        b/=2;
    }
    return ret;
}

int main() {
    cin>>n;
    n*=2;
    LL dumn = n;
    FOR(p,2,n){
        if((LL)p*(LL)p >= n || dumn == 1){
            if(dumn != 1)primes.push_back(Pcnt{dumn,1});
            break;
        }
        if(!(dumn%p)){
            FOR(i,1,52){
                if(!(dumn % pow((LL)p,(LL)i)) && dumn % pow((LL)p,(LL)i+1)){
                    primes.push_back(Pcnt{(LL)p,i});
                    dumn /= pow(p,i);
                    break;
                }
            }
        }
    }
    /*REP(i,primes.size()){
        cerr<<primes[i].p<<" "<<primes[i].cnt<<endl;
    }*/
    LL ret = n;
    REP(i,1<<primes.size()){
        LL k=1,x,y;
        REP(j,primes.size()){
            if(i & (1<<j)){
                k*=pow(primes[j].p,primes[j].cnt);
            }
        }
        if(!(k%2))continue;
        if(k==n){
            ret = min(ret,k);
            continue;
        }
        LL kcomp = n/k;
        LL ret_ = extGCD(k,kcomp,x,y);
        //cerr<<k<<" "<<kcomp<<" "<<x<<endl;
        LL kk = ((kcomp-(x+kcomp)%kcomp)*k);
        ret = min(ret,kk);

        kk = (((x+kcomp)%kcomp)*k);
        if(kk!= 1) ret = min(ret,kk-1);
    }
    cout<<ret<<endl;
}