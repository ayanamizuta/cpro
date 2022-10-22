#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
vector<int> p,retp;
struct S{
    int init;
    int term;
};
vector<S> ret;

int main(){
    cin>>n;
    REP(i,n){
        int k;
        cin>>k;
        k--;
        p.push_back(k);
    }

    REP(i,n){
        if(p[i] > i){
            ret.push_back(S{p[i]-1,i});
        }
    }

    LL size = 0;
    for(auto s: ret){
        size += (LL)(s.init - s.term + 1);
    }

    if(size != n-1){
        cout<<-1<<endl;
        return 0;
    }

    for(auto s: ret){
        FOR(i,s.term,s.init+1){
            retp.push_back(s.term - i + s.init);
        }
    }

    REP(i,n-1){
        swap(p[retp[n-2-i]],p[retp[n-2-i]+1]);
    }
    REP(i,n){
        if(p[i] != i){
            cout<<-1<<endl;
            return 0;
        }
    }

    REP(i,n-1){
        cout<<retp[n-2-i]+1<<endl;
    }
}