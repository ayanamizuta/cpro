#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define LL long long

int n,q;
int x[200000],y[200000];

struct S{
    int idx;
    int x;
    int y;
};

vector<S> v;

int main() {
    cin>>n;
    v.resize(n);
    REP(i,n){
        int x,y;
        cin>>x>>y;
        v[i]=S{i,x,y};
    }

    auto uf = atcoder::dsu(n);
    sort(ALL(v),[](S p1,S p2){return p1.x < p2.x;});

    /*REP(i,n){
        cerr<<v[i].x<<" "<<v[i].y<<endl;
    }*/

    int idx = v[0].idx;
    int miny = v[0].y;
    FOR(i,1,n){
        if(miny < v[i].y)uf.merge(idx,v[i].idx);
        else{
            idx = v[i].idx;
            miny = v[i].y;
        }
    }

    /*REP(i,n){
        cout<<uf.size(i)<<endl;
    }*/

    sort(ALL(v),[](S p1,S p2){return p1.x > p2.x;});

    /*REP(i,n){
        cerr<<v[i].x<<" "<<v[i].y<<endl;
    }*/
    idx = v[0].idx;
    int maxy = v[0].y;
    FOR(i,1,n){
        if(maxy > v[i].y){
            uf.merge(idx,v[i].idx);
        }
        else{
            idx = v[i].idx;
            maxy = v[i].y;
        }
    }

    /*REP(i,n){
        cout<<uf.size(i)<<endl;
    }*/

    sort(ALL(v),[](S p1,S p2){return p1.y < p2.y;});
    idx = v[0].idx;
    int minx = v[0].x;
    FOR(i,1,n){
        if(minx < v[i].x)uf.merge(idx,v[i].idx);
        else{
            idx = v[i].idx;
            minx = v[i].x;
        }
    }

    /*REP(i,n){
        cout<<uf.size(i)<<endl;
    }*/

    sort(ALL(v),[](S p1,S p2){return p1.y > p2.y;});
    idx = v[0].idx;
    int maxx = v[0].x;
    FOR(i,1,n){
        if(maxx > v[i].x)uf.merge(idx,v[i].idx);
        else{
            idx = v[i].idx;
            maxx = v[i].x;
        }
    }
    
    REP(i,n){
        cout<<uf.size(i)<<endl;
    }

}