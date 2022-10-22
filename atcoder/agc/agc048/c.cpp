#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
LL l;
LL a[100000],b[100000],biased_l[100001],biased_r[100001];
LL directions[100000];

int main(){
    cin>>n>>l;
    biased_l[0] = n;
    biased_r[n] = l+1-n;
    REP(i,n){
        cin>>a[i];
        biased_l[i+1] = a[i]+n-i-1;
        biased_r[i] = a[i]-i;
    }
    REP(i,n)cin>>b[i];

    REP(i,n){
        if(a[i] == b[i]){
            directions[i]=0;
        }else if(a[i] > b[i]){
            LL key = b[i]+n-i-1;
            int lb=0,ub=n+1;
            while(lb < ub){
                auto mid = (lb+ub)/2;
                if(biased_l[mid] > key){
                    ub = mid;
                }else{
                    lb = mid+1;
                }
            }
            lb--;
            if(biased_l[lb] != key){
                cout<<-1<<endl;
                return 0;
            }
            directions[i] = lb - i - 1;
        }else{
            LL key = b[i] - i;
            int lb=0,ub=n+1;
            while(lb < ub){
                auto mid = (lb+ub)/2;
                if(biased_r[mid] >= key){
                    ub = mid;
                }else{
                    lb = mid+1;
                }
            }
            if(biased_r[lb] != key){
                cout<<-1<<endl;
                return 0;
            }
            directions[i] = lb - i;
        }
        //cerr<<i<<" "<<directions[i]<<endl;
    }

    LL ret=0,capl=0,capr=0;
    REP(i,n){
        LL dir = directions[i];
        if(dir==0){
            capl=0;
            capr=0;
        }else if(dir < 0){
            capr=0;
            if(capl < (-dir)){
                ret++;
            }else{
                ret+=-dir;
            }
            capl = -dir;
        }else{
            capl=0;
            if(capr > dir){
                ret = ret;
            }else{
                ret+=dir;
            }
            capr = dir;
        }
    }
    cout<<ret<<endl;
}