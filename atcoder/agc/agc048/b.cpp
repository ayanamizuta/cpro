#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
LL a[100000],b[100000],max_odd[100000],max_even[100000];
LL acm_odd_b=0,acm_even_b=0;

struct S{
    int idx;
    LL value;
};

vector<S> a_odd_ad,a_even_ad;

int main(){
    cin>>n;
    REP(i,n)cin>>a[i];
    REP(i,n)cin>>b[i];
    REP(i,n){
        if(i%2==1){
            a_odd_ad.push_back(S{i,a[i]-b[i]});
            acm_odd_b += b[i];
        }else{
            a_even_ad.push_back(S{i,a[i]-b[i]});
            acm_even_b += b[i];
        }
    }
    sort(ALL(a_odd_ad),[](S s1,S s2){return s1.value > s2.value;});
    sort(ALL(a_even_ad),[](S s1,S s2){return s1.value > s2.value;});
    max_odd[0] = acm_odd_b;
    max_even[0] = acm_even_b;
    //cerr<<a_odd_ad[0].value<<" "<<a_odd_ad[1].value<<endl;
    //cerr<<a_even_ad[0].value<<" "<<a_even_ad[1].value<<endl;
    FOR(i,1,n/2+1){
        max_odd[i] = max_odd[i-1] + a_odd_ad[i-1].value;
        max_even[i] = max_even[i-1] + a_even_ad[i-1].value;
    }

    LL ret = 0;
    REP(i,n/2+1)ret=max(ret,max_odd[i]+max_even[i]);
    cout<<ret<<endl;
}