#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

struct S{
    int from;
    int to;
    int color;
};

int n,m;
vector<vector<S>> g,g_red;
bool visited[100000];
int colors[100000];

void fill_color(int v,bool fill,int color_carry,int from){
    //cerr<<v<<" "<<fill<<" "<<color_carry<<" "<<from<<endl;
    if(fill)colors[v] = color_carry;
    std::map<int, bool> m;
    for(auto s:g_red[v]){
        if(!fill)m.insert(std::make_pair(s.color,true));
        if(s.to == from)continue;
        if(color_carry == s.color)fill_color(s.to,!fill,s.color,v);
        else fill_color(s.to,true,s.color,v);
    }
    if(!fill){
        FOR(i,1,n+1){
            if(m.find(i) == m.end()){
                colors[v] = i;
                return;
            }
        }
    }
}

void exrtract_tree(int v){
    visited[v]=true;
    for(auto s:g[v]){
        if(visited[s.to])continue;
        visited[s.to]=true;
        g_red[v].push_back(s);
        g_red[s.to].push_back(S{s.to,s.from,s.color});
        exrtract_tree(s.to);
    }
}

int main(){
    cin>>n>>m;
    g.resize(n);
    g_red.resize(n);
    REP(i,m){
        int u,v,c;
        cin>>u>>v>>c;
        u--;
        v--;
        g[u].push_back({u,v,c});
        g[v].push_back({v,u,c});
    }

    exrtract_tree(0);
    /*REP(i,g_red.size()){
        REP(j,g_red[i].size()){
            cerr<<g_red[i][j].from<<" "<<g_red[i][j].to<<endl;
        }
    }*/
    fill_color(0,false,-1,-1);
    REP(i,n)cout<<colors[i]<<endl;
}