#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

struct W {
    int to;
    LL w1;
    LL w2;
};

int n,hub;
vector<vector<W>> g;

bool is_hub(){
    REP(i,n){
        if(g[i].size()==n-1){
            hub=i;
            return true;
        }
    }
    return false;
}

bool table[100000],table_to[100000];

bool hub_solve(){
    vector<int> v,v_to;
    bool bl_pre=false,bl=false;
    REP(i,n){
        table[i]=false;
        table_to[i]=false;
    }
    cerr<<"dbg"<<endl;
    REP(i,30){
        REP(j,g[hub].size()){
            bool flag = (g[hub][j].w1>>i)&1;
            int to = g[hub][j].to;
            if(bl){
                if(table[to] != flag)return false;
            }else{
                bl_pre=true;
                if(flag)table[to] = true;
            }
        }
        if(bl_pre)bl=true;
    }
    cerr<<"dbg"<<endl;

    bl_pre=false;
    bl = false;
    REP(i,30){
        REP(j,g[hub].size()){
            bool flag = (g[hub][j].w2>>i)&1;
            int to = g[hub][j].to;
            if(bl){
                if(table_to[to] != flag)return false;
            }else{
                bl_pre=true;
                if(flag)table[to] = true;
            }
        }
        if(bl_pre)bl=true;
    }

    REP(i,n){
        if(table[i]!=table_to[i])return false;
    }
    return true;
}

int type1(int ind){

    int hub1=-1,hub2=-1;
    REP(i,n-1){
        REP(j,g[i].size()){
            if((g[i][j].w1>>ind) & 1){
                if(hub1==-1){
                    hub1 = i;
                    hub2 = g[i][j].to;
                }else if(hub2==-1){
                    if(hub1!=i)return 2;
                }else {
                    if(hub1==i || hub2==i){
                        hub1=i;
                        hub2=-1;
                    }else if(hub1==g[i][j].to || hub2 == g[i][j].to){
                        hub1=g[i][j].to;
                        hub2=-1;
                    }else return 2;
                }
            }
        }
    }

    if(hub1==-1)return 0;

    REP(i,g[hub1].size()){
        if(((g[hub1][i].w1>>ind) & 1)==0)return 2;
    }
    return 1;
}

int type2(int ind){

    int hub1=-1,hub2=-1;
    REP(i,n-1){
        REP(j,g[i].size()){
            if((g[i][j].w2>>ind) & 1){
                if(hub1==-1){
                    hub1 = i;
                    hub2 = g[i][j].to;
                }else if(hub2==-1){
                    if(hub1!=i)return 2;
                }else {
                    if(hub1==i || hub2==i){
                        hub1=i;
                        hub2=-1;
                    }else if(hub1==g[i][j].to || hub2 == g[i][j].to){
                        hub1=g[i][j].to;
                        hub2=-1;
                    }else return 2;
                }
            }
        }
    }

    if(hub1==-1)return 0;
    
    REP(i,g[hub1].size()){
        if(((g[hub1][i].w2>>ind) & 1)==0)return 2;
    }
    return 1;
}

int main(){
    cin>>n;
    g.resize(n);
    REP(i,n-1){
        int u,v;
        LL w1,w2;
        cin>>u>>v>>w1>>w2;
        u--;
        v--;
        g[u].push_back(W{v,w1,w2});
        g[v].push_back(W{u,w1,w2});
    }

    if(is_hub()){
        if(hub_solve()){
            cout<<"YES"<<endl;
            return 0;
        }else{
            cout<<"NO"<<endl;
            return 0;
        }
    }

    REP(i,30){
        if(type1(i) != type2(i)){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}