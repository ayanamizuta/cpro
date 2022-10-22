#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long
int n,m;
LL a[200000],b[200000];
int is_leader[200000];
vector<vector<int>> v;
int main(){
    cin>>n>>m;
    REP(i,n)cin>>a[i];
    REP(i,n)cin>>b[i];
    REP(i,n)is_leader[i]=-1;
    auto uf = atcoder::dsu(n);
    REP(i,m){
        int c,d;
        cin>>c>>d;
        c--;
        d--;
        uf.merge(c, d);
    }
    REP(i,n){
        int leader = uf.leader(i);
        if(is_leader[leader] != -1){
            v[is_leader[leader]].push_back(i);
        }else{
            is_leader[leader] = v.size();
            v.push_back({i});
        }
    }


    for(auto vv: v){
        LL sua = 0,sub = 0;
        for(auto vidx: vv){
            sua += a[vidx];
            sub += b[vidx];
        }
        if(sua != sub){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}