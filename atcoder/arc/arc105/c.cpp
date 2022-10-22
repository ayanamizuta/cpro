#include "bits/stdc++.h"
//#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

struct S{
    LL l;
    LL v;
};

int n,m;
vector<LL> w;
LL l[100000],v[100000];
vector<S> b;
LL maxl[100001];
LL dist[10][10];
LL dp[10];

int main() {
    LL maxi = 0;
    cin>>n>>m;
    REP(i,n){
        LL w_in;
        cin>>w_in;
        maxi = max(maxi,w_in);
        w.push_back(w_in);
    }
    REP(i,m){
        cin>>l[i]>>v[i];
        if(maxi > v[i]){
            cout<<-1<<endl;
            return 0;
        }
        b.push_back(S{l[i],v[i]});
    }
    sort(ALL(b),[](S s1, S s2){return s1.v < s2.v;});
    
    maxl[0] = b[0].l;
    FOR(i,1,m)maxl[i] = max(maxl[i-1],b[i].l);
    
    sort(ALL(w));
    LL ret = 1e15;
    do {
        //cerr<<w[0]<<" "<<w[1]<<" "<<w[2]<<endl;
        REP(i,n){
            LL vv = w[i];
            FOR(j,i+1,n){
                vv += w[j];
                int lb=0,ub=m;
                while(lb < ub){
                    int mid = (lb+ub)/2;
                    //cerr<<vv<<" "<<lb<<" "<<ub<<" "<<mid<<endl;
                    if(b[mid].v < vv){
                        lb = mid+1;
                    }else{
                        ub = mid;
                    }
                }
                
                //cerr<<i<<" "<<j<<" "<<lb<<" "<<maxl[lb-1]<<endl;
                dist[i][j] = lb == 0 ? 0 : maxl[lb-1];
            }
        }
        dp[0] = 0;
        FOR(i,1,n){
            dp[i] = 0;
            FOR(j,1,i+1){
                dp[i] = max(dp[i],dp[i-j]+dist[i-j][i]);
            }
        }
        //REP(i,n)cerr<<dp[i]<<" ";
        //cerr<<endl;
        //cerr<<"dp "<<dp[n-1]<<endl;
        ret = min(ret,dp[n-1]);
    } while(next_permutation(ALL(w)));

    if(ret == 1e15)cout<<-1<<endl;
    else cout<<ret<<endl;
}