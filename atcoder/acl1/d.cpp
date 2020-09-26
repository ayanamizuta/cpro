#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

struct S{
    int nextindex;
    LL indsum;
};

int n,k,q;
vector<LL> x;
vector<vector<S>> tables;

int main() {
    cin>>n>>k;
    x.resize(n);
    REP(i,n)cin>>x[i];
    cin>>q;
}