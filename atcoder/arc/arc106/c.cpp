#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n,m;
LL ma=1e9;
int main(){
    cin>>n>>m;
    if(n==1 && m==0){
        cout<<1<<" "<<2<<endl;
        return 0;
    }
    if(m<0 || m >= n-1){
        cout<<-1<<endl;
        return 0;
    }
    if(m==0){
        REP(i,n){
            cout<<3*i+1<<" "<<3*i+2<<endl;
        }
        return 0;
    }
    int small = 1+m;
    cout<<1<<" "<<ma/2<<endl;
    REP(i,small){
        cout<<2+3*i<<" "<<2+3*i+1<<endl;
    }
    REP(i,n-1-small){
        cout<<2+3*i+ma/2<<" "<<2+3*i+1+ma/2<<endl;
    }
}