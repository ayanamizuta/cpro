#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n;
int a[100],b[100];
int at[200],bt[200];

bool check(int cur, int term){
    int mid = (2*cur+2*term)/2;
    int inter = mid-2*cur;
    FOR(i,2*cur,mid){
        //cerr<<cur<<" "<<term<<" "<<i<<" "<<bt[i]<<" "<<at[i]<<endl;
        //cerr<<at[i]<<" "<<b[at[i]]<<" "<<i+inter<<endl;
        if(bt[i] != -1)return false;
        if(at[i] != -1 && b[at[i]] != -1 && b[at[i]] != i + inter)return false;
    }
    FOR(i,mid,2*term){
        //cerr<<cur<<" "<<term<<" "<<i<<" "<<bt[i]<<" "<<at[i]<<endl;
        //cerr<<bt[i]<<" "<<a[bt[i]]<<" "<<i+inter<<endl;
        if(at[i] != -1)return false;
        if(bt[i] != -1 && a[bt[i]] != -1 && a[bt[i]] != i - inter)return false;
    }
    return true;
}

int main() {
    cin>>n;
    REP(i,2*n){
        at[i] = -1;
        bt[i] = -1;
    }
    REP(i,n){
        cin>>a[i]>>b[i];
        if(a[i] != -1)a[i]--;
        if(b[i] != -1)b[i]--;
        if(a[i] != -1){
            if(at[a[i]] != -1 || bt[a[i]] != -1){
                cout<<"No"<<endl;
                return 0;
            }
            at[a[i]] = i;
        }
        if(b[i] != -1){
            if(bt[b[i]] != -1 || at[b[i]] != -1){
                cout<<"No"<<endl;
                return 0;
            }
            bt[b[i]] = i;
        }
    }
    
    int cur=0;
    FOR(i,1,n+1){
        if(i < n && bt[2*i] >= 0)continue;
        //cerr<<cur<<" "<<i<<endl;
        if(i < n){
            int cnt=0;
            bool bl = false;
            FOR(j,2*i,2*n){
                if(bt[j] >= 0)cnt++;
                if(cnt > (j-2*i+1)/2)bl=true;
            }
            if(bl)continue;
        }
        //cerr<<cur<<" "<<i<<endl;
        if(i < n){
            bool bl = false;
            FOR(j,2*cur,2*i){
                FOR(k,2*i,2*n)if(at[j] != -1 && at[j] == bt[k])bl=true;
            }
            if(bl)continue;
        }
        //cerr<<cur<<" "<<i<<endl;
        if(!check(cur,i)){
            //cerr<<cur<<" "<<i<<endl;
            if(i == n){
                cout<<"No"<<endl;
                return 0;
            }
        }else{
            cur = i;
        }
    }
    cout<<"Yes"<<endl;
}